//---------------------------------------------------------------------------

#ifndef Main_UnitH
#define Main_UnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.Actions.hpp>
#include <System.Win.TaskbarCore.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Taskbar.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ToolWin.hpp>
#include <Xml.XMLDoc.hpp>
#include <Xml.xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include "frxClass.hpp"
#include "frxDBSet.hpp"
#include "frxExportBaseDialog.hpp"
#include "frxExportPDF.hpp"
#include "ProjectPCH1.h"
#include <Vcl.ExtCtrls.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdHTTP.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <IdIntercept.hpp>
#include <IdInterceptThrottler.hpp>
#include <IdIOHandler.hpp>
#include <IdIOHandlerSocket.hpp>
#include <IdIOHandlerStack.hpp>
#include <IdSSL.hpp>
#include <IdSSLOpenSSL.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.ObjectScope.hpp>
#include <REST.Client.hpp>
#include <REST.Types.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Datasnap.DSClientRest.hpp>
#include <map>
#include <vector>
//---------------------------------------------------------------------------
class TForm_Main : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TMainMenu *MainMenu1;
	TActionList *ActionList1;
	TMenuItem *LoginMenuClick;
	TAction *Action1;
	TGroupBox *GroupBoxKnjige;
	TListView *ListViewKnjige;
	TXMLDocument *PopisKnjiga;
	TButton *BtnLoadBooks;
	TMenuItem *EN;
	TMenuItem *HR;
	TButton *BtnDeleteBooks;
	TButton *BtnUpdateBooks;
	TButton *BtnAddBooks;
	TGroupBox *GroupBox1;
	TListView *ListViewFavKnjige;
	TButton *BtnLoadFavBooks;
	TButton *BtnAddFavBooks;
	TButton *BtnDeleteFavBooks;
	TGroupBox *Checkout;
	TListView *ListViewCart;
	TButton *AddBooksToBasketBtn;
	TButton *PrintBooksFromBasketBtn;
	TEdit *artiklKnjigaIDEdit;
	TLabel *CheckoutTotalPriceLabel;
	TLabel *CheckoutPDVLabel;
	TLabel *CheckoutPriceLabel;
	TLabel *LabelPrice;
	TLabel *LabelPDV;
	TLabel *LabelFullPrice;
	TLabel *CheckoutIDLabel;
	TGroupBox *GroupBox3;
	TMemo *MemoBill;
	TEdit *EditPaid;
	TLabel *CheckoutPaidLabel;
	TMemo *MemoChange;
	TButton *btnSaveReceiptMFT;
	TButton *btnReadReceiptMFT;
	TListView *ListViewGenres;
	TButton *Button2;
	TListBox *ListBoxNotifications;
	TImage *Image1;
	TComboBox *ComboBox1;
	TProgressBar *ProgressBar1;
	TLabel *LabelDownloadState;
	TButton *BtnDownloadTerms;
	TMemo *MemoDigSignature;
	TButton *BtnValidateReceipt;
	TEdit *EReceiptNum;
	TMenuItem *Reservations1;
	TIdInterceptThrottler *IdInterceptThrottler1;
	TIdSSLIOHandlerSocketOpenSSL *IdSSLIOHandlerSocketOpenSSL1;
	TIdHTTP *TIdHTTP1;
	TRESTClient *RESTClient1;
	TRESTRequest *RESTRequest1;
	TRESTResponse *RESTResponse1;
	TImage *Image2;
	TAction *Action2;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall LoginMenuClickClick(TObject *Sender);
	void __fastcall BtnLoadBooksClick(TObject *Sender);
	void __fastcall ENClick(TObject *Sender);
	void __fastcall HRClick(TObject *Sender);
	void __fastcall BtnAddBooksClick(TObject *Sender);
	void __fastcall BtnDeleteBooksClick(TObject *Sender);
	void __fastcall BtnLoadFavBooksClick(TObject *Sender);
	void __fastcall BtnAddFavBooksClick(TObject *Sender);
	void __fastcall BtnDeleteFavBooksClick(TObject *Sender);
	void __fastcall AddBooksToBasketBtnClick(TObject *Sender);
	void __fastcall PrintBooksFromBasketBtnClick(TObject *Sender);
	void __fastcall btnSaveReceiptMFTClick(TObject *Sender);
	void __fastcall btnReadReceiptMFTClick(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall BtnDownloadTermsClick(TObject *Sender);
	void __fastcall TIdHTTP1WorkBegin(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCountMax);
	void __fastcall TIdHTTP1Work(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCount);
	void __fastcall TIdHTTP1WorkEnd(TObject *ASender, TWorkMode AWorkMode);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall BtnValidateReceiptClick(TObject *Sender);
	void __fastcall Reservations1Click(TObject *Sender);
	void __fastcall BtnUpdateBooksClick(TObject *Sender);
  private: // User declarations
  public: // User declarations
    __fastcall TForm_Main(TComponent* Owner);
    bool loggedIn;
    System::UnicodeString currentUser;
    System::UnicodeString currentLanguage;
    std::map<String, std::map<String, String> > translation;
    String formattedUser;
    int idLastBook;
    int brStranica;
    float fullPrice;
    UnicodeString dateStr;
    UnicodeString timeStr;
    int brRacuna;
    std::map<int, int> bookCount;
    System::UnicodeString title;
	System::UnicodeString author;
	System::UnicodeString genre;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_Main *Form_Main;
//---------------------------------------------------------------------------
#endif


















