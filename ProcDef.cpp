//---------------------------------------------------------------------------

#pragma hdrstop

#include "ProcDef.h"
#include "IoFrameUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

static const PinInfo esp32PinInfo_[]
{
    { PinCap::ALL }, // gpi0
    { PinCap::ALL }, // gpi1
    { PinCap::ALL }, // gpi2
    { PinCap::ALL }, // gpi3
    { PinCap::ALL }, // gpi4
    { PinCap::ALL }, // gpi5
    { PinCap::NONE }, // gpi6
    { PinCap::NONE }, // gpi7
    { PinCap::NONE }, // gpi8
    { PinCap::NONE }, // gpi9
    { PinCap::NONE }, // gpi10
    { PinCap::NONE }, // gpi11
    { PinCap::ALL }, // gpi12
    { PinCap::ALL }, // gpi13
    { PinCap::ALL }, // gpi14
    { PinCap::ALL }, // gpi15
    { PinCap::ALL }, // gpi16
    { PinCap::ALL }, // gpi17
    { PinCap::ALL }, // gpi18
    { PinCap::ALL }, // gpi19
    { PinCap::NONE }, // gpi20
    { PinCap::ALL }, // gpi21
    { PinCap::ALL }, // gpi22
    { PinCap::ALL }, // gpi23
    { PinCap::NONE }, // gpi24
    { PinCap::ALL }, // gpi25
    { PinCap::ALL }, // gpi26
    { PinCap::ALL }, // gpi27
    { PinCap::NONE }, // gpi28
    { PinCap::NONE }, // gpi29
    { PinCap::NONE }, // gpi30
    { PinCap::NONE }, // gpi31
    { PinCap::ALL }, // gpi32
    { PinCap::ALL }, // gpi33
    { PinCap::xI }, // gpi34
    { PinCap::xI }, // gpi35
    { PinCap::xI }, // gpi36
    { PinCap::NONE }, // gpi37
    { PinCap::NONE }, // gpi38
    { PinCap::xI }, // gpi39
};

ProcDef ProcDef::ESP32{
        "ESP32",
        40,     // pins
        16,     // PWM
        12,     // ADC bits
        3.3,    // ADC Volts
        esp32PinInfo_
        };

static const PinInfo esp8266PinInfo_[]
{
    { PinCap::Dx|PinCap::AO },     // gpi0
    { PinCap::Dx|PinCap::AO },     // gpi1
    { PinCap::Dx|PinCap::AO },     // gpi2
    { PinCap::Dx|PinCap::AO },     // gpi3
    { PinCap::Dx|PinCap::AO },     // gpi4
    { PinCap::Dx|PinCap::AO },     // gpi5
    { PinCap::NONE },   // gpi6
    { PinCap::NONE },   // gpi7
    { PinCap::NONE },   // gpi8
    { PinCap::NONE },   // gpi9
    { PinCap::NONE },   // gpi10
    { PinCap::NONE },   // gpi11
    { PinCap::Dx|PinCap::AO },     // gpi12
    { PinCap::Dx|PinCap::AO },     // gpi13
    { PinCap::NONE },   // gpi14
    { PinCap::NONE },   // gpi15
    { PinCap::Dx },    // gpi16
    { PinCap::AI }     // FAKE - ADC0
};

ProcDef ProcDef::ESP8266{
        "ESP32",
        18, // pins
        0,  // pwm chan
        10, // adc bits
        1.0,// adc Volts
        esp8266PinInfo_
        };

//---------------------------------------------------------------------------
void ProcDef::assertPinOk(int pin)
{
    if(pin <0 || pin >= _ioPins)
        throw new Exception(AnsiString()
            .sprintf("Pin# %d out of range 0..%d", pin, _ioPins-1));
}
//---------------------------------------------------------------------------
TIoFrame* ProcDef::makeIoFrame(int pin, TWinControl* owner)
{
    if( pin <0 || pin >= _ioPins )
        return nullptr; // by defn, not existing

    auto info = _pinInfo[pin];
    if((info.caps & PinCap::ALL) == PinCap::NONE)
        return nullptr;

    auto iof = new TIoFrame(owner);
    iof->Name = AnsiString("GPIO") + pin;
    iof->Parent = owner;
    iof->init(pin, &info);
    if( (info.caps & PinCap::AI) == PinCap::AI)
        iof->adcBits(_adcBits);

    return iof;
}
//---------------------------------------------------------------------------

