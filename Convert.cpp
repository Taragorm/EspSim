//---------------------------------------------------------------------------

#pragma hdrstop

#include "Convert.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
/*

Vsupply--
        |
       | |
       | | Rth
        |
        |-- Vth
        |
       | |
       | | R1
        |
0V-------

"Normal" arrangement, Thermistor pulls up.

*/
double __fastcall Thermistor::convert(double v)
{
    auto r = _Rth25 * exp(
            _B*(1.0/(273+v)-1.0/(273+25))
            );

    auto vth = _VSupply * _R1 /(_R1+r);

    if(_thermistorPullsDown)
        vth = _VSupply - vth;

    auto counts = (int)(vth * _countMax / _VadcMax +0.5);

    if(counts<0)
        counts = 0;
    else if (counts>_countMax)
        counts = _countMax;

    return counts;
}
