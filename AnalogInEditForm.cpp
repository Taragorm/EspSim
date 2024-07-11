//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AnalogInEditForm.h"
#include "IoFrameUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAnalogInEdit *AnalogInEdit;
//---------------------------------------------------------------------------
__fastcall TAnalogInEdit::TAnalogInEdit(TComponent* Owner)
    : TForm(Owner)
{
   errorLabel->Caption = "";
   this->Left = Mouse->CursorPos.X;
   this->Top = Mouse->CursorPos.Y;
}
//---------------------------------------------------------------------------
void __fastcall TAnalogInEdit::setIo(class TIoFrame* io)
{
    this->Caption = io->name();
    _io = io;
    this->unitsLabel->Caption = io->units();
    _lo = io->lo();
    _hi = io->hi();
    minLabel->Caption = AnsiString(_lo);
    maxLabel->Caption = AnsiString(_hi);
    trackBar->Min = _lo;
    trackBar->Max = _hi;
    load();
}
//---------------------------------------------------------------------------
void __fastcall TAnalogInEdit::trackBarTracking(TObject *Sender)
{
    auto pos = trackBar->Position;
    edit->Text = AnsiString(pos);
    _io->value(pos);
}
//---------------------------------------------------------------------------

void __fastcall TAnalogInEdit::applyButtonClick(TObject *Sender)
{
    double v=-1;
    try
    {
        v = StrToFloat(edit->Text);
        if(v>_hi)
            throw Exception(">HI");
        if(v<_lo)
            throw Exception("<LO");

        errorLabel->Caption = "";
        _io->value(v);
        trackBar->Position = v;
    }
    catch(Exception& ex)
    {
        Beep();
        errorLabel->Caption = ex.Message;
    }
}
//---------------------------------------------------------------------------
void __fastcall TAnalogInEdit::revertButtonClick(TObject *Sender)
{
     edit->Text = AnsiString(_io->value());
     errorLabel->Caption = "";
}
//---------------------------------------------------------------------------
void __fastcall TAnalogInEdit::load()
{
    trackBar->Position = _io->value();
    edit->Text = AnsiString(_io->value());
}
//---------------------------------------------------------------------------
void __fastcall TAnalogInEdit::FormShow(TObject *Sender)
{
    edit->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TAnalogInEdit::FormClose(TObject *Sender, TCloseAction &Action)
{
    Action = caFree;
}
//---------------------------------------------------------------------------

