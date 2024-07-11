#include <consoleSerial.h>
ConsoleSerial Serial;
ConsoleSerial Serial1;
ConsoleSerial Serial2;
ConsoleSerial Serial3;

//------------------------------------------------------------------------------
size_t ConsoleSerial::write(uint8_t d)
{
	if(sink != nullptr)
		sink(AnsiString( (char) d));
	return 1;
};

//------------------------------------------------------------------------------
size_t ConsoleSerial::write(const uint8_t *buffer, size_t size)
{
	if(sink != nullptr)
		sink( (const char*)buffer);
	return size;
}
//------------------------------------------------------------------------------

