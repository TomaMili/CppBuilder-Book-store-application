//---------------------------------------------------------------------------

#ifndef TCP_UnitH
#define TCP_UnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <IdCustomTCPServer.hpp>
#include <IdTCPServer.hpp>
#include <IdContext.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <IdUDPBase.hpp>
#include <IdUDPClient.hpp>
#include <IdUDPServer.hpp>
#include <IdGlobal.hpp>
#include <IdSocketHandle.hpp>
#include <Vcl.Menus.hpp>
#include <map>
#include <string>

using namespace std;
//---------------------------------------------------------------------------
class TForm_TCP : public TForm
{
__published:	// IDE-managed Components
	TEdit *EditMessage;
	TButton *Button1;
	TIdTCPClient *C1;
	TEdit *EditHost;
	TLabel *Label1;
	TButton *BtnCon;
	TListBox *ListBox1;
	TLabel *Label2;
	TIdTCPServer *S1;
	TButton *ButtonSendFile;
	TOpenDialog *fileDialog;
	TImage *Image1;
	TIdUDPClient *UDPClient;
	TIdUDPServer *UDPServer;
	TMainMenu *MainMenu1;
	TMenuItem *Language1;
	TMenuItem *EN;
	TMenuItem *HR;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall BtnConClick(TObject *Sender);
	void __fastcall S1Execute(TIdContext *AContext);
	void __fastcall ButtonSendFileClick(TObject *Sender);
	void __fastcall UDPServerUDPRead(TIdUDPListenerThread *AThread, const TIdBytes AData,
          TIdSocketHandle *ABinding);
	void __fastcall ENClick(TObject *Sender);
	void __fastcall HRClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall TForm_TCP(TComponent* Owner);
  std::map<String, std::map<String, String> > translation;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_TCP *Form_TCP;
//---------------------------------------------------------------------------
#endif




