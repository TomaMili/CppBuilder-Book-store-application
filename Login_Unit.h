//---------------------------------------------------------------------------

#ifndef Login_UnitH
#define Login_UnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <map>
//---------------------------------------------------------------------------
class TForm_Login : public TForm
{
__published:	// IDE-managed Components
	TEdit *EditUsername;
	TEdit *EditPassword;
	TButton *BtnLogin;
	TButton *BtnRegister;
	TButton *Button3;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *LabelErrorLogin;
	TCheckBox *LoginSaveCheck;
	TLabel *LabelErrorPassword;
	TMainMenu *MainMenu1;
	TMenuItem *LanguageLoginClick;
	TMenuItem *EN;
	TMenuItem *HR;
	TMenuItem *ExitBtnNavLogin;
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall BtnRegisterClick(TObject *Sender);
	void __fastcall BtnLoginClick(TObject *Sender);
	void __fastcall ENClick(TObject *Sender);
	void __fastcall HRClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ExitBtnNavLoginClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall TForm_Login(TComponent* Owner);
  std::map<String, std::map<String, String> > translation;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_Login *Form_Login;
//---------------------------------------------------------------------------
#endif



