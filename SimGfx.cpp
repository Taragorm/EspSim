//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SimGfx.h"
#include "GfxShim.h"
#include "Widget.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSimGfxForm *SimGfxForm;
//---------------------------------------------------------------------------
__fastcall TSimGfxForm::TSimGfxForm(TComponent* Owner)
	: 	TForm(Owner),
		_gfx( nullptr ),
		_scale(2),
		_buffer(nullptr)

{
}
//---------------------------------------------------------------------------
void _fastcall TSimGfxForm::Clear(TColor c)
{
    Image1->Canvas->Pen->Color   = c;
    Image1->Canvas->Brush->Color = c;
//    Image1->Canvas->FillRect(Image1->Canvas->ClipRect);
    Image1->Canvas->Rectangle(
            0,0,
            _panelw*_scale,
            _panelh*_scale
            );
}
//---------------------------------------------------------------------------
void __fastcall TSimGfxForm::gfx(GfxShim* gfx)
{
	_gfx  = gfx;
	if(_gfx != nullptr)
	{
		if(_gfx->getRotation() & 1)
		{
			_panelh = _gfx->width();
			_panelw = _gfx->height();
		}
		else
		{
			_panelw = _gfx->width();
			_panelh = _gfx->height();
		}
		setRotation(_gfx->getRotation());
	}

}
//---------------------------------------------------------------------------
void __fastcall TSimGfxForm::setRotation(uint8_t r)
{
    Clear(clWhite);
	if(r & 1)
	{
		resize(_panelh,_panelw);
	}
	else
	{
		resize(_panelw, _panelh);
	}
}
//---------------------------------------------------------------------------
void __fastcall TSimGfxForm::drawPixel(int16_t x, int16_t y, uint16_t color)
{
	if(x<0 || x>=_w || y <0 || y>= _h)
		return;

	auto c = Image1->Canvas;

    uint8_t r,g,b;
	psiwidget::decode565raw(color, r,g,b);
    r = (r*255)/31;
    g = (g*255)/63;
    b = (b*255)/31;
    auto cl = RGB(r,g,b);

	c->Brush->Color =  (TColor) cl;
	c->Pen->Color = (TColor) cl;
	c->Rectangle(
		x*_scale,
		y*_scale,
		(x+1)*_scale,
		(y+1)*_scale
		);
}
//---------------------------------------------------------------------------
void __fastcall TSimGfxForm::resize(uint16_t x, uint16_t y)
{
	_w = x;
	_h = y;
	if(_buffer)
	{
		delete _buffer;
		_buffer = nullptr;
	}

	_buffer = new uint32_t[x*y];
    Image1->Width = x*_scale;
    Image1->Height = y*_scale;
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------







void __fastcall TSimGfxForm::Image1MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
    if(Button != TMouseButton::mbLeft)
        return;

   _down = true;
   _seen = false;
   _xpos = X;
   _ypos = Y;
}
//---------------------------------------------------------------------------

void __fastcall TSimGfxForm::Image1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
    if(Button != TMouseButton::mbLeft)
        return;

  _down = false;
  if(!_seen)
  	_seen = true;

   _xpos = X;
   _ypos = Y;
}
//---------------------------------------------------------------------------
bool TSimGfxForm::touched()
{
    _seen = true;
    return _down;
}
//---------------------------------------------------------------------------
void TSimGfxForm::readData(  uint16_t& x, uint16_t& y, uint8_t& z)
{
    x = _xpos/_scale;
    y = _ypos/_scale;
    z = 255;
}
//---------------------------------------------------------------------------
void __fastcall TSimGfxForm::Image1MouseLeave(TObject *Sender)
{
    // we left the area, so fake an up if needed
    if(_down && _seen)
    {
	  	_down = false;
	    _seen = false;
    }
}
//---------------------------------------------------------------------------

