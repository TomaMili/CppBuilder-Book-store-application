//---------------------------------------------------------------------------


#pragma hdrstop
#include <System.SysUtils.hpp>
#include "DataModule.h"
#include "Main_Unit.h"
#include "MyBooks_Unit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma resource "*.dfm"
TData_Module *Data_Module;
//---------------------------------------------------------------------------
__fastcall TData_Module::TData_Module(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------

// Calculated field for DB Reservations
void __fastcall TData_Module::TRezervationsCalcFields(TDataSet *DataSet)
{
	TDateTime datumOd = DataSet->FieldByName("DatumOd")->AsDateTime;
    TDateTime datumDo = DataSet->FieldByName("DatumDo")->AsDateTime;

    // Calculate the difference in days
    int vrijemeTrajanja = static_cast<int>(datumDo - datumOd);

	// Assign the duration to the "TrajanjeRezervacije" field

	DataSet->FieldByName("TrajanjeRezervacije")->AsInteger = vrijemeTrajanja;

}
//---------------------------------------------------------------------------


