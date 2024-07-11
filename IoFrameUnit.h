//---------------------------------------------------------------------------

#ifndef IoFrameUnitH
#define IoFrameUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Samples.Spin.hpp>

#include <ProcDef.h>
#include <Vcl.Mask.hpp>
#include <Vcl.ComCtrls.hpp>

#include "convert.h"
//---------------------------------------------------------------------------
class TIoFrame : public TFrame
{
    friend class ProcDef;

__published:	// IDE-managed Components
    TGroupBox *GroupBox1;
    TFlowPanel *FlowPanel1;
    TShape *shape;
    TLabel *unitsLabel;
    TEdit *edit;
    void __fastcall shapeMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
    void __fastcall editClick(TObject *Sender);

private:	// User declarations
    int _pin;
    const PinInfo * _info;
    UnicodeString _funcName;

    // value in eng units
    int _value;

    int _adcBits;
    int _adcMax;
    std::shared_ptr<IOConvert> _converter;

    void __fastcall init(int pin, const PinInfo * info);

    void __fastcall refreshCaption();

protected:
    const char *_type;
    const char *_name;
    PinCap _mode;

public:		// User declarations
    __fastcall TIoFrame(TComponent* Owner);
    TIoFrame* __fastcall setFuncName(UnicodeString str);

    const char * __fastcall type() const { return _type; }
    const char * __fastcall name() const { return _name; }
    virtual void __fastcall digitalWrite(int v);
    virtual void __fastcall analogWrite(uint16_t v);
    virtual bool __fastcall digitalRead();
    virtual uint16_t __fastcall analogRead();
    void __fastcall setMode(PinCap mode, bool force=false);

    double __fastcall hi() const  { return _converter ? _converter->hi() : _adcMax; }
    double __fastcall lo() const  { return _converter ? _converter->lo() : 0; }

    double __fastcall value() const { return _value; }
    void __fastcall value(double d);

    AnsiString __fastcall units() const { return _converter ? _converter->units() : AnsiString("counts"); }

    TIoFrame* __fastcall adcBits(int b)
    {
        _adcBits=b;
        _adcMax= (1<<b)-1;
        return this;
    }

    TIoFrame* __fastcall setConverter(IOConvert* c);

    __property UnicodeString FunctionName { read=_funcName, write = setFuncName};
};
//---------------------------------------------------------------------------
extern PACKAGE TIoFrame *IoFrame;
//---------------------------------------------------------------------------
#endif
