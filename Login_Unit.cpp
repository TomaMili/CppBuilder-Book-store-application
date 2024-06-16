//---------------------------------------------------------------------------

#include <vcl.h>
#include <registry.hpp>
#pragma hdrstop

#include "Login_Unit.h"
#include "Main_Unit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm_Login *Form_Login;
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


__fastcall TForm_Login::TForm_Login(TComponent* Owner) : TForm(Owner)
{
    TRegistry* Registry = new TRegistry;
    Registry->RootKey = HKEY_CURRENT_USER;
	UnicodeString KLJUC = "Software\\ProjektToma";
	// If key exists and can be opened...

	if (Registry->OpenKey(KLJUC, false)) {
		EditUsername->Text = Registry->ReadString("remember");
		Registry->CloseKey();

	}

	delete Registry;




	translation["Label1"] = {
		{
			{ "EN", "Username:" },
			{ "HR", L"Korisničko ime:" }
		}
	};
	translation["Label2"] =	{
		{
			{"EN", "Password:"},
			{"HR", "Lozinka:"}
		}
	};
	translation["BtnRegister"] =	{
		{
			{"EN", "Register"},
			{"HR", "Registriraj"}
		}
	};
	translation["BtnLogin"] =	{
		{
			{"EN", "Login"},
			{"HR", "Prijavi"}
		}
	};
	translation["Button3"] =	{
		{
			{"EN", "Cancel"},
			{"HR", "Otkaži"}
		}
	};
	translation["LoginSaveCheck"] = {
		{
			{ "EN", "Remember me" },
			{ "HR", "Zapamti me" }
		}
	};
	translation["LanguageLoginClick"] =	{
		{
			{"EN", "Language"},
			{"HR", "Jezik"}
		}
	};
	translation["ExitBtnNavLogin"] =	{
		{
			{"EN", "Exit"},
			{"HR", "Izlaz"}
		}
	};



}
//---------------------------------------------------------------------------

// Enter key login click
void __fastcall TForm_Login::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift){
	if (Key == VK_RETURN){
		BtnLogin->Click();
	}
}
//---------------------------------------------------------------------------


// Remember me button
void __fastcall TForm_Login::FormClose(TObject *Sender, TCloseAction &Action){
    TRegistry *Registry = new TRegistry;
	Registry->RootKey = HKEY_CURRENT_USER;
	UnicodeString KLJUC = "Software\\ProjektToma";

	try {
        if (Registry->OpenKey(KLJUC, true)) {
            if (LoginSaveCheck->Checked) {
                Registry->WriteString("remember", EditUsername->Text);
            } else {
                Registry->DeleteValue("remember");
            }
            Registry->CloseKey();
        } else {
            ShowMessage("Failed to access registry!");
        }
    } catch (...) {
        ShowMessage("An error occurred while saving remember me settings!");
    }

	delete Registry;

}
//---------------------------------------------------------------------------

// Button for register
void __fastcall TForm_Login::BtnRegisterClick(TObject *Sender)
{
    TRegistry *Registry = new TRegistry;
	Registry->RootKey = HKEY_CURRENT_USER;
	UnicodeString KLJUC = "Software\\ProjektToma";

	try {
		// Try to open the registry key or create it if it doesn't exist
		if (Registry->OpenKey(KLJUC, true)) {
			// Save the username and password to the registry
			Registry->WriteString(EditUsername->Text, EditPassword->Text);
			Registry->CloseKey();
			Form_Main->loggedIn = true;
			Form_Main->currentUser = EditUsername->Text;
            ShowMessage("Registration successful!");
        } else {
			ShowMessage("Failed to access registry!");
		}
	} catch (...) {
		ShowMessage("An error occurred during registration!");
	}
    delete Registry;
}
//---------------------------------------------------------------------------


// Button for login
void __fastcall TForm_Login::BtnLoginClick(TObject *Sender)
{
    TRegistry *Registry = new TRegistry;
    Registry->RootKey = HKEY_CURRENT_USER;
    UnicodeString KLJUC = "Software\\ProjektToma";

    try {
		if (Registry->OpenKey(KLJUC, false)) {
            UnicodeString savedPassword = Registry->ReadString(EditUsername->Text);
            Registry->CloseKey();

			if (savedPassword.IsEmpty()) {
				LabelErrorLogin->Caption = "Username not found!";
            } else if (EditPassword->Text == savedPassword) {
				Form_Main->loggedIn = true;
                Form_Main->currentUser = EditUsername->Text;
                Close();
            } else {
				LabelErrorLogin->Caption = "";
				LabelErrorPassword->Caption = "Invalid password!";
            }
        }
		else {
			ShowMessage("Failed to access registry!");
		}
	} catch (...) {
        ShowMessage("An error occurred during login!");
	}
	delete Registry;
}
//---------------------------------------------------------------------------


void __fastcall TForm_Login::ENClick(TObject *Sender)
{
	translateForm(this, "EN", translation);
	Form_Main->currentLanguage = "EN";
	Form_Main->ENClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm_Login::HRClick(TObject *Sender)
{
	translateForm(this, "HR", translation);
	Form_Main->currentLanguage = "HR";
    Form_Main->HRClick(Sender);
}
//---------------------------------------------------------------------------




void __fastcall TForm_Login::FormShow(TObject *Sender)
{
    if (Form_Main->currentLanguage == "HR") {
		translateForm(this, "HR", translation);
	} else{
		translateForm(this, "EN", translation);
	}
}
//---------------------------------------------------------------------------

// Exit button navigation
void __fastcall TForm_Login::ExitBtnNavLoginClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------


