//---------------------------------------------------------------------------

#ifndef MainUnitH
#define MainUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "DiPin.h"
#include "IoPin.h"
#include <vector>

#include "ProcDef.h"
#include "IoShim.h"
#include "IoFrameUnit.h"
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TButton *Start;
	TTimer *Timer1;
    TGroupBox *GroupBox1;
    TScrollBox *ScrollBox1;
    TFlowPanel *flowPanel;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall StartClick(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
private:    // User declarations
    ProcDef _processor;
    std::vector<TIoFrame*> _io;
protected:
    TIoFrame* __fastcall getIoFrame(int pin);

public: // User declarations
    __fastcall TMainForm(TComponent* Owner);


    //
    // Standard I/O access
    int __fastcall  analogRead(int pin);
    bool __fastcall digitalRead(int pin);
    void __fastcall analogWrite(int pin, int v);
    void __fastcall digitalWrite(int pin, int v);
    void __fastcall pinMode(int pin, int mode);

    void __fastcall log(AnsiString& str);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
