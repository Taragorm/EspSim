//---------------------------------------------------------------------------

#ifndef AnalogInEditFormH
#define AnalogInEditFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Mask.hpp>
//---------------------------------------------------------------------------
class TAnalogInEdit : public TForm
{
__published:	// IDE-managed Components
    TTrackBar *trackBar;
    TLabel *unitsLabel;
    TLabel *minLabel;
    TLabel *maxLabel;
    TEdit *edit;
    TButton *applyButton;
    TLabel *errorLabel;
    TButton *revertButton;
    void __fastcall trackBarTracking(TObject *Sender);
    void __fastcall applyButtonClick(TObject *Sender);
    void __fastcall revertButtonClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
    void __fastcall load();

protected:
    class TIoFrame* _io;
    double _lo, _hi;

public:		// User declarations
    __fastcall TAnalogInEdit(TComponent* Owner);
    void __fastcall setIo(class TIoFrame* io);
};
//---------------------------------------------------------------------------
extern PACKAGE TAnalogInEdit *AnalogInEdit;
//---------------------------------------------------------------------------
#endif
