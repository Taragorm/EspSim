//---------------------------------------------------------------------------

#pragma hdrstop

#include "GfxShim.h"
#include "SimGfx.h"
#include <winuser.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)

void GfxShim::drawPixel(int16_t x, int16_t y, uint16_t color)
{
	if(_form != nullptr)
		_form->drawPixel(x,y,color);
}
//---------------------------------------------------------------------------
void GfxShim::setRotation(uint8_t r)
{
    base::setRotation(r);
	if(_form != nullptr)
		_form->setRotation(r);

}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void MouseShim::readData(  uint16_t& x, uint16_t& y, uint8_t& z)
{
    _form->readData(x,y,z);
}
//---------------------------------------------------------------------------
bool MouseShim::firstTouch()
{
    return _form->touched();
}
//---------------------------------------------------------------------------
bool MouseShim::touched()
{
    return _form->touched();
}
//---------------------------------------------------------------------------

