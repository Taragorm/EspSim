#include <Arduino.h>
#include <LiquidCrystal.h>
#include <cstdlib>
#include <iostream>
#include <windows.h>

using namespace std;



int main(int argc, char *argv[])
{
    arduino_init();
    setup();
    while(1)
    {
        loop();
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
