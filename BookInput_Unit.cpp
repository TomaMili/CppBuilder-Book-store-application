//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BookInput_Unit.h"
#include "PopisKnjiga.h"
#include "Main_Unit.h"
#include "ProjectPCH1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm_BookInput *Form_BookInput;
//---------------------------------------------------------------------------

void translateForm(TForm* Form, String Language, const std::map<String, std::map<String, String>>& translation){
	for(int i = 0; i < Form->ComponentCount; i++) // iterate though all components on the form
		for(auto it_ComponentName = translation.begin(); it_ComponentName != translation.end(); it_ComponentName++)
			if(Form->Components[i]->Name == it_ComponentName->first) // find component by name
				for(auto it_Language = it_ComponentName->second.begin(); it_Language != it_ComponentName->second.end(); it_Language++)
					if(it_Language->first == Language) // find translation for the target language
						if(IsPublishedProp(Form->Components[i], "Caption"))
							SetPropValue(Form->Components[i], "Caption", it_Language->second);
}

__fastcall TForm_BookInput::TForm_BookInput(TComponent* Owner) : TForm(Owner)
{
	translation["BookInputTitleLabel"] = {
		{
			{ "EN", "Title:" },
			{ "HR", L"Naslov:" }
		}
	};
	translation["BookInputAuthorLabel"] =	{
		{
			{"EN", "Author:"},
			{"HR", "Autor:"}
		}
	};
	translation["BookInputPagesLabel"] =	{
		{
			{"EN", "Number of pages:"},
			{"HR", "Broj stranica:"}
		}
	};
	translation["BookInputGenreLabel"] =	{
		{
			{"EN", "Genre"},
			{"HR", L"Žanr"}
		}
	};
	translation["BtnInputSave"] =	{
		{
			{"EN", "Save"},
			{"HR", "Spremi"}
		}
	};
	translation["Language1"] = {
		{
			{ "EN", "Language" },
			{ "HR", "Jezik" }
		}
	};
}

//---------------------------------------------------------------------------
void __fastcall TForm_BookInput::BtnInputSaveClick(TObject *Sender)
{
	Form_Main->brStranica = StrToInt(PageNumberInput->Text);
	Form_Main->title = TitleInput->Text;
	Form_Main->author = AuthorInput->Text;
	Form_Main->genre = GenreInput->Text;
}
//---------------------------------------------------------------------------
void __fastcall TForm_BookInput::FormClose(TObject *Sender, TCloseAction &Action)

{
	PageNumberInput->Text = "";
	TitleInput->Text = "";
	AuthorInput->Text = "";
	GenreInput->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm_BookInput::Eng1Click(TObject *Sender)
{
    translateForm(this, "EN", translation);
	Form_Main->currentLanguage = "EN";
	Form_Main->ENClick(Sender);
}


void __fastcall TForm_BookInput::Hrv1Click(TObject *Sender)
{
    translateForm(this, "HR", translation);
	Form_Main->currentLanguage = "HR";
    Form_Main->HRClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm_BookInput::FormShow(TObject *Sender)
{
    if (Form_Main->currentLanguage == "HR") {
		translateForm(this, "HR", translation);
	} else{
		translateForm(this, "EN", translation);
	}
}
//---------------------------------------------------------------------------


