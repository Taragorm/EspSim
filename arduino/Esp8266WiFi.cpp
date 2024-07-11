#include "Esp8266WiFI.h"
#include "../MainUnit.h"

extern "C"
{
//------------------------------------------------------------------------------
void pinMode(pin_size_t pin, PinMode m)
{
    MainForm->pinMode(pin,m);
}
//------------------------------------------------------------------------------
void digitalWrite(pin_size_t pin, PinStatus val)
{
    MainForm->digitalWrite(pin,val);
}
//------------------------------------------------------------------------------
PinStatus digitalRead(pin_size_t pin)
{
    return MainForm->digitalRead(pin);
}
//------------------------------------------------------------------------------
void analogWrite(pin_size_t pin, analog_t val)
{
     MainForm->analogWrite(pin,val);
}
//------------------------------------------------------------------------------
analog_t analogRead(pin_size_t pin)
{
    return MainForm->analogRead(pin);
}
//------------------------------------------------------------------------------
} // extern "C"
