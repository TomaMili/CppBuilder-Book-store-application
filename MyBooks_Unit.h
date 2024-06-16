//---------------------------------------------------------------------------

#ifndef MyBooks_UnitH
#define MyBooks_UnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.WinXPickers.hpp>
#include "frxClass.hpp"
#include "frxDBSet.hpp"
#include "frxExportBaseDialog.hpp"
#include "frxExportPDF.hpp"
#include <Vcl.Dialogs.hpp>
#include <Vcl.Menus.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.ObjectScope.hpp>
#include <REST.Client.hpp>
#include <REST.Types.hpp>
#include <Data.Bind.EngExt.hpp>
#include <System.Bindings.Outputs.hpp>
#include <System.Rtti.hpp>
#include <Vcl.Bind.DBEngExt.hpp>
#include <Vcl.Bind.Editors.hpp>
#include <map>
//---------------------------------------------------------------------------
class TForm_MyBooks : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *Users;
	TGroupBox *Books;
	TGroupBox *Reservations;
	TDBGrid *DBGrid1;
	TDBGrid *DBGrid2;
	TDBGrid *DBGrid3;
	TLabel *ReservationsReservationsToLabel;
	TDatePicker *EditDateToRes;
	TDatePicker *EditDateFromRes;
	TLabel *ReservationsReservationsFromLabel;
	TButton *BtnSaveDB;
	TButton *BtnSaveTBooks;
	TEdit *EditBooksID;
	TEdit *EditUsersName;
	TEdit *EditUsersSurname;
	TLabel *ReservationsUsersNameLabel;
	TLabel *ReservationsUsersSurnameLabel;
	TButton *BtnSaveTUser;
	TLabel *ReservationsBooksIDLabel;
	TButton *BtnDeleteTUser;
	TButton *BtnDeleteTBooks;
	TButton *BtnDeleteDB;
	TButton *BtnEditTUser;
	TButton *BtnReadTUser;
	TButton *BtnEditTBooks;
	TButton *BtnReadTBooks;
	TButton *BtnEditDB;
	TButton *BtnReadDB;
	TfrxReport *frxReport1;
	TfrxDBDataset *frxReservations;
	TfrxPDFExport *frxPDFExport1;
	TOpenDialog *OpenDialog1;
	TDBImage *DBImage1;
	TButton *BtnLoadImageTUser;
	TButton *BtnDeleteImageTUser;
	TfrxDBDataset *frxUsers;
	TButton *btnShowReport;
	TButton *btnSortGenre;
	TButton *btnSortAuthor;
	TButton *btnSortNumPages;
	TButton *btnSortBookID;
	TButton *btnSortTitle;
	TButton *btnSortID;
	TLabel *ReservationsBooksGenreLabel;
	TEdit *filterTextBox;
	TCheckBox *filterCheckBox;
	TMainMenu *MainMenu1;
	TMenuItem *Language1;
	TMenuItem *Eng1;
	TMenuItem *Hrv1;
	TMemo *MemoWordSearch;
	TEdit *EWordSearch;
	TButton *BtnWordSearch;
	TRESTClient *RESTClient1;
	TRESTRequest *RESTRequest1;
	TRESTResponse *RESTResponse1;
	TMenuItem *ExitBtnNav;
	TBindingsList *BindingsList1;
	void __fastcall BtnSaveDBClick(TObject *Sender);
	void __fastcall BtnSaveTUserClick(TObject *Sender);
	void __fastcall BtnSaveTBooksClick(TObject *Sender);
	void __fastcall BtnDeleteTUserClick(TObject *Sender);
	void __fastcall BtnDeleteTBooksClick(TObject *Sender);
	void __fastcall BtnDeleteDBClick(TObject *Sender);
	void __fastcall BtnEditTUserClick(TObject *Sender);
	void __fastcall BtnEditTBooksClick(TObject *Sender);
	void __fastcall BtnEditDBClick(TObject *Sender);
	void __fastcall BtnReadTUserClick(TObject *Sender);
	void __fastcall BtnReadTBooksClick(TObject *Sender);
	void __fastcall BtnReadDBClick(TObject *Sender);
	void __fastcall BtnLoadImageTUserClick(TObject *Sender);
	void __fastcall BtnDeleteImageTUserClick(TObject *Sender);
	void __fastcall btnShowReportClick(TObject *Sender);
	void __fastcall btnSortGenreClick(TObject *Sender);
	void __fastcall btnSortAuthorClick(TObject *Sender);
	void __fastcall btnSortNumPagesClick(TObject *Sender);
	void __fastcall btnSortBookIDClick(TObject *Sender);
	void __fastcall btnSortTitleClick(TObject *Sender);
	void __fastcall btnSortIDClick(TObject *Sender);
	void __fastcall filterCheckBoxClick(TObject *Sender);
	void __fastcall Eng1Click(TObject *Sender);
	void __fastcall Hrv1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall BtnWordSearchClick(TObject *Sender);
	void __fastcall ExitBtnNavClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall TForm_MyBooks(TComponent* Owner);
  std::map<String, std::map<String, String> > translation;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_MyBooks *Form_MyBooks;
//---------------------------------------------------------------------------
#endif


