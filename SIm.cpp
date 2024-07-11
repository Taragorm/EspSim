//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("MainUnit.cpp", MainForm);
USEFORM("LogUnit.cpp", LogForm);
USEFORM("SimGfx.cpp", SimGfxForm);
USEFORM("IoFrameUnit.cpp", IoFrame); /* TFrame: File Type */
USEFORM("AnalogInEditForm.cpp", AnalogInEdit);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TMainForm), &MainForm);
         Application->CreateForm(__classid(TSimGfxForm), &SimGfxForm);
         Application->CreateForm(__classid(TLogForm), &LogForm);
         Application->CreateForm(__classid(TAnalogInEdit), &AnalogInEdit);
         Application->CreateForm(__classid(TAnalogInEdit), &AnalogInEdit);
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
