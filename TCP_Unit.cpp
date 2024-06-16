//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TCP_Unit.h"
#include "Main_Unit.h"
#include <IdGlobal.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include <IdSocketHandle.hpp>
TForm_TCP* Form_TCP;
//---------------------------------------------------------------------------
__fastcall TForm_TCP::TForm_TCP(TComponent* Owner) : TForm(Owner) {


translation["Label1"] = {
		{
			{ "EN", "Host:" },
			{ "HR", L"Poslužitelj:" }
		}
	};
	translation["BtnCon"] =	{
		{
			{"EN", "Connect"},
			{"HR", L"Poveži se"}
		}
	};
	translation["Label2"] =	{
		{
			{"EN", "Message:"},
			{"HR", "Poruka:"}
		}
	};
	translation["ButtonSendFile"] =	{
		{
			{"EN", "Send file"},
			{"HR", "Pošalji dat."}
		}
	};
	translation["Button1"] =	{
		{
			{"EN", "Send"},
			{"HR", "Pošalji"}
		}
	};

}
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


void StringToIdBytes(const UnicodeString& str, TIdBytes& bytes)
{
    bytes.Length = str.Length() * sizeof(wchar_t);
    for (int i = 0; i < str.Length(); ++i)
    {
        wchar_t currentChar = str[i + 1]; // C++ Builder strings are 1-indexed
        bytes[i * sizeof(wchar_t)] = currentChar & 0xFF;
        bytes[i * sizeof(wchar_t) + 1] = (currentChar >> 8) & 0xFF;
    }
}
UnicodeString IdBytesToString(const TIdBytes& bytes)
{
	int charCount = bytes.Length / sizeof(wchar_t); // Calculate number of wchar_t characters
    UnicodeString str;
    for (int i = 0; i < charCount; ++i)
    {
		wchar_t currentChar = (bytes[i * sizeof(wchar_t) + 1] << 8) | bytes[i * sizeof(wchar_t)];// Retrieve wchar_t from bytes
		str += currentChar; // Append character to string
    }
	return str;  // Return the constructed UnicodeString
}

void __fastcall TForm_TCP::Button1Click(TObject* Sender)
{
    // send message to chat server
    if (C1->Connected()) {
		UnicodeString Message = Form_Main->formattedUser + ": " + EditMessage->Text;
		C1->Socket->WriteLn(Message);
	} else {
		ShowMessage("Not connected to the server.");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm_TCP::BtnConClick(TObject *Sender)
{
	 // connect to chat server
	C1->Host = EditHost->Text;
    if (C1->Connected()) {
        C1->Disconnect();
		BtnCon->Caption = "Connect";
        return;
    }
    try {
		C1->Connect();
		BtnCon->Caption = "Disconnect";
    }
	catch(const Exception &e) {
		ShowMessage("Unable to connect: " + e.Message);
	}
}
//---------------------------------------------------------------------------

void ScreenCapture(TMemoryStream* ms)
{
   TRect r = Rect(0, 0, Screen->Width, Screen->Height);
   std::unique_ptr<Graphics::TBitmap> bmp(new Graphics::TBitmap);
   bmp->Width = r.Width();
   bmp->Height = r.Height();
   bmp->PixelFormat = pf24bit;
   ::BitBlt( bmp->Canvas->Handle, 0, 0, bmp->Width, bmp->Height, ::GetDC(0), 0, 0, SRCCOPY);
   ::ReleaseDC(0, ::GetDC(0));
   bmp->SaveToStream(ms);
   bmp->FreeImage();
}

void __fastcall TForm_TCP::S1Execute(TIdContext *AContext)
{
	 UnicodeString message = AContext->Connection->Socket->ReadLn();
    if (message == "TakeScreenshot") {
        std::unique_ptr<TMemoryStream> ms(new TMemoryStream);
        ScreenCapture(ms.get()); // do screenshot and save content to stream
        AContext->Connection->Socket->Write(ms->Size); // send stream size
        AContext->Connection->Socket->Write(ms.get()); // send stream
        TThread::Synchronize(nullptr, [&]() {
            ms->Position = 0; // reset stream position before loading the image
            Form_Main->Image1->Picture->LoadFromStream(ms.get());
        });
    } else {
        TThread::Synchronize(TThread::CurrentThread, [&]() {
            ListBox1->Items->Add(message);
            ListBox1->ItemIndex = ListBox1->Count - 1; // select incoming message
            Form_Main->ListBoxNotifications->Items->Add("Notification: " + message);
            Form_Main->ListBoxNotifications->ItemIndex =
                Form_Main->ListBoxNotifications->Count - 1; // Select the incoming message
        });
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm_TCP::ButtonSendFileClick(TObject* Sender)
{
	C1->Socket->WriteLn("TakeScreenshot");
    int size = C1->Socket->ReadInt64(); // read stream size
    std::unique_ptr<TMemoryStream> ms(new TMemoryStream);
    C1->Socket->ReadStream(ms.get(), size); // read stream
    ms->Position = 0; // read from the beginning of the stream
    TThread::Synchronize(nullptr, [&]() {
        Form_Main->Image1->Picture->LoadFromStream(ms.get()); // show stream content (image)
	});
}
//---------------------------------------------------------------------------

void __fastcall TForm_TCP::UDPServerUDPRead(TIdUDPListenerThread *AThread, const TIdBytes AData,
          TIdSocketHandle *ABinding)
{
     // Handle incoming UDP messages
    UnicodeString receivedMessage = BytesToString(AData);
    TThread::Synchronize(TThread::CurrentThread, [&](){
		Form_Main->ListBoxNotifications->Items->Add("Notification: " + receivedMessage);
		Form_Main->ListBoxNotifications->ItemIndex = Form_Main->ListBoxNotifications->Count - 1; // Select the incoming message
    });
}
//---------------------------------------------------------------------------


void __fastcall TForm_TCP::ENClick(TObject *Sender)
{
    translateForm(this, "EN", translation);
	Form_Main->currentLanguage = "EN";
	Form_Main->ENClick(Sender);
}


void __fastcall TForm_TCP::HRClick(TObject *Sender)
{
    translateForm(this, "HR", translation);
	Form_Main->currentLanguage = "HR";
    Form_Main->HRClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm_TCP::FormShow(TObject *Sender)
{
    if (Form_Main->currentLanguage == "HR") {
		translateForm(this, "HR", translation);
	} else{
		translateForm(this, "EN", translation);
	}
}
//---------------------------------------------------------------------------

