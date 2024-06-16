//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MyBooks_Unit.h"
#include "Main_Unit.h"
#include "DataModule.h"
#include <jpeg.hpp> // podrška za jpg i jpeg formate
#include <pngimage.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frxClass"
#pragma link "frxDBSet"
#pragma link "frxExportBaseDialog"
#pragma link "frxExportPDF"
#pragma resource "*.dfm"
TForm_MyBooks *Form_MyBooks;
//---------------------------------------------------------------------------

// Translate function
void translateForm(TForm* Form, String Language, const std::map<String, std::map<String, String>>& translation){
	for(int i = 0; i < Form->ComponentCount; i++) // iterate though all components on the form
		for(auto it_ComponentName = translation.begin(); it_ComponentName != translation.end(); it_ComponentName++)
			if(Form->Components[i]->Name == it_ComponentName->first) // find component by name
				for(auto it_Language = it_ComponentName->second.begin(); it_Language != it_ComponentName->second.end(); it_Language++)
					if(it_Language->first == Language) // find translation for the target language
						if(IsPublishedProp(Form->Components[i], "Caption"))
							SetPropValue(Form->Components[i], "Caption", it_Language->second);
}

__fastcall TForm_MyBooks::TForm_MyBooks(TComponent* Owner) : TForm(Owner)
{
	DBImage1->DoubleBuffered = true;

	translation["ReservationsUsersNameLabel"] = {
		{
			{ "EN", "Name:" },
			{ "HR", L"Ime:" }
		}
	};
	translation["ReservationsUsersSurnameLabel"] =	{
		{
			{"EN", "Surname:"},
			{"HR", "Prezime:"}
		}
	};
	translation["BtnSaveTUser"] =	{
		{
			{"EN", "Save"},
			{"HR", "Spremi"}
		}
	};
	translation["BtnDeleteTUser"] =	{
		{
			{"EN", "Delete"},
			{"HR", L"Izbriši"}
		}
	};
	translation["BtnEditTUser"] =	{
		{
			{"EN", "Edit"},
			{"HR", "Izmjeni"}
		}
	};
	translation["BtnReadTUser"] = {
		{
			{ "EN", "Read" },
			{ "HR", L"Ispiši" }
		}
	};
	translation["BtnLoadImageTUser"] = {
		{
			{ "EN", "Load" },
			{ "HR", L"Učitaj" }
		}
	};
	translation["BtnDeleteImageTUser"] = {
		{
			{ "EN", "Delete" },
			{ "HR", L"Izbriši" }
		}
	};
	translation["Users"] = {
		{
			{ "EN", "Users" },
			{ "HR", "Korisnici" }
		}
	};
	translation["ReservationsBooksGenreLabel"] = {
		{
			{ "EN", "Genre:" },
			{ "HR", L"Žanr:" }
		}
	};
	translation["filterCheckBox"] = {
		{
			{ "EN", "Filter" },
			{ "HR", "Filter" }
		}
	};
	translation["ReservationsBooksIDLabel"] = {
		{
			{ "EN", "Book ID:" },
			{ "HR", "ID knjige:" }
		}
	};
	translation["BtnSaveTBooks"] = {
		{
			{ "EN", "Save" },
			{ "HR", "Spremi" }
		}
	};
	translation["BtnDeleteTBooks"] = {
		{
			{ "EN", "Delete" },
			{ "HR", L"Izbriši" }
		}
	};
	translation["BtnEditTBooks"] = {
		{
			{ "EN", "Edit" },
			{ "HR", "Izmjeni" }
		}
	};
	translation["BtnReadTBooks"] = {
		{
			{ "EN", "Read" },
			{ "HR", L"Ispiši" }
		}
	};
	translation["Books"] = {
		{
			{ "EN", "Books" },
			{ "HR", "Knjige" }
		}
	};
	translation["btnSortTitle"] = {
		{
			{ "EN", "Title" },
			{ "HR", "Naslov" }
		}
	};
	translation["btnSortAuthor"] = {
		{
			{ "EN", "Author" },
			{ "HR", "Autor" }
		}
	};
	translation["btnSortGenre"] = {
		{
			{ "EN", "Genre" },
			{ "HR", L"Žanr" }
		}
	};
	translation["btnSortNumPages"] = {
		{
			{ "EN", "NumPages" },
			{ "HR", "BrStran." }
		}
	};
	translation["btnSortBookID"] = {
		{
			{ "EN", "BookID" },
			{ "HR", "ID Knjige" }
		}
	};
	translation["ReservationsReservationsFromLabel"] = {
		{
			{ "EN", "From:" },
			{ "HR", "Od:" }
		}
	};
	translation["ReservationsReservationsToLabel"] = {
		{
			{ "EN", "To:" },
			{ "HR", "Do:" }
		}
	};
	translation["BtnSaveDB"] = {
		{
			{ "EN", "Save" },
			{ "HR", "Spremi" }
		}
	};
	translation["BtnDeleteDB"] = {
		{
			{ "EN", "Delete" },
			{ "HR", L"Izbriši" }
		}
	};
	translation["BtnEditDB"] = {
		{
			{ "EN", "Edit" },
			{ "HR", "Izmjeni" }
		}
	};
	translation["BtnReadDB"] = {
		{
			{ "EN", "Read" },
			{ "HR", L"Ispiši" }
		}
	};
	translation["btnShowReport"] = {
		{
			{ "EN", "Print" },
			{ "HR", "Print" }
		}
	};
	translation["Reservations"] = {
		{
			{ "EN", "Reservations" },
			{ "HR", "Rezervacije" }
		}
	};
	translation["Language1"] = { { { "EN", "Language" }, { "HR", "Jezik" } } };
	translation["BtnWordSearch"] = { { { "EN", "Search" }, { "HR", L"Pretraži" } } };
	translation["btnShowReport"] = { { { "EN", "Print" },{ "HR", L"Ispiši" } } };
	translation["ExitBtnNav"] = { { { "EN", "Exit" }, { "HR", "Izlaz" } } };
}

//---------------------------------------------------------------------------

// Add a reservation to DB
void __fastcall TForm_MyBooks::BtnSaveDBClick(TObject *Sender)
{

	TDataSet *DataSet1 = DBGrid1->DataSource->DataSet;
	TDataSet* DataSet2 = DBGrid2->DataSource->DataSet;

    if (!DataSet1->IsEmpty() && DBGrid1->SelectedRows->Count > 0 &&
        !DataSet2->IsEmpty() && DBGrid2->SelectedRows->Count > 0)
    {
		DataSet1->GotoBookmark(DBGrid1->SelectedRows->Items[0]);
		int idUserDB = DataSet1->FieldByName("IDUseri")->AsInteger;

		DataSet2->GotoBookmark(DBGrid2->SelectedRows->Items[0]);
		int brStranicaDB = DataSet2->FieldByName("BrStranica")->AsInteger;
		int idBookDB = DataSet2->FieldByName("ID")->AsInteger;


		Data_Module->TRezervations->Append();
		Data_Module->TRezervations->FieldByName("DatumOd")->AsDateTime = EditDateFromRes->Date;
		Data_Module->TRezervations->FieldByName("DatumDo")->AsDateTime = EditDateToRes->Date;
		Data_Module->TRezervations->FieldByName("Cijena")->AsInteger = brStranicaDB * 0.08;
		Data_Module->TRezervations->FieldByName("IDKnjige")->AsString = idBookDB;
		Data_Module->TRezervations->FieldByName("IDUseri")->AsString = idUserDB;
		Data_Module->TRezervations->Post();


    } else {
        ShowMessage("No row is selected.");
    }
}

// Add a user to DB
void __fastcall TForm_MyBooks::BtnSaveTUserClick(TObject* Sender)
{
	if(!EditUsersName->Text.IsEmpty() && !EditUsersSurname->Text.IsEmpty()){
		Data_Module->TUsers->Append();
		Data_Module->TUsers->FieldByName("Ime")->AsString = EditUsersName->Text;
		Data_Module->TUsers->FieldByName("Prezime")->AsString = EditUsersSurname->Text;
		Data_Module->TUsers->Post();
	}
	EditUsersName->Text = "";
	EditUsersSurname->Text= "";
}

// Add a book to DB
void __fastcall TForm_MyBooks::BtnSaveTBooksClick(TObject* Sender)
{
	if(!EditBooksID->Text.IsEmpty()){
		// TBooks
		int element = StrToInt(EditBooksID->Text);
		for (int i = 0; i < Form_Main->ListViewKnjige->Items->Count; i++) {
			TListItem *item = Form_Main->ListViewKnjige->Items->Item[i];
			if (item->SubItems->Count > 0 && item->SubItems->Strings[3] == element) {
				// Access other items of the row here
				Data_Module->TBooks->Append();
				Data_Module->TBooks->FieldByName("Naziv")->AsString = item->Caption;
				Data_Module->TBooks->FieldByName("BrStranica")->AsString = item->SubItems->Strings[2];
				Data_Module->TBooks->FieldByName("Autor")->AsString = item->SubItems->Strings[0];
				Data_Module->TBooks->FieldByName("Zanr")->AsString = item->SubItems->Strings[1];
				Data_Module->TBooks->FieldByName("IDKnjiga")->AsString = item->SubItems->Strings[3];
				Data_Module->TBooks->Post();

				break; // If you only need the first occurrence, you can break out of the loop
			}
		}
	}
    EditBooksID->Text = "";
}

//---------------------------------------------------------------------------

// Delete a user from DB
void __fastcall TForm_MyBooks::BtnDeleteTUserClick(TObject *Sender)
{
	TDataSet *DataSet = DBGrid1->DataSource->DataSet;

	// Check if any row is selected
	if (!DataSet->IsEmpty() && DBGrid1->SelectedRows->Count > 0) {
		// Get the selected row
		DataSet->GotoBookmark(DBGrid1->SelectedRows->Items[0]);

		// Delete the selected row
		DataSet->Delete(); // This deletes the current record from the dataset

	} else {
		ShowMessage("No row is selected.");
	}
}

// Delete a book from DB
void __fastcall TForm_MyBooks::BtnDeleteTBooksClick(TObject *Sender)
{
	TDataSet *DataSet = DBGrid2->DataSource->DataSet;

	// Check if any row is selected
	if (!DataSet->IsEmpty() && DBGrid2->SelectedRows->Count > 0) {
		// Get the selected row
		DataSet->GotoBookmark(DBGrid2->SelectedRows->Items[0]);

		// Delete the selected row
		DataSet->Delete(); // This deletes the current record from the dataset

	} else {
		ShowMessage("No row is selected.");
	}
}

// Delete a reservation from DB
void __fastcall TForm_MyBooks::BtnDeleteDBClick(TObject *Sender)
{
	TDataSet *DataSet = DBGrid3->DataSource->DataSet;

	// Check if any row is selected
	if (!DataSet->IsEmpty() && DBGrid3->SelectedRows->Count > 0) {
		// Get the selected row
		DataSet->GotoBookmark(DBGrid3->SelectedRows->Items[0]);

		// Delete the selected row
		DataSet->Delete(); // This deletes the current record from the dataset

	} else {
		ShowMessage("No row is selected.");
	}
}
//---------------------------------------------------------------------------

// Edit User from DB
void __fastcall TForm_MyBooks::BtnEditTUserClick(TObject *Sender)
{
	TDataSet *DataSet = DBGrid1->DataSource->DataSet;

	// Check if any row is selected
	if (!DataSet->IsEmpty() && DBGrid1->SelectedRows->Count > 0) {
		DataSet->GotoBookmark(DBGrid1->SelectedRows->Items[0]);

        DataSet->Edit();
        DataSet->FieldByName("Ime")->AsString = EditUsersName->Text;
        DataSet->FieldByName("Prezime")->AsString = EditUsersSurname->Text;

		DataSet->Post();
	} else {
		ShowMessage("No row is selected.");
	}
	EditUsersName->Text = "";
	EditUsersSurname->Text= "";
}

// Edit Book from DB
void __fastcall TForm_MyBooks::BtnEditTBooksClick(TObject *Sender)
{
	TDataSet *DataSet = DBGrid2->DataSource->DataSet;

	// Check if any row is selected
	if (!DataSet->IsEmpty() && DBGrid2->SelectedRows->Count > 0) {
		// Get the selected row
		DataSet->GotoBookmark(DBGrid2->SelectedRows->Items[0]);

		int element = StrToInt(EditBooksID->Text);
		for (int i = 0; i < Form_Main->ListViewKnjige->Items->Count; i++) {
			TListItem *item = Form_Main->ListViewKnjige->Items->Item[i];
			if (item->SubItems->Count > 0 && item->SubItems->Strings[3] == element) {

				DataSet->Edit();
				DataSet->FieldByName("Naziv")->AsString = item->Caption;
				DataSet->FieldByName("BrStranica")->AsString = item->SubItems->Strings[2];
				DataSet->FieldByName("Autor")->AsString = item->SubItems->Strings[0];
				DataSet->FieldByName("Zanr")->AsString = item->SubItems->Strings[1];
				DataSet->FieldByName("IDKnjiga")->AsString = item->SubItems->Strings[3];
				DataSet->Post();

				break; // If you only need the first occurrence, you can break out of the loop
			}
		}
	} else {
		ShowMessage("No row is selected.");
	}
	EditBooksID->Text = "";
}

// Edit Book from DB
void __fastcall TForm_MyBooks::BtnEditDBClick(TObject *Sender)
{
    TDataSet *DataSet1 = DBGrid1->DataSource->DataSet;
	TDataSet *DataSet2 = DBGrid2->DataSource->DataSet;
	TDataSet *DataSet3 = DBGrid3->DataSource->DataSet;

    if (!DataSet1->IsEmpty() && DBGrid1->SelectedRows->Count > 0 &&
        !DataSet2->IsEmpty() && DBGrid2->SelectedRows->Count > 0)
    {
		DataSet1->GotoBookmark(DBGrid1->SelectedRows->Items[0]);
		int idUserDB = DataSet1->FieldByName("IDUseri")->AsInteger;

		DataSet2->GotoBookmark(DBGrid2->SelectedRows->Items[0]);
		int brStranicaDB = DataSet2->FieldByName("BrStranica")->AsInteger;
		int idBookDB = DataSet2->FieldByName("ID")->AsInteger;

		DataSet3->GotoBookmark(DBGrid3->SelectedRows->Items[0]);

		DataSet3->Edit();
        DataSet3->FieldByName("DatumOd")->AsString = EditDateFromRes->Date;
        DataSet3->FieldByName("DatumDo")->AsString = EditDateToRes->Date;
		DataSet3->FieldByName("Cijena")->AsInteger = brStranicaDB * 0.08;
		DataSet3->FieldByName("IDKnjige")->AsString = idBookDB;
		DataSet3->FieldByName("IDUseri")->AsString = idUserDB;
		DataSet3->Post();
	} else {
		ShowMessage("No row is selected.");
	}
}
//---------------------------------------------------------------------------


// Read out users from DB
void __fastcall TForm_MyBooks::BtnReadTUserClick(TObject *Sender)
{
	Data_Module->TUsers->First();
	for(int i = 0; i < Data_Module->TUsers->RecordCount; i++){
		// pročitaj i ispiši pojedine stupce aktivnog zapisa
		UnicodeString ime = Data_Module->TUsers->FieldByName("Ime")->AsString;
		UnicodeString prezime = Data_Module->TUsers->FieldByName("Prezime")->AsString;
		ShowMessage(IntToStr(i+1) + ") " + ime + " " + prezime);
		// postavi kursor na sljedeći zapis
		Data_Module->TUsers->Next();
	}

}

// Read out books from DB
void __fastcall TForm_MyBooks::BtnReadTBooksClick(TObject *Sender)
{
	Data_Module->TBooks->First();
	for(int i = 0; i < Data_Module->TBooks->RecordCount; i++){
		// pročitaj i ispiši pojedine stupce aktivnog zapisa
		UnicodeString  naziv = Data_Module->TBooks->FieldByName("Naziv")->AsString;
		UnicodeString  autor = Data_Module->TBooks->FieldByName("Autor")->AsString;
		UnicodeString  zanr = Data_Module->TBooks->FieldByName("Zanr")->AsString;
		UnicodeString  brStranica = Data_Module->TBooks->FieldByName("BrStranica")->AsString;
		UnicodeString  id = Data_Module->TBooks->FieldByName("IDKnjiga")->AsString;
		ShowMessage("Knjiga: " + naziv + " - " + autor + "\nŽanr: " + zanr + "\nBroj stranica: " + brStranica+ "\nID: " + id);
		// postavi kursor na sljedeći zapis
		Data_Module->TBooks->Next();
	}
}

// Read out reservations from DB
void __fastcall TForm_MyBooks::BtnReadDBClick(TObject *Sender)
{
	Data_Module->TRezervations->First();
	for(int i = 0; i < Data_Module->TRezervations->RecordCount; i++){
		// pročitaj i ispiši pojedine stupce aktivnog zapisa
		UnicodeString datumOd = Data_Module->TRezervations->FieldByName("DatumOd")->AsString;
		UnicodeString datumDo = Data_Module->TRezervations->FieldByName("DatumDo")->AsString;
		int cijena = Data_Module->TRezervations->FieldByName("Cijena")->AsInteger;
		UnicodeString idKnjige = Data_Module->TRezervations->FieldByName("IDKnjige")->AsString;
		UnicodeString idUseri = Data_Module->TRezervations->FieldByName("IDUseri")->AsString;
		ShowMessage("Razdoblje rezervacije: " + datumOd + " - " + datumDo + "\nCijena: " + IntToStr(cijena) + "€\nID Knjiga: " + idKnjige + "\nID User: " + idUseri);
		// postavi kursor na sljedeći zapis
		Data_Module->TRezervations->Next();
	}
}
//---------------------------------------------------------------------------

// Save and delete blob image buttons
void __fastcall TForm_MyBooks::BtnLoadImageTUserClick(TObject* Sender)
{
    if(OpenDialog1->Execute()){
		Data_Module->TUsers->Edit();
		static_cast<TBlobField*>(Data_Module->TUsers->FieldByName("Slika"))->LoadFromFile(OpenDialog1->FileName);
		Data_Module->TUsers->Post();
	}
}

void __fastcall TForm_MyBooks::BtnDeleteImageTUserClick(TObject *Sender)
{
    Data_Module->TUsers->Edit();
	Data_Module->TUsers->FieldByName("Slika")->Clear();
	Data_Module->TUsers->Post();
}
//---------------------------------------------------------------------------

// Export to PDF button
void __fastcall TForm_MyBooks::btnShowReportClick(TObject *Sender)
{
    frxReport1->ShowReport();
}
//---------------------------------------------------------------------------

// Sort buttons

void __fastcall TForm_MyBooks::btnSortGenreClick(TObject *Sender)
{
	Data_Module->TBooks->IndexFieldNames = "Zanr";
}


void __fastcall TForm_MyBooks::btnSortAuthorClick(TObject *Sender)
{
	Data_Module->TBooks->IndexFieldNames = "Autor";
}


void __fastcall TForm_MyBooks::btnSortNumPagesClick(TObject *Sender)
{
	Data_Module->TBooks->IndexFieldNames = "BrStranica";
}


void __fastcall TForm_MyBooks::btnSortBookIDClick(TObject *Sender)
{
	Data_Module->TBooks->IndexFieldNames = "IDKnjiga";
}


void __fastcall TForm_MyBooks::btnSortTitleClick(TObject *Sender)
{
	Data_Module->TBooks->IndexFieldNames = "Naziv";
}


void __fastcall TForm_MyBooks::btnSortIDClick(TObject *Sender)
{
	Data_Module->TBooks->IndexFieldNames = "ID";
}
//---------------------------------------------------------------------------

// Filter by genre

void __fastcall TForm_MyBooks::filterCheckBoxClick(TObject* Sender)
{
	if(filterCheckBox->Checked)
		Data_Module->TBooks->Filter = "Zanr = " + QuotedStr(filterTextBox->Text);
	Data_Module->TBooks->Filtered = filterCheckBox->Checked;

}
//---------------------------------------------------------------------------

// Translate clicks

void __fastcall TForm_MyBooks::Eng1Click(TObject *Sender)
{
    translateForm(this, "EN", translation);
	Form_Main->currentLanguage = "EN";
	Form_Main->ENClick(Sender);
}


void __fastcall TForm_MyBooks::Hrv1Click(TObject *Sender)
{
    translateForm(this, "HR", translation);
	Form_Main->currentLanguage = "HR";
    Form_Main->HRClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm_MyBooks::FormShow(TObject *Sender)
{
    if (Form_Main->currentLanguage == "HR") {
		translateForm(this, "HR", translation);
	} else{
		translateForm(this, "EN", translation);
	}
}
//---------------------------------------------------------------------------

// Api dictionary
void __fastcall TForm_MyBooks::BtnWordSearchClick(TObject *Sender)
{
	UnicodeString baseUrl = "https://api.dictionaryapi.dev/api/v2/entries/en/";
    MemoWordSearch->Clear();
    // Get the word from the TEdit component
    UnicodeString wordToLookup = EWordSearch->Text.Trim();
    // Concatenate the base URL with the user-entered word
	UnicodeString fullUrl = baseUrl + wordToLookup;
    // Set the constructed URL as the base URL
	RESTClient1->BaseURL = fullUrl;
    // Execute the request
	RESTRequest1->Execute();
	MemoWordSearch->Lines->Add(wordToLookup);
	MemoWordSearch->Lines->Add("--------------------------------------------------------");
    // Parse the JSON response
    UnicodeString jsonResponse = RESTRequest1->Response->Content;
    TJSONArray* jsonArray =
        static_cast<TJSONArray*>(TJSONObject::ParseJSONValue(jsonResponse));

    // Check if jsonArray is valid and contains at least one element
    if (jsonArray != nullptr && jsonArray->Count > 0) {
        TJSONObject *jsonObject = static_cast<TJSONObject*>(jsonArray->Items[0]);
        // Extract the "meanings" array
        TJSONArray *meaningsArray = static_cast<TJSONArray*>(jsonObject->FindValue("meanings"));
        // Iterate through the meanings array and print definitions
        for (int i = 0; i < meaningsArray->Count; ++i) {
            TJSONObject *meaningObject = static_cast<TJSONObject*>(meaningsArray->Items[i]);
            // Extract the "definitions" array
            TJSONArray *definitionsArray = static_cast<TJSONArray*>(meaningObject->FindValue("definitions"));
            // Print up to 5 definitions
            for (int j = 0; j < Min(definitionsArray->Count, 5); ++j) {
                TJSONObject *definitionObject = static_cast<TJSONObject*>(definitionsArray->Items[j]);
                UnicodeString definition = definitionObject->GetValue("definition")->Value();
				MemoWordSearch->Lines->Add("Definition: " + definition + "\n");
            }
        }
	}
    // Clean up
    delete jsonArray;
}
//---------------------------------------------------------------------------

// Exit nav
void __fastcall TForm_MyBooks::ExitBtnNavClick(TObject* Sender) {
	this->Close();
}
//---------------------------------------------------------------------------





