#ifndef _ESP8266WIFI_H
#define _ESP8266WIFI_H

#include <stdint.h>

// Fake IO for ADC
#define A0 17

typedef uint8_t pin_size_t;
typedef uint16_t analog_t;
typedef uint16_t PinStatus;

//enum PinMode
//{
//    OUTPUT=0,
//
//    INPUT=1,
//    INPUT_PULLUP=1
//};

typedef uint8_t PinMode;

//#define OUTPUT 1
//#define INPUT 0
#define INPUT_PULLUP 0

extern "C"
{
void pinMode(pin_size_t pin, PinMode m);
void digitalWrite(pin_size_t pin, PinStatus val);
PinStatus digitalRead(pin_size_t pin);
void analogWrite(pin_size_t pin, analog_t val);
analog_t analogRead(pin_size_t pin);
}

#endif