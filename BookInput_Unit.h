//---------------------------------------------------------------------------

#ifndef BookInput_UnitH
#define BookInput_UnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Xml.XMLDoc.hpp>
#include <Xml.xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include <Vcl.Menus.hpp>
#include <map>
//---------------------------------------------------------------------------
class TForm_BookInput : public TForm
{
__published:	// IDE-managed Components
	TEdit *TitleInput;
	TEdit *AuthorInput;
	TEdit *PageNumberInput;
	TLabel *BookInputAuthorLabel;
	TLabel *BookInputPagesLabel;
	TLabel *BookInputGenreLabel;
	TButton *BtnInputSave;
	TEdit *GenreInput;
	TMainMenu *MainMenu1;
	TMenuItem *Language1;
	TMenuItem *Eng1;
	TMenuItem *Hrv1;
	TLabel *BookInputTitleLabel;
	void __fastcall BtnInputSaveClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Eng1Click(TObject *Sender);
	void __fastcall Hrv1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall TForm_BookInput(TComponent* Owner);
  std::map<String, std::map<String, String> > translation;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_BookInput *Form_BookInput;
//---------------------------------------------------------------------------
#endif


