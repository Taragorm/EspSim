//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "LogUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TLogForm *LogForm;
//---------------------------------------------------------------------------
__fastcall TLogForm::TLogForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TLogForm::clearButtonClick(TObject *Sender)
{
	log->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TLogForm::logMessage(AnsiString str)
{
	log->Text = log->Text + str;
}
//---------------------------------------------------------------------------

