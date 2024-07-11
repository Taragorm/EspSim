//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DiPin.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "IoPin"
#pragma resource "*.dfm"
TDiPinFrame *DiPinFrame;
//---------------------------------------------------------------------------
__fastcall TDiPinFrame::TDiPinFrame(TComponent* Owner)
    : TIoPinBaseFrame(Owner)
{
}
//---------------------------------------------------------------------------
