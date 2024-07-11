//---------------------------------------------------------------------------

#ifndef GfxShimH
#define GfxShimH
#include <Adafruit_GFX.h>
#include <WidgetTypes.h>
#include "ITouch.h"
//---------------------------------------------------------------------------
class TSimGfxForm;
//---------------------------------------------------------------------------
/**
  Make a shim class that punts calls to the associated form
 */
class GfxShim : public Adafruit_GFX
{
    typedef Adafruit_GFX base;

	const int _x;
	const int _y;
	TSimGfxForm* _form;

public:
	GfxShim(int x, int y)
		: Adafruit_GFX(x,y),
		_x(x), _y(y)
	{
	}

	void __fastcall form(TSimGfxForm* form) { _form = form; }

	virtual void drawPixel(int16_t x, int16_t y, uint16_t color) override;
	virtual void setRotation(uint8_t r) override;

    void begin(int freq=0) {}
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
/**
    Make the mouse look like a touch device
 */
class MouseShim : public psiwidget::ITouch
{
    int _x, _y;
	TSimGfxForm* _form;

    public:
		void __fastcall form(TSimGfxForm* form) { _form = form; }

        virtual void init() override {}
        virtual void rotation(psiwidget::Rotation rot) override {}
        virtual void readData(  uint16_t& x, uint16_t& y, uint8_t& z) override;
        virtual bool firstTouch() override;
        virtual bool touched() override;
};
#endif
