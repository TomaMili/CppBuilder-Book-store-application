//---------------------------------------------------------------------------

#ifndef DataModuleH
#define DataModuleH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
//---------------------------------------------------------------------------
class TData_Module : public TDataModule
{
__published:	// IDE-managed Components
	TADOConnection *MainConnection;
	TADOTable *TBooks;
	TDataSource *DBooks;
	TADOTable *TRezervations;
	TADOTable *TUsers;
	TDataSource *DRezervations;
	TDataSource *DUsers;
	TIntegerField *TRezervationsTrajanjeRezervacije;
	TAutoIncField *TRezervationsID;
	TDateTimeField *TRezervationsDatumOd;
	TIntegerField *TRezervationsIDKnjige;
	TIntegerField *TRezervationsIDUseri;
	TDateTimeField *TRezervationsDatumDo;
	TBCDField *TRezervationsCijena;
	TAutoIncField *TBooksID;
	TWideStringField *TBooksNaziv;
	TIntegerField *TBooksBrStranica;
	TWideStringField *TBooksAutor;
	TWideStringField *TBooksZanr;
	TIntegerField *TBooksIDKnjiga;
	TStringField *TRezervationsIme;
	TWideStringField *TUsersIme;
	TWideStringField *TUsersPrezime;
	TAutoIncField *TUsersIDUseri;
	TBlobField *TUsersSlika;
	void __fastcall TRezervationsCalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
	__fastcall TData_Module(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TData_Module *Data_Module;
//---------------------------------------------------------------------------
#endif
