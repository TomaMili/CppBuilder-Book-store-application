//---------------------------------------------------------------------------

#include <vcl.h>
#include <registry.hpp>
#include <DateUtils.hpp>
#include <System.JSON.hpp>
#include <SysUtils.hpp>
#include <System.SysUtils.hpp>
#include <REST.Client.hpp>
#include <REST.Types.hpp>
#pragma hdrstop

#include "Main_Unit.h"
#include "Login_Unit.h"
#include "PopisKnjiga.h"
#include "BookInput_Unit.h"
#include "UnitLib.h"

#include <map>
#include <iostream>
#include <string>
#include <memory>
#include <random>
#include <ctime>
#include <thread>
#include <chrono>
#include <queue>
#include <future>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <windows.h>
#include <wincrypt.h>
#include <jpeg.hpp>

#include <mutex>
#include <condition_variable>
#include <functional>
#include <algorithm>
#include "MyBooks_Unit.h"
#include "DataModule.h"
#include "TCP_Unit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frxClass"
#pragma link "frxDBSet"
#pragma link "frxExportBaseDialog"
#pragma link "frxExportPDF"
#pragma link "IdHTTP"
#pragma resource "*.dfm"
TForm_Main *Form_Main;

using namespace std;
//---------------------------------------------------------------------------

extern "C" float __declspec(dllexport) __stdcall calcPriceByPage(int NumPages);
extern "C" float __declspec(dllexport) __stdcall calcArPrice(float arPrice);

double customRound(double value, int decimalPlaces) {
	double scale = std::pow(10.0, decimalPlaces);
	return std::round(value * scale) / scale;
}

//---------------------------------------------------------------------------

// My file format classes (6)
class MojFormat{
public:
	wchar_t _naziv[10];
	float _inacica;
	MojFormat(){
		wcsncpy(_naziv, L"MojFormat", 10);
	_inacica = 1.0;
	}
};


class Receipt{
public:
  wchar_t _operatorName[25], _date[25],_price[30], _receiptNum[30], _time[30],
			 _libraryName[30];
  Receipt() {}
  Receipt(const wchar_t* operatorName, const wchar_t* date, const wchar_t* receiptNum,const wchar_t* price, const wchar_t* time, const wchar_t* libraryName)
  {
	  wcsncpy(_operatorName, operatorName, 25);
	  wcsncpy(_date, date, 25);
	  wcsncpy(_price, price, 30);
	  wcsncpy(_receiptNum, receiptNum, 30);
	  wcsncpy(_time, time, 30);
	  wcsncpy(_libraryName, libraryName, 30);
  }
};
std::vector<Receipt> receipts;
//---------------------------------------------------------------------------

// Translate functions for ListView columns (3)
void translateListViewsEN()
{
	// ListViewKnjige
    Form_Main->ListViewKnjige->Column[0]->Caption = "Title";
    Form_Main->ListViewKnjige->Column[1]->Caption = "Author";
	Form_Main->ListViewKnjige->Column[2]->Caption = "Genre";
	Form_Main->ListViewKnjige->Column[3]->Caption = "Number of pages";

	// ListViewGenres
	Form_Main->ListViewGenres->Column[0]->Caption = "Genre";
	Form_Main->ListViewGenres->Column[1]->Caption = "Num";

	// ListViewCart
	Form_Main->ListViewCart->Column[0]->Caption = "BookID";
	Form_Main->ListViewCart->Column[1]->Caption = "Title";
	Form_Main->ListViewCart->Column[2]->Caption = "Price";

	// ListViewFavKnjige
	Form_Main->ListViewFavKnjige->Column[0]->Caption = "Title";
	Form_Main->ListViewFavKnjige->Column[1]->Caption = "Author";
	Form_Main->ListViewFavKnjige->Column[2]->Caption = "Genre";
	Form_Main->ListViewFavKnjige->Column[3]->Caption = "Number of pages";
	Form_Main->ListViewFavKnjige->Column[4]->Caption = "Date";
	Form_Main->ListViewFavKnjige->Column[5]->Caption = "Username";
}

void translateListViewsHR()
{
    // ListViewKnjige
    Form_Main->ListViewKnjige->Column[0]->Caption = "Naslov";
    Form_Main->ListViewKnjige->Column[1]->Caption = "Autor";
	Form_Main->ListViewKnjige->Column[2]->Caption = "Žanr";
	Form_Main->ListViewKnjige->Column[3]->Caption = "Broj stranica";

	// ListViewGenres
	Form_Main->ListViewGenres->Column[0]->Caption = "Žanr";
	Form_Main->ListViewGenres->Column[1]->Caption = "Br";

    // ListViewCart
	Form_Main->ListViewCart->Column[0]->Caption = "ID Knjige";
	Form_Main->ListViewCart->Column[1]->Caption = "Naslov";
	Form_Main->ListViewCart->Column[2]->Caption = "Cijena";

    // ListViewFavKnjige
	Form_Main->ListViewFavKnjige->Column[0]->Caption = "Naslov";
	Form_Main->ListViewFavKnjige->Column[1]->Caption = "Autor";
	Form_Main->ListViewFavKnjige->Column[2]->Caption = "Žanr";
	Form_Main->ListViewFavKnjige->Column[3]->Caption = "Broj stranica";
	Form_Main->ListViewFavKnjige->Column[4]->Caption = "Datum";
	Form_Main->ListViewFavKnjige->Column[5]->Caption = "Korisnik";
}
//---------------------------------------------------------------------------

// Translate function (3)
void translateForm(TForm* Form, String Language,
    const std::map<String, std::map<String, String> > &translation)
{
    for(int i = 0; i < Form->ComponentCount; i++) // iterate though all components on the form
		for(auto it_ComponentName = translation.begin(); it_ComponentName != translation.end(); it_ComponentName++)
			if(Form->Components[i]->Name == it_ComponentName->first) // find component by name
				for(auto it_Language = it_ComponentName->second.begin(); it_Language != it_ComponentName->second.end(); it_Language++)
					if(it_Language->first == Language) // find translation for the target language
						if(IsPublishedProp(Form->Components[i], "Caption"))
							SetPropValue(Form->Components[i], "Caption", it_Language->second);
}

//---------------------------------------------------------------------------

__fastcall TForm_Main::TForm_Main(TComponent* Owner) : TForm(Owner)
{
	loggedIn = false;

	translation["GroupBoxKnjige"] =	{
		{
			{"EN", "All books"},
			{"HR", "Sve knjige"}
		}
	};
	translation["GroupBox1"] =	{
		{
			{"EN", "Returned books"},
			{"HR", L"Vraćene knjige"}
		}
	};
	translation["LanguageMenuClick"] =	{
		{
			{"EN", "Language"},
			{"HR", "Jezik"}
		}
	};
	translation["BtnLoadBooks"] =	{
		{
			{"EN", "Load"},
			{"HR", L"Učitaj"}
		}
	};
	translation["LoginMenuClick"] = {
		{
			{ "EN", "Login" },
			{ "HR", "Prijava" }
		}
	};
	translation["BtnValidateReceipt"] = {
		{
			{ "EN", "Validate receipt" },
			{ "HR", L"Provjeri račun" }
		}
	};
	translation["BtnDownloadTerms"] = {
		{
			{ "EN", "Terms of services" },
			{ "HR", L"Uvjeti korištenja" }
		}
	};
	translation["Reservations1"] = {
		{
			{ "EN", "Reservations" },
			{ "HR", "Rezervacije" }
		}
	};
	translation["CheckoutPriceLabel"] =	{
		{
			{"EN", "Price:"},
			{"HR", "Cijena:"}
		}
	};
	translation["CheckoutPDVLabel"] = {
		{
			{ "EN", "PDV rate:" },
			{ "HR", "Iznos PDV-a:" }
		}
	};
	translation["CheckoutTotalPriceLabel"] =	{
		{
			{"EN", "Total price:"},
			{"HR", "Ukupna cijena:"}
		}
	};
	translation["CheckoutIDLabel"] = {
		{
			{ "EN", "ID:" },
			{ "HR", "ID:" }
		}
	};
	translation["CheckoutPaidLabel"] =	{
		{
			{"EN", "Paid:"},
			{"HR", L"Plaćeno:"}
		}
	};
	translation["AddBooksToBasketBtn"] = {
		{
			{ "EN", "Add" },
			{ "HR", "Dodaj" }
		}
	};
	translation["PrintBooksFromBasketBtn"] =	{
		{
			{"EN", "Print"},
			{"HR", "Ispis"}
		}
	};
	translation["Checkout"] = {
		{
			{ "EN", "Checkout" },
			{ "HR", "Naplata" }
		}
	};
	translation["BtnDeleteBooks"] = {
		{
			{ "EN", "Delete" },
			{ "HR", "Ukloni" }
		}
	};
	translation["BtnUpdateBooks"] = {
		{
			{ "EN", "Update" },
			{ "HR", L"Ažuriraj" }
		}
	};
	translation["BtnAddBooks"] = {
		{
			{ "EN", "Add" },
			{ "HR", "Dodaj" }
		}
	};
	translation["BtnLoadFavBooks"] = {
		{
			{ "EN", "Load" },
			{ "HR", L"Učitaj" }
		}
	};
	translation["BtnDeleteFavBooks"] = {
		{
			{ "EN", "Delete" },
			{ "HR", "Ukloni" }
		}
	};
	translation["BtnAddFavBooks"] = {
		{
			{ "EN", "Add" },
			{ "HR", "Dodaj" }
		}
	};
	translation["BtnUpdateFavBooks"] = {
		{
			{ "EN", "Update" },
			{ "HR", L"Ažuriraj" }
		}
	};
	translation["btnSaveReceiptMFT"] = {
		{
			{ "EN", "Save" },
			{ "HR", "Spremi" }
		}
	};
	translation["btnReadReceiptMFT"] = {
		{
			{ "EN", "Read" },
			{ "HR", L"Ispiši" }
		}
	};
	translation["GroupBox3"] = {
		{
			{ "EN", "Receipt" },
			{ "HR", L"Račun" }
		}
	};
	currentLanguage = "EN";
	translateListViewsEN();

//---------------------------------------------------------------------------

	// Loading DLL resource, logo image (30)
	HINSTANCE ResourceDll;
	if((ResourceDll = LoadLibrary(L"ProjectDLL.dll"))==NULL) {
		ShowMessage("Cannot load ProjectDLL.dll!");
		return;
	}
	TResourceStream* rs = new TResourceStream((int)ResourceDll, "LOGO_PNG", RT_RCDATA);
    Image2->Picture->LoadFromStream(rs);
    delete rs;
	FreeLibrary(ResourceDll);
//---------------------------------------------------------------------------
}

// Save windows properties to INI file (4)
void __fastcall TForm_Main::FormClose(TObject *Sender, TCloseAction &Action){
	TIniFile *ini;
	ini = new TIniFile(GetCurrentDir() + "\\settings.ini");
	ini->WriteString("Main Window", "Window position", Caption);
	ini->WriteInteger("Main Window", "Left", Left);
	ini->WriteInteger("Main Window", "Top", Top);
	ini->WriteInteger("Main Window", "Width", Width);
	ini->WriteInteger("Main Window", "Height", Height);
	delete ini;
}
//---------------------------------------------------------------------------

// Load windows properties from INI file (4)
void __fastcall TForm_Main::FormCreate(TObject *Sender){
    TIniFile *ini;
	ini = new TIniFile(GetCurrentDir() + "\\settings.ini");
	Left = ini->ReadInteger("Main Window", "Left", 0);
	Top = ini->ReadInteger("Main Window", "Top", 0);
	Width = ini->ReadInteger("Main Window", "Width", 500);
	Height = ini->ReadInteger("Main Window", "Height", 300);
	delete ini;


}
//---------------------------------------------------------------------------

// Login button handle
void __fastcall TForm_Main::LoginMenuClickClick(TObject *Sender)
{
	Form_Login->ShowModal();
    formattedUser = UpperCase(currentUser.SubString(1, 1)) +
						   LowerCase(currentUser.SubString(2, MaxInt));
	if(loggedIn){
		if(currentLanguage == "EN"){
			Label1->Caption = "Welcome " + formattedUser;
		}else{
			Label1->Caption = "Dobrodošli " + formattedUser;
		}
	}

}
//---------------------------------------------------------------------------

// Change language to EN menu click
void __fastcall TForm_Main::ENClick(TObject *Sender)
{
	translateForm(this, "EN", translation);
	translateListViewsEN();
	currentLanguage = "EN";
	if(loggedIn)
		Label1->Caption = "Welcome " + formattedUser;

}

// Change language to HR menu click
void __fastcall TForm_Main::HRClick(TObject *Sender)
{
	translateForm(this, "HR", translation);
	translateListViewsHR();
	currentLanguage = "HR";
	if(loggedIn)
		Label1->Caption = "Dobrodošli " + formattedUser;

}
//---------------------------------------------------------------------------


// Load books from XML file to ListView (5)
void __fastcall TForm_Main::BtnLoadBooksClick(TObject *Sender)
{
    if(!loggedIn){
		ShowMessage("You're not logged in!");
		return;
	}

	_di_IXMLpopisType Popis_Knjiga = Getpopis(PopisKnjiga);
	ListViewKnjige->Items->Clear();

    // Populate ListViewKnjige with book details from XML
    for (int i = 0; i < Popis_Knjiga->Count; i++) {
        TListItem* bookItem = ListViewKnjige->Items->Add();
        bookItem->Caption = Popis_Knjiga->knjiga[i]->naziv;
        bookItem->SubItems->Add(Popis_Knjiga->knjiga[i]->autor);
        bookItem->SubItems->Add(Popis_Knjiga->knjiga[i]->zanr);
        bookItem->SubItems->Add(IntToStr(Popis_Knjiga->knjiga[i]->stranice));
        bookItem->SubItems->Add(Popis_Knjiga->knjiga[i]->id);
	}

    idLastBook = Popis_Knjiga->knjiga[Popis_Knjiga->Count - 1]->id;
	int threadCount = 2; // number of threads

	std::vector<std::thread> t(threadCount);
    int start, assignedElements = 0, elementsCount = 0;

	// Don't create unnecessary threads
    if (Popis_Knjiga->Count < threadCount)
		threadCount = Popis_Knjiga->Count;

	std::map<String, int> genreCount; // Map to store genre counts

	TCriticalSection* cs = new TCriticalSection();

    for (int i = 0; i < threadCount; i++) {
        // Calculate the number of vector elements for each thread...
        assignedElements += elementsCount;
        start = assignedElements;
        elementsCount = Popis_Knjiga->Count / threadCount + (i < Popis_Knjiga->Count % threadCount);
        int end = start + elementsCount - 1;
        // Each thread searches its part of the vector: [start, end]
        t[i] = std::thread([&, start, end, cs]() {
			for (int j = start; j <= end; j++) {
                // Increment the count for each genre
                String genre = Popis_Knjiga->knjiga[j]->zanr;
                cs->Enter();
                try {
                    genreCount[genre]++;
                } __finally {
                    cs->Leave();
                }
            }
        });
	}

    // Wait for all threads to finish
    for (int i = 0; i < threadCount; i++) {
        t[i].join();
    }

    // Convert the map to a vector of pairs
	std::vector<std::pair<String, int>> genreVector(genreCount.begin(), genreCount.end());

    // Sort the vector by count in descending order
    std::sort(genreVector.begin(), genreVector.end(),
        [](const std::pair<String, int>& a, const std::pair<String, int>& b) {
            return a.second > b.second; // Descending order
		});

    // Use TThread::Queue to update the UI in the main thread
	TThread::Queue(NULL, [=]() {
        // Clear the ListView before updating
		ListViewGenres->Items->Clear();

        // Display genre counts in the ListView in sorted order
        for (const auto& [genre, count] : genreVector) {
            TListItem* item = ListViewGenres->Items->Add();
            item->Caption = genre;
            item->SubItems->Add(IntToStr(count));
		}

		// Clear and re-populate ListViewKnjige with book details from XML
        ListViewKnjige->Items->Clear();
        for (int i = 0; i < Popis_Knjiga->Count; i++) {
            TListItem* bookItem = ListViewKnjige->Items->Add();
            bookItem->Caption = Popis_Knjiga->knjiga[i]->naziv;
            bookItem->SubItems->Add(Popis_Knjiga->knjiga[i]->autor);
            bookItem->SubItems->Add(Popis_Knjiga->knjiga[i]->zanr);
            bookItem->SubItems->Add(IntToStr(Popis_Knjiga->knjiga[i]->stranice));
            bookItem->SubItems->Add(Popis_Knjiga->knjiga[i]->id);
        }
    });
    delete cs; // Clean up
}


// Add books from Form_BookInput to XML file (5)
void __fastcall TForm_Main::BtnAddBooksClick(TObject* Sender)
{
    if(!loggedIn){
		ShowMessage("You're not logged in!");
		return;
	}

	Form_BookInput->ShowModal();

	_di_IXMLpopisType Popis_Knjiga = Getpopis(PopisKnjiga);
	_di_IXMLknjigaType knjiga = Popis_Knjiga->Add();

	knjiga->id = idLastBook + 1;
	knjiga->naziv = title;
	knjiga->autor = author;
	knjiga->zanr = genre;
	knjiga->stranice = brStranica;

	PopisKnjiga->SaveToFile(PopisKnjiga->FileName);
	BtnLoadBooksClick(Sender);
}

// Delete books from XML file (5)
void __fastcall TForm_Main::BtnDeleteBooksClick(TObject* Sender)
{
    if(!loggedIn){
		ShowMessage("You're not logged in!");
		return;
	}

	if(ListViewKnjige->ItemIndex == -1)
		return;

	_di_IXMLpopisType Popis_Knjiga = Getpopis(PopisKnjiga);

	Popis_Knjiga->Delete(ListViewKnjige->ItemIndex);
	PopisKnjiga->SaveToFile(PopisKnjiga->FileName);

	BtnLoadBooksClick(Sender);
}

// Update books from XML file (5)
void __fastcall TForm_Main::BtnUpdateBooksClick(TObject *Sender)
{
    if(!loggedIn){
		ShowMessage("You're not logged in!");
		return;
	}

	if(ListViewKnjige->ItemIndex == -1)
		return;


    _di_IXMLpopisType Popis_Knjiga = Getpopis(PopisKnjiga);
	_di_IXMLknjigaType knjiga = Popis_Knjiga->knjiga[ListViewKnjige->ItemIndex];

	Form_BookInput->TitleInput->Text = knjiga->naziv;
	Form_BookInput->AuthorInput->Text = knjiga->autor;
	Form_BookInput->PageNumberInput->Text = knjiga->stranice;
	Form_BookInput->GenreInput->Text = knjiga->zanr;

    Form_BookInput->ShowModal();

	knjiga->naziv = title;
	knjiga->autor = author;
	knjiga->zanr = genre;
	knjiga->stranice = brStranica;

	PopisKnjiga->SaveToFile(PopisKnjiga->FileName);
	BtnLoadBooksClick(Sender);

}


// Load returned books from JSON file to ListView (5)
void __fastcall TForm_Main::BtnLoadFavBooksClick(TObject *Sender)
{
	if(!loggedIn){
		ShowMessage("You're not logged in!");
	} else {
		std::unique_ptr<TStringStream> jsonStream(new TStringStream);
		jsonStream->LoadFromFile("PopisOmiljenihKnjiga.json");
		UnicodeString jsonDoc = jsonStream->DataString;

		// Dohvati cijeli JSON
		TJSONObject* FavBooks = (TJSONObject*)TJSONObject::ParseJSONValue(jsonDoc);

		// Dohvati niz "knjige" unutar JSON dokumenta
		TJSONArray* Knjige = (TJSONArray*)TJSONObject::ParseJSONValue(FavBooks->GetValue("knjige")->ToString());

		ListViewFavKnjige->Items->Clear();
		for (int i = 0; i < Knjige->Count; i++) {
			UnicodeString bookUser = Knjige->Items[i]->GetValue<UnicodeString>("user");
			if (currentUser == bookUser) {
				TListItem *item = ListViewFavKnjige->Items->Add();
				item->Caption = Knjige->Items[i]->GetValue<UnicodeString>("naziv");
				item->SubItems->Add(Knjige->Items[i]->GetValue<UnicodeString>("autor"));
				item->SubItems->Add(Knjige->Items[i]->GetValue<UnicodeString>("zanr"));
				item->SubItems->Add(IntToStr(Knjige->Items[i]->GetValue<int>("stranice")));
				item->SubItems->Add(Knjige->Items[i]->GetValue<UnicodeString>("datum"));
				item->SubItems->Add(Knjige->Items[i]->GetValue<UnicodeString>("user"));
				item->SubItems->Add(Knjige->Items[i]->GetValue<UnicodeString>("id"));
			}
		}
	}
}
// Add returned books to JSON file (5)
void __fastcall TForm_Main::BtnAddFavBooksClick(TObject* Sender)
{
	if (!loggedIn) {
		ShowMessage("You're not logged in!");
	} else {
		if (ListViewKnjige->Selected) {
			TDateTime currentDate = Now();

			// Load existing data from JSON file
			std::unique_ptr<TStringStream> jsonStream(new TStringStream);
			jsonStream->LoadFromFile("PopisOmiljenihKnjiga.json");
			UnicodeString jsonDoc = jsonStream->DataString;

			// Parse existing JSON data
			TJSONObject* FavBooks = (TJSONObject*)TJSONObject::ParseJSONValue(jsonDoc);
            TJSONArray* Knjige = (TJSONArray*)TJSONObject::ParseJSONValue(FavBooks->GetValue("knjige")->ToString());


            // Add new selected book
            TJSONObject* newBook = new TJSONObject();
			newBook->AddPair("naziv", ListViewKnjige->Selected->Caption);
            newBook->AddPair(
                "autor", ListViewKnjige->Selected->SubItems->Strings[0]);
            newBook->AddPair(
				"zanr", ListViewKnjige->Selected->SubItems->Strings[1]);
			newBook->AddPair(
                "stranice", ListViewKnjige->Selected->SubItems->Strings[2]);
            newBook->AddPair("datum", DateToStr(currentDate));
			newBook->AddPair("user", currentUser);
			newBook->AddPair("id", ListViewKnjige->Selected->SubItems->Strings[3]);
            Knjige->AddElement(newBook);

			// Update JSON object with the new array of books
            FavBooks->RemovePair("knjige");
            FavBooks->AddPair("knjige", Knjige);

			// Convert updated JSON data back to string
            UnicodeString updatedJsonDoc = FavBooks->ToString();

            // Save updated JSON data to file
			std::unique_ptr<TStringStream> ss(new TStringStream);
            ss->WriteString(updatedJsonDoc);
			ss->SaveToFile("PopisOmiljenihKnjiga.json");

			BtnLoadFavBooksClick(Sender);
        }
    }
}

// Update returned books from JSON file (5)// Delete returned books from JSON file (5)
void __fastcall TForm_Main::BtnDeleteFavBooksClick(TObject *Sender)
{
	if(!loggedIn){
		ShowMessage("You're not logged in!");
		return;
	}

	if (ListViewFavKnjige->Selected) {

    // Get the ID of the selected book
	UnicodeString selectedBookId = ListViewFavKnjige->Selected->SubItems->Strings[5]; // Assuming the book ID is in the fifth column (index 4)

	// Load existing data from JSON file
    std::unique_ptr<TStringStream> jsonStream(new TStringStream);
    jsonStream->LoadFromFile("PopisOmiljenihKnjiga.json");
    UnicodeString jsonDoc = jsonStream->DataString;

    // Parse existing JSON data
    TJSONObject* FavBooks = (TJSONObject*)TJSONObject::ParseJSONValue(jsonDoc);
    TJSONArray* Knjige = (TJSONArray*)TJSONObject::ParseJSONValue(FavBooks->GetValue("knjige")->ToString());

    // Find the index of the book with the selected ID in the JSON array
    int selectedIndex = -1;
    for (int i = 0; i < Knjige->Count; ++i) {
		TJSONObject* book = (TJSONObject*)Knjige->Items[i];
        UnicodeString bookId = book->GetValue("id")->Value(); // Assuming the key for the book ID is "id"
        if (bookId == selectedBookId) {
            selectedIndex = i;
			break;
        }
	}

	if (selectedIndex != -1) {
        // Remove the corresponding entry from the JSON array
        Knjige->Remove(selectedIndex);

		// Update JSON object with the modified array of books
        FavBooks->RemovePair("knjige");
        FavBooks->AddPair("knjige", Knjige);

		// Convert updated JSON data back to string
        UnicodeString updatedJsonDoc = FavBooks->ToString();

        // Save updated JSON data to file
		std::unique_ptr<TStringStream> ss(new TStringStream);
        ss->WriteString(updatedJsonDoc);
        ss->SaveToFile("PopisOmiljenihKnjiga.json");

		// Remove the selected book from the ListView
		delete ListViewFavKnjige->Items->Item[ListViewFavKnjige->Selected->Index];

        BtnLoadFavBooksClick(Sender);
    } else {
        ShowMessage("Failed to find the selected book in the JSON data.");
	}
} else {
    ShowMessage("Please select a book to delete.");
}

}
//---------------------------------------------------------------------------

// Count of articles ordered
void addBook(std::map<int, int>&bookCountMap, int bookID) {
	bookCountMap[bookID]++;
}

// Add books to the basket button
void __fastcall TForm_Main::AddBooksToBasketBtnClick(TObject *Sender)
{
	if(!loggedIn){
		ShowMessage("You're not logged in!");
		return;
	}
    int BookID = StrToInt(artiklKnjigaIDEdit->Text);
	int NumPages;
	float articlePrice;
	float PDV = 1.05;
	UnicodeString bookTitle;



	for (int i = 0; i < ListViewKnjige->Items->Count; i++) {
		TListItem *item = ListViewKnjige->Items->Item[i];
		if (item->SubItems->Count > 0 && item->SubItems->Strings[3] == BookID) {
			bookTitle = item->Caption;
			NumPages = StrToInt(item->SubItems->Strings[2]);
			addBook(bookCount, BookID);
			break;
		}
	}


	// Functions from static and dynamic libraries

	articlePrice = calcPriceByPage(NumPages);

	fullPrice = fullPrice + articlePrice * PDV;

	LabelPrice->Caption = FloatToStr((ceil(articlePrice * PDV * 100.0) / 100.0))  + " €";
	LabelPDV->Caption = "5%";
	LabelFullPrice->Caption = FloatToStr(customRound(calcArPrice(fullPrice),2)) + " €";

	TListItem *item = ListViewCart->Items->Add();
	item->Caption = BookID;
	item->SubItems->Add(bookTitle);
	item->SubItems->Add(calcArPrice(articlePrice));
}



//--------------------------------------------------------------------------

// Digital signature (26)

bool VerifySignature(const std::string &data, const std::vector<BYTE> &signature, const std::vector<BYTE> &publicKey) {
    HCRYPTPROV hProv;
    HCRYPTKEY hKey;
    HCRYPTHASH hHash;
    if (!CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT)) {
        return false;
    }
    if (!CryptImportKey(hProv, &publicKey[0], publicKey.size(), 0, 0, &hKey)) {
        CryptReleaseContext(hProv, 0);
        return false;
    }
    if (!CryptCreateHash(hProv, CALG_SHA1, 0, 0, &hHash)) {
        CryptDestroyKey(hKey);
        CryptReleaseContext(hProv, 0);
        return false;
    }
    if (!CryptHashData(hHash, reinterpret_cast<const BYTE*>(data.c_str()), data.size(), 0)) {
        CryptDestroyHash(hHash);
        CryptDestroyKey(hKey);
        CryptReleaseContext(hProv, 0);
        return false;
    }
    bool result = CryptVerifySignature(hHash, &signature[0], signature.size(), hKey, NULL, 0);
    CryptDestroyHash(hHash);
    CryptDestroyKey(hKey);
    CryptReleaseContext(hProv, 0);
    return result;
}


std::map<int, std::vector<BYTE>> publicKeyStore;
std::map<int, std::vector<BYTE>> signatureStore;

std::string UnicodeStringToString(const UnicodeString &us) {
    return std::string(AnsiString(us).c_str());
}

std::string MemoToString(TMemo *Memo) {
    std::string result;
    for (int i = 0; i < Memo->Lines->Count; i++) {
        result += UnicodeStringToString(Memo->Lines->Strings[i]);
        if (i < Memo->Lines->Count - 1) {
            result += "\n";
        }
    }
    return result;
}

bool GenerateKeyPair(HCRYPTPROV &hProv, HCRYPTKEY &hKey) {
    if (!CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_FULL, CRYPT_NEWKEYSET | CRYPT_VERIFYCONTEXT)) {
        return false;
    }
    if (!CryptGenKey(hProv, AT_SIGNATURE, 0x08000000 | CRYPT_EXPORTABLE, &hKey)) {
        CryptReleaseContext(hProv, 0);
        return false;
    }
    return true;
}

bool SignData(const std::string &data, std::vector<BYTE> &signature, HCRYPTPROV hProv, HCRYPTKEY hKey) {
    HCRYPTHASH hHash;
    if (!CryptCreateHash(hProv, CALG_SHA1, 0, 0, &hHash)) {
        return false;
    }
    if (!CryptHashData(hHash, reinterpret_cast<const BYTE*>(data.c_str()), data.size(), 0)) {
        CryptDestroyHash(hHash);
        return false;
    }
    DWORD dwSigLen;
    if (!CryptSignHash(hHash, AT_SIGNATURE, NULL, 0, NULL, &dwSigLen)) {
        CryptDestroyHash(hHash);
        return false;
    }
    signature.resize(dwSigLen);
    if (!CryptSignHash(hHash, AT_SIGNATURE, NULL, 0, &signature[0], &dwSigLen)) {
        CryptDestroyHash(hHash);
        return false;
    }
    CryptDestroyHash(hHash);
    return true;
}

bool ExportPublicKey(HCRYPTPROV hProv, HCRYPTKEY hKey, std::vector<BYTE> &publicKey) {
    DWORD dwBlobLen;
    if (!CryptExportKey(hKey, 0, PUBLICKEYBLOB, 0, NULL, &dwBlobLen)) {
        return false;
    }
    publicKey.resize(dwBlobLen);
    if (!CryptExportKey(hKey, 0, PUBLICKEYBLOB, 0, &publicKey[0], &dwBlobLen)) {
        return false;
    }
    return true;
}

// Print books to receipt and all functionalities for counting change
void __fastcall TForm_Main::PrintBooksFromBasketBtnClick(TObject *Sender) {
    if(!loggedIn){
        ShowMessage("You're not logged in!");
        return;
    }

	// Generating key pairs
    HCRYPTPROV hProv;
    HCRYPTKEY hKey;
    if (!GenerateKeyPair(hProv, hKey)) {
        ShowMessage("Error generating key pair!");
        return;
    }

    // Basket ListView and full price count
    TDateTime currentDate = Now(); // Get the current date and time
    dateStr = FormatDateTime("dd/mm/yyyy", currentDate); // Custom
    timeStr = FormatDateTime("hh:nn:ss", currentDate); // Custom

	MemoBill->Lines->Clear();
    MemoBill->Lines->Add("LIBRARY");
	MemoBill->Lines->Add("-----------------------------------");
	// Static library function
	brRacuna = receiptNumberGen();
	EReceiptNum->Text = IntToStr(brRacuna);
	MemoBill->Lines->Add("Račun broj:   " + IntToStr(brRacuna));
    MemoBill->Lines->Add("Datum Izdavanja:   " + dateStr);
    MemoBill->Lines->Add("Vrijeme Izdavanja:   " + timeStr);
    MemoBill->Lines->Add("-----------------------------------");

    for (const auto &entry : bookCount) {
        for (int i = 0; i < ListViewCart->Items->Count; i++) {
            TListItem* item = ListViewCart->Items->Item[i];
            if (item->SubItems->Count > 0 && item->Caption == entry.first) {
                UnicodeString titleCut = item->SubItems->Strings[0];
                if (titleCut.Length() > 16) {
                    titleCut = item->SubItems->Strings[0].SubString(1, 16) + "..."; // Truncate and add ellipsis
                } else {
                    titleCut = titleCut + UnicodeString::StringOfChar(' ', (19-titleCut.Length()));
                }
                MemoBill->Lines->Add(titleCut + "    " + IntToStr(entry.second) + "    " + (item->SubItems->Strings[1]) + "€");
				break;
            }
        }
    }
    MemoBill->Lines->Add("-----------------------------------");
    MemoBill->Lines->Add("Iznos PDV-a:  5%");
	MemoBill->Lines->Add("Ukupno:   " + LabelFullPrice->Caption);
    MemoBill->Lines->Add("Operater:   " + formattedUser);

	// Converting MemoBill to string
    std::string memoContent = MemoToString(MemoBill);

	// Digital signing
    std::vector<BYTE> signature;
	if (SignData(memoContent, signature, hProv, hKey)) {
		MemoDigSignature->Lines->Clear();
		MemoDigSignature->Lines->Add("--------------------------------");

		// Converting signature to hexadecimal for appearance
		std::stringstream ss;
        ss << std::hex << std::setfill('0');
        for (BYTE b : signature) {
            ss << std::setw(2) << static_cast<int>(b);
        }
        UnicodeString hexSignature = ss.str().c_str();
		MemoDigSignature->Lines->Add("DIGITAL SIGNATURE: " + hexSignature);
		MemoDigSignature->Lines->Add("--------------------------------");

		// Storing public key and signature
        std::vector<BYTE> publicKey;
        if (ExportPublicKey(hProv, hKey, publicKey)) {
            publicKeyStore[brRacuna] = publicKey;
            signatureStore[brRacuna] = signature;
        } else {
            ShowMessage("Error exporting public key!");
        }
    } else {
        ShowMessage("Error signing data!");
    }

	//----------------------------------------------------------------------

	// Change functionalities
	float paid;
    if (!EditPaid->Text.IsEmpty() && TryStrToFloat(EditPaid->Text, paid)) {
		float price = fullPricePDV(fullPrice);
        float change = ceil((paid - price) * 100.0) / 100.0;
        int euro_100 = 0, euro_50 = 0, euro_20 = 0, euro_10 = 0, euro_05 = 0, euro_02 = 0, euros = 0, cent_50 = 0, cent_20 = 0, cent_10 = 0, cent_05 = 0, cent_02 = 0, cent_01 = 0;

        MemoChange->Lines->Clear();
        MemoChange->Lines->Add("CHANGE");
        MemoChange->Lines->Add("--------------------");
        MemoChange->Lines->Add(FloatToStr(ceil((paid - price) * 100.0) / 100.0) + "€");
        MemoChange->Lines->Add("--------------------");

        while (change > 0) {
            if (change >= 100) {
                euro_100++;
                change -= 100;
            } else if (change >= 50) {
                euro_50++;
                change -= 50;
            } else if (change >= 20) {
                euro_20++;
                change -= 20;
            } else if (change >= 10) {
                euro_10++;
                change -= 10;
            } else if (change >= 5) {
                euro_05++;
                change -= 5;
            } else if (change >= 2) {
                euro_02++;
                change -= 2;
            } else if (change >= 1) {
                euros++;
                change -= 1;
            } else if (change >= 0.50) {
                cent_50++;
                change -= 0.50;
            } else if (change >= 0.20) {
                cent_20++;
                change -= 0.20;
            } else if (change >= 0.10) {
                cent_10++;
                change -= 0.10;
            } else if (change >= 0.05) {
                cent_05++;
                change -= 0.05;
            } else if (change >= 0.02) {
                cent_02++;
                change -= 0.02;
            } else if (change >= 0.01) {
                cent_01++;
                change -= 0.01;
            } else {
                break; // to avoid infinite loop due to floating point precision issues
            }
        }

        if (euro_100) MemoChange->Lines->Add("100€ -> " + IntToStr(euro_100));
        if (euro_50) MemoChange->Lines->Add("50€ -> " + IntToStr(euro_50));
        if (euro_20) MemoChange->Lines->Add("20€ -> " + IntToStr(euro_20));
        if (euro_10) MemoChange->Lines->Add("10€ -> " + IntToStr(euro_10));
        if (euro_05) MemoChange->Lines->Add("5€ -> " + IntToStr(euro_05));
        if (euro_02) MemoChange->Lines->Add("2€ -> " + IntToStr(euro_02));
		if (euros) MemoChange->Lines->Add("1€ -> " + IntToStr(euros));
		if (cent_50) MemoChange->Lines->Add("0.50€ -> " + IntToStr(cent_50));
        if (cent_20) MemoChange->Lines->Add("0.20€ -> " + IntToStr(cent_20));
        if (cent_10) MemoChange->Lines->Add("0.10€ -> " + IntToStr(cent_10));
        if (cent_05) MemoChange->Lines->Add("0.05€ -> " + IntToStr(cent_05));
        if (cent_02) MemoChange->Lines->Add("0.02€ -> " + IntToStr(cent_02));
        if (cent_01) MemoChange->Lines->Add("0.01€ -> " + IntToStr(cent_01));
    } else {
        ShowMessage("Enter a valid number!");
    }

    CryptDestroyKey(hKey);
    CryptReleaseContext(hProv, 0);
}




//---------------------------------------------------------------------------

// My file format
void __fastcall TForm_Main::btnSaveReceiptMFTClick(TObject* Sender)
{
    if(!loggedIn){
		ShowMessage("You're not logged in!");
		return;
	}

	UnicodeString rac = IntToStr(brRacuna);
	const wchar_t* w_rac = rac.c_str();

	receipts.push_back({ Receipt(formattedUser.c_str(), dateStr.c_str()	,w_rac, LabelFullPrice->Caption.c_str(), timeStr.c_str(), L"LIBRARY") });
	// Create and initialize the header
	MojFormat Header;

    // Create a memory stream to hold the data
	std::unique_ptr<TFileStream> receiptStream(new TFileStream("receipts.mft", fmOpenReadWrite | fmShareDenyWrite));

	try {
		receiptStream->Seek(0, soFromEnd);

		// Write the header to the memory stream (only for the first time using it)
		//receiptStream->WriteBuffer(&Header, sizeof(MojFormat));

		// Write the receipt(s) to the memory stream
		for (int i = 0; i < receipts.size(); i++) {
			receiptStream->WriteBuffer(&receipts[i], sizeof(Receipt));
		}
		// Save the memory stream content to a file

    } catch (...) {
		ShowMessage("An error occurred while writing to the file.");
    }
}

// Reading the receipts from .mff
void __fastcall TForm_Main::btnReadReceiptMFTClick(TObject *Sender)
{
	if(!loggedIn){
		ShowMessage("You're not logged in!");
		return;
	}

	// Load contets from file to memorystream
	std::unique_ptr<TMemoryStream> receiptStream(new TMemoryStream);
	receiptStream->LoadFromFile("receipts.mft");
	// Read header
    MojFormat mojFormat;
	receiptStream->Read(&mojFormat, sizeof(MojFormat));

	// Check if correct format
	if(UnicodeString(mojFormat._naziv) != "MojFormat" || mojFormat._inacica != 1.0){
        ShowMessage("Pogrešan format!");
		return;
	}

	// Read all articles
	Receipt pom;
	int brArtikala = (receiptStream->Size - sizeof(MojFormat)) / sizeof(Receipt);
	for(int i = 0; i < brArtikala; i++){
		String receipt;
		receiptStream->Read(&pom, sizeof(Receipt));
		receipt += String(pom._operatorName) + " ";
		receipt += String(pom._date) + " ";
		receipt += String(pom._receiptNum) + " ";
		receipt += String(pom._price) + " ";
		receipt += String(pom._time) + " ";
		receipt += String(pom._libraryName) + " ";
		ShowMessage(receipt);
    }

}
//---------------------------------------------------------------------------

// Form_TCP handle, Chat functionality (15)
void __fastcall TForm_Main::Button2Click(TObject *Sender)
{
    if(!loggedIn){
		ShowMessage("You're not logged in!");
		return;
	}

	Form_TCP->ShowModal();
}

//---------------------------------------------------------------------------

// Url creating function
String GetURLFilename(String FileUrl){
	return FileUrl.SubString(LastDelimiter("/",FileUrl) + 1, FileUrl.Length());
}

// Terms of services download (17)
void __fastcall TForm_Main::BtnDownloadTermsClick(TObject *Sender)
{
	if(!loggedIn){
		ShowMessage("You're not logged in!");
		return;
	}

	ProgressBar1->Position = 0;
    Application->ProcessMessages();
    String EFileUrl = "https://drive.google.com/uc?export=download&id=1UW0ADdDxU7iJrlYOkPYvHhhdoqRUmwXd";
	String localFileName = "Terms_of_services.pdf";  // You can extract this from the URL if needed
    TFileStream *x = new TFileStream(localFileName, fmCreate);
    try {
        // Set up SSL handler
		TIdHTTP1->IOHandler = IdSSLIOHandlerSocketOpenSSL1;
		TIdHTTP1->HandleRedirects = true;

		// Set User-Agent (optional, but can help with some servers)
		TIdHTTP1->Request->UserAgent = "Mozilla/5.0 (compatible; Indy Library)";

        // Start downloading
		TIdHTTP1->Get(EFileUrl, x);


	} catch (const Exception &e) {

        // Handle exceptions
        ShowMessage("An error occurred: " + e.Message);
    }
    delete x;
}

//---------------------------------------------------------------------------

//Progress bar handles
void __fastcall TForm_Main::TIdHTTP1WorkBegin(TObject *ASender, TWorkMode AWorkMode,
		  __int64 AWorkCountMax)
{
    // set progressbar maximum
	ProgressBar1->Max = AWorkCountMax;
}

void __fastcall TForm_Main::TIdHTTP1Work(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCount)
{
    // show current download progress
	ProgressBar1->Position = AWorkCount;
	Application->ProcessMessages();
}

void __fastcall TForm_Main::TIdHTTP1WorkEnd(TObject *ASender, TWorkMode AWorkMode)
{
	if (currentLanguage == "HR") {
		LabelDownloadState->Caption = "Preuzimanje završeno!";
	} else{
		LabelDownloadState->Caption = "Download complete!";
	}
}

//---------------------------------------------------------------------------

// Changing download speed
void __fastcall TForm_Main::ComboBox1Change(TObject *Sender)
{
    if (ComboBox1->ItemIndex == 0)
			IdInterceptThrottler1->BitsPerSec = 409600; // 50 KB/s
	else if (ComboBox1->ItemIndex == 1)
			IdInterceptThrottler1->BitsPerSec = 819200; // 100 KB/s
	else if (ComboBox1->ItemIndex == 2)
			IdInterceptThrottler1->BitsPerSec = 1638400; // 200 KB/s
	else
			IdInterceptThrottler1->BitsPerSec = 8192000;
}
//---------------------------------------------------------------------------

// Validate digital signature and integrity of receipt
void __fastcall TForm_Main::BtnValidateReceiptClick(TObject *Sender)
{
    if(!loggedIn){
		ShowMessage("You're not logged in!");
		return;
	}

	int racunBroj = StrToInt(EReceiptNum->Text);

    if (publicKeyStore.find(racunBroj) == publicKeyStore.end() || signatureStore.find(racunBroj) == signatureStore.end()) {
        ShowMessage("No such receipt number!");
        return;
    }
    std::vector<BYTE> publicKey = publicKeyStore[racunBroj];
    std::vector<BYTE> signature = signatureStore[racunBroj];
    std::string memoContent = MemoToString(MemoBill);
    if (VerifySignature(memoContent, signature, publicKey)) {
        ShowMessage("Signature is valid!");
    } else {
        ShowMessage("Signature is not valid!");
	}
}
//---------------------------------------------------------------------------

// Opens "Form_MyBooks"
void __fastcall TForm_Main::Reservations1Click(TObject *Sender)
{
//	if(!loggedIn){
//		ShowMessage("You are not logged in!");
//	} else {
//
//		Form_MyBooks->ShowModal();
//	}

	Form_MyBooks->ShowModal();
}
