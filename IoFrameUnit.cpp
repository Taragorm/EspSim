//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "IoFrameUnit.h"
#include "Convert.h"
#include "AnalogInEditForm.h"
#include "ConsoleSerial.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TIoFrame *IoFrame;
//---------------------------------------------------------------------------
__fastcall TIoFrame::TIoFrame(TComponent* Owner)
    : TFrame(Owner), _info(nullptr)
{
    unitsLabel->Caption = "";
}
//---------------------------------------------------------------------------
void __fastcall TIoFrame::init(int pin, const PinInfo * info)
{
    _pin = pin;
    _info = info;
    refreshCaption();
    this->edit->Visible = false;
}
//---------------------------------------------------------------------------
TIoFrame* __fastcall TIoFrame::setFuncName(UnicodeString str)
{
    _funcName = str;
    refreshCaption();
    return this;
}
//---------------------------------------------------------------------------
void __fastcall TIoFrame::refreshCaption()
{
    GroupBox1->Caption = AnsiString("#") + _pin + ":" + _funcName;
}
//---------------------------------------------------------------------------
void __fastcall TIoFrame::setMode(PinCap mode, bool force)
{
    if(mode == _mode && !force)
        return;

    TControl* last = nullptr;
    switch(mode)
    {
        case PinCap::NONE:
            Visible = false;
            break;

        case PinCap::AI:
            Visible = true;
            shape->Visible = false;
            unitsLabel->Visible = true;
            edit->Visible = true;
            edit->Enabled = true;
            break;

        case PinCap::DI:
            Visible = true;
            shape->Visible = true;
            shape->Enabled = true;
            unitsLabel->Visible = true;
            edit->Visible = false;
            last = unitsLabel;
            break;

        case PinCap::AO:
            Visible = true;
            shape->Visible = false;
            unitsLabel->Visible = true;
            edit->Visible = true;
            edit->Enabled = false;
            break;

        case PinCap::DO:
            Visible = true;
            shape->Visible = true;
            shape->Enabled = false;
            unitsLabel->Visible = true;
            edit->Visible = false;
            last = unitsLabel;
            break;

        default:
            // ex?
            return;
    }

    //AdjustSize();
    if(last)
        this->Width = last->Left + last->Width+10;
    _mode = mode;
}
//---------------------------------------------------------------------------
void __fastcall TIoFrame::digitalWrite(int v)
{
    setMode(PinCap::DO);
    if(_value==v)
        return;

    _value = v;
    if(v)
        shape->Brush->Color = clGreen;
    else
        shape->Brush->Color = clWhite;
}
//---------------------------------------------------------------------------
void __fastcall TIoFrame::analogWrite(uint16_t v)
{
    setMode(PinCap::AO);
    if(_value==v)
        return;

    _value = v;
    double vc = v;
    if(_converter)
    {
        vc = _converter->convert(vc);
    }

    edit->Text = FloatToStr(vc);
}
//---------------------------------------------------------------------------
bool __fastcall TIoFrame::digitalRead()
{
    setMode(PinCap::DI);
    return _value != 0;
}
//---------------------------------------------------------------------------
uint16_t __fastcall TIoFrame::analogRead()
{
    setMode(PinCap::AI);
    auto v = _value;
    if(_converter)
    {
        auto v2 = _converter->convert(v);
        //Serial.printf("%f -> %f\r\n", v, v2);
        return (int)v2;
    }
    else
    {
        return (int)v;
    }
}
//---------------------------------------------------------------------------
void __fastcall TIoFrame::shapeMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
    _value = !_value;

    if(_value)
        shape->Brush->Color = clWhite;
    else
        shape->Brush->Color = clGreen;

}
//---------------------------------------------------------------------------
TIoFrame* __fastcall TIoFrame::setConverter(IOConvert* c)
{
    _converter.reset(c);
    unitsLabel->Caption = c ? c->units() : AnsiString();
    return this;
}
//---------------------------------------------------------------------------

void __fastcall TIoFrame::editClick(TObject *Sender)
{
    if(_mode!=PinCap::AI)
        return;

    auto frm = new TAnalogInEdit(this);
    frm->setIo(this);
    frm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TIoFrame::value(double v)
{
    _value = v;
//    double vc = v;
//    if(_converter)
//    {
//        vc = _converter->convert(vc);
//    }

    edit->Text = FloatToStr(v);

}
//---------------------------------------------------------------------------

