#include <Arduino.h>

// The st and ft and li are used to set up start of execution, ft2 and li2 are used to do microsecond and millis
SYSTEMTIME st;
FILETIME ft1, ft2; // File time has unit of 100ns interval
LARGE_INTEGER li1, li2;    

void arduino_init(void)
{
    // Set up the ft as the start of the execution
    GetSystemTime(&st);
    SystemTimeToFileTime(&st, &ft1);
    li1.LowPart = ft1.dwLowDateTime;
    li1.HighPart = ft1.dwHighDateTime;
}

unsigned long millis(void)
{
    GetSystemTime(&st);
    SystemTimeToFileTime(&st, &ft2);
    li2.LowPart = ft2.dwLowDateTime;
    li2.HighPart = ft2.dwHighDateTime;
    return ((li2.LowPart-li1.LowPart)/10000);
}
unsigned long micros(void)
{
    GetSystemTime(&st);
    SystemTimeToFileTime(&st, &ft2);
    li2.LowPart = ft2.dwLowDateTime;
    li2.HighPart = ft2.dwHighDateTime;
    return ((li2.LowPart-li1.LowPart)/10);
}
