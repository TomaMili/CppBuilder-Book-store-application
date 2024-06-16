//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("TCP_Unit.cpp", Form_TCP);
USEFORM("BookInput_Unit.cpp", Form_BookInput);
USEFORM("DataModule.cpp", Data_Module); /* TDataModule: File Type */
USEFORM("Login_Unit.cpp", Form_Login);
USEFORM("Main_Unit.cpp", Form_Main);
USEFORM("MyBooks_Unit.cpp", Form_MyBooks);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TForm_Main), &Form_Main);
		Application->CreateForm(__classid(TForm_Login), &Form_Login);
		Application->CreateForm(__classid(TForm_BookInput), &Form_BookInput);
		Application->CreateForm(__classid(TForm_MyBooks), &Form_MyBooks);
		Application->CreateForm(__classid(TData_Module), &Data_Module);
		Application->CreateForm(__classid(TForm_TCP), &Form_TCP);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
