//---------------------------------------------------------------------------

#ifndef DiPinH
#define DiPinH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "IoPin.h"
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TDiPinFrame : public TIoPinBaseFrame
{
__published:	// IDE-managed Components
    TBitBtn *BitBtn1;
private:	// User declarations
public:		// User declarations
    __fastcall TDiPinFrame(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDiPinFrame *DiPinFrame;
//---------------------------------------------------------------------------
#endif
