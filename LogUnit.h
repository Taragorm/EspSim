//---------------------------------------------------------------------------

#ifndef LogUnitH
#define LogUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TLogForm : public TForm
{
__published:	// IDE-managed Components
	TButton *clearButton;
	TMemo *log;
	void __fastcall clearButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TLogForm(TComponent* Owner);
	void __fastcall logMessage(AnsiString str);

};
//---------------------------------------------------------------------------
extern PACKAGE TLogForm *LogForm;
//---------------------------------------------------------------------------
#endif
