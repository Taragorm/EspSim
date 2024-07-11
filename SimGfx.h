//---------------------------------------------------------------------------

#ifndef SimGfxH
#define SimGfxH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class GfxShim;
class MouseShim;
class ITouch;
class Adafruit_GFX;

class TSimGfxForm : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall Image1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall Image1MouseLeave(TObject *Sender);

private:	// User declarations
	GfxShim* _gfx;
    MouseShim* _mouse;

	uint16_t _scale;
	uint16_t _panelw;
	uint16_t _panelh;
	uint16_t _w;
	uint16_t _h;
	uint32_t* _buffer;

    bool _down;
    bool _seen;
    uint16_t _xpos, _ypos;

    void _fastcall Clear(TColor c);
public:		// User declarations
	__fastcall TSimGfxForm(TComponent* Owner);
	void __fastcall resize(uint16_t x, uint16_t y);

	GfxShim& gfx() const { return *_gfx; }
	void __fastcall gfx(GfxShim* gfx);
	void __fastcall drawPixel(int16_t x, int16_t y, uint16_t color);
	void __fastcall setRotation(uint8_t r);

	void __fastcall mouse(MouseShim* m) { _mouse = m; }

    bool touched();
    void readData(  uint16_t& x, uint16_t& y, uint8_t& z) ;
};
//---------------------------------------------------------------------------
extern PACKAGE TSimGfxForm *SimGfxForm;
//---------------------------------------------------------------------------
#endif
