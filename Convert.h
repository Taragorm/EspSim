//---------------------------------------------------------------------------

#ifndef ConvertH
#define ConvertH
//---------------------------------------------------------------------------
class IOConvert
{
    AnsiString _units;
public:
    IOConvert(AnsiString units) : _units(units) {}

    virtual ~IOConvert()
    {}

    AnsiString __fastcall units() { return _units; }
    virtual double __fastcall convert(double v) = 0;
    virtual double __fastcall hi() const = 0;
    virtual double __fastcall lo() const = 0;

};

//---------------------------------------------------------------------------
class Scaler : public IOConvert
{
    const double _i0,_i1,_o0,_o1;

public:
    Scaler(double i0, double i1, double o0, double o1,
            AnsiString units
            )
    :   IOConvert(units),
        _i0(i0), _i1(i1), _o0(o0), _o1(o1)
    {}

    virtual double __fastcall convert(double v) override
    {
        if(v<=_i0)
            return _o0;
        if(v>=_i1)
            return _o1;

        return (v-_i0)*(_o1-_o0)/(_i1-_i0) + _o0;
    }

    virtual double __fastcall hi() const override { return _i1; }
    virtual double __fastcall lo() const override { return _i0; }

};
//---------------------------------------------------------------------------
class Thermistor : public IOConvert
{
    const double _Rth25, _R1, _B, _VSupply, _VadcMax;
    const int _countMax;
    const bool _thermistorPullsDown;
    const double _lo, _hi;

public:
    Thermistor(
                double Rth25,
                double R1,
                double B,
                int countMax,
                bool thermistorPullsDown,
                double Vsupply = 3.3,
                double VadcMax = 3.3,
                double lo = 0.0,
                double hi = 100.0
                )
    :   IOConvert(AnsiString("C")),
        _Rth25(Rth25), _R1(R1), _B(B),
        _countMax(countMax),
        _thermistorPullsDown(thermistorPullsDown),
        _VSupply(Vsupply),
        _VadcMax(VadcMax),
        _lo(lo), _hi(hi)
    {}


    virtual double __fastcall convert(double v) override;
    virtual double __fastcall hi() const override { return _hi; }
    virtual double __fastcall lo() const override { return _lo; }

};

#endif
