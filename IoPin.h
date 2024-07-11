//---------------------------------------------------------------------------

#ifndef IoPinH
#define IoPinH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "cspin.h"


//---------------------------------------------------------------------------
class TIoPinBaseFrame : public TFrame
{
__published:	// IDE-managed Components
    TGroupBox *groupBox;
    __property UnicodeString Name { read=_name, write=setName };
    __property UnicodeString Descr { read=_descr, write=setDescr };
    __property int Pin { read=_pin, write=setPin };

protected:
    UnicodeString _name;
    UnicodeString _descr;
    int _pin;

private:	// User declarations
    void __fastcall updateCaption()
    {}

    void __fastcall setName(UnicodeString n) { _name = n; updateCaption(); }
    void __fastcall setDescr(UnicodeString d) { _descr = d; updateCaption(); }
    void __fastcall setPin(int p) { _pin = p; updateCaption(); }


public:		// User declarations
	__fastcall TIoPinBaseFrame(TComponent* Owner);

    //
    // Standard I/O access
    virtual int __fastcall  analogRead() const { return 0; }
    virtual bool __fastcall digitalRead() const { return false; }
    virtual void __fastcall analogWrite(int v) {}
    virtual void __fastcall digitalWrite(int v) {}


};
//---------------------------------------------------------------------------
extern PACKAGE TIoPinBaseFrame *IoPinBaseFrame;
//---------------------------------------------------------------------------
#endif
