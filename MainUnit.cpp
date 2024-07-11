//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "WidgetDisplay.h"
#include "MainUnit.h"
#include "LogUnit.h"
#include "SimGfx.h"
#include "pages.h"
#include "ProcDef.h"
#include "IoFrameUnit.h"
#include "convert.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DiPin"
#pragma link "IoPin"
#pragma resource "*.dfm"

#define STANDARD_ENTRY_POINTS 2

#if STANDARD_ENTRY_POINTS==1
    void _setup();
    void _loop();
    #define SETUP_FUNC _setup
    #define LOOP_FUNC _loop
#elif STANDARD_ENTRY_POINTS==2
    void setup();
    void loop();
    #define SETUP_FUNC setup
    #define LOOP_FUNC loop
#endif

TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
    :   TForm(Owner) ,
        _processor(ProcDef::ESP8266)
{
    _io.reserve(_processor.ioPins());

    for(int i=0; i<_processor.ioPins(); ++i)
    {
        auto io = _processor.makeIoFrame(i, flowPanel);
       if(io != nullptr)
       {
           _io[i] = io;
            io->setMode(PinCap::NONE, /*force*/ true);
       }
    }


    //
    // Custom init
    getIoFrame(16)->setFuncName("Triac");
    getIoFrame(17)->setFuncName("ADC")
                    ->setConverter( new Thermistor(
                                    100*1000,
                                    10*1000,
                                    3950,
                                    _processor.adcCountMax(),
                                    /*th pulls down*/ false,
                                    3.3, // Vcc
                                    1.0 // Vadc
                                    ))
                    ->value(20)
                    ;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormShow(TObject *Sender)
{
    Serial.sink = &(LogForm->logMessage);

    LogForm->Show();

    // link shims and form
    SimGfxForm->gfx(&gfx_);
    gfx_.form(SimGfxForm);

    SimGfxForm->mouse(&touch_);
    touch_.form(SimGfxForm);

    SimGfxForm->Show();

    LogForm->Left 	= Left+Width+1;
    LogForm->Top 	= Top;

    SimGfxForm->Left 	= LogForm->Left + LogForm->Width+1;
    SimGfxForm->Top 	= LogForm->Top;

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
     Timer1->Enabled = false;
     LogForm->Close();
     SimGfxForm->Close();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::StartClick(TObject *Sender)
{
    psiwidget::Rotation rot;

    try
    {
#if STANDARD_ENTRY_POINTS
        SETUP_FUNC();
#else
        #error Put setup here
        //initPages();
#endif
    }
    catch(Exception & ex)
    {
        ShowMessage(ex.Message);
        return;
    }
    Timer1->Enabled = true;
    Start->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Timer1Timer(TObject *Sender)
{
    try
    {
#if STANDARD_ENTRY_POINTS
        LOOP_FUNC();
#else
        #error Put looped code here
        //display_.render();
#endif
    }
    catch(Exception& ex)
    {
        Timer1->Enabled = false;
        Start->Enabled = true;
        ShowMessage(ex.Message);
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::log(AnsiString& str)
{
    ShowMessage(str);
}
//---------------------------------------------------------------------------
TIoFrame* __fastcall TMainForm::getIoFrame(int pin)
{
    TIoFrame* ret = nullptr;

    if(pin>=0 && pin <_processor.ioPins() )
        ret = _io[pin];

    if(ret==nullptr)
        throw EInvalidOperation(AnsiString().sprintf("No Pin %d", pin));

    return ret;
}
//---------------------------------------------------------------------------
int __fastcall  TMainForm::analogRead(int pin)
{
    return getIoFrame(pin)->analogRead();
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::digitalRead(int pin)
{
    return getIoFrame(pin)->analogRead();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::analogWrite(int pin, int v)
{
  getIoFrame(pin)->analogWrite(v);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::digitalWrite(int pin, int v)
{
  getIoFrame(pin)->digitalWrite(v);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::pinMode(int pin, int mode)
{
    //getIoFrame(pin)->pinMode(mode);
}
//---------------------------------------------------------------------------

