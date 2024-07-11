
#ifndef consoleSerial_h
#define consoleSerial_h

#include <Arduino.h>
#include <iostream>

class ConsoleSerial : public Stream
{
  public:
	ConsoleSerial(){};
    void begin(unsigned long){};
    void end(){};
    virtual int available(void){return 0;};
    virtual int peek(void){return 0;};
	virtual int read(void){return 0;};
    virtual void flush(void){return;};
	virtual size_t write(uint8_t d);
	virtual size_t write(const uint8_t *buffer, size_t size);

	void (__closure * __fastcall sink) (AnsiString str);

	};


  extern ConsoleSerial Serial;
  extern ConsoleSerial Serial1;
  extern ConsoleSerial Serial2;
  extern ConsoleSerial Serial3;

#endif
