//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "IoPin.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cspin"
#pragma resource "*.dfm"
TIoPinBaseFrame *IoPinBaseFrame;
//---------------------------------------------------------------------------
__fastcall TIoPinBaseFrame::TIoPinBaseFrame(TComponent* Owner)
    : TFrame(Owner)
{

}
//---------------------------------------------------------------------------
