//---------------------------------------------------------------------------

#ifndef ProcDefH
#define ProcDefH
//---------------------------------------------------------------------------
enum class PinCap
{
    NONE=0,
    AI=1,
    DI=2,
    AO=4,
    DO=8,
    Ax=5,
    Dx=10,
    xI=3,
    xO=12,
    ALL=0x0f
};
DEFINE_ENUM_FLAG_OPERATORS(PinCap)
//---------------------------------------------------------------------------
struct PinInfo
{
    PinCap caps;
    int8_t adc1channel;
    int8_t adc2channel;
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class ProcDef
{
    const int _ioPins;
    const int _pwmChannels;
    const char *_name;
    const PinInfo* const _pinInfo;
    const int _adcBits;
    const double _adcVolts;

public:

    int ioPins() const { return _ioPins; }
    int pwmChannels() const { return _pwmChannels; }
    int adcBits() const { return _adcBits; }
    int adcCountMax() const { return ( (1<<(_adcBits)) -1); }
    const char* name() const { return _name; }
    virtual void assertPinOk(int pin);
    virtual class TIoFrame* makeIoFrame(int pin, TWinControl* owner);
    //----------------------------------------------------
    ProcDef(
                const char* name,
                int pins,
                int channels,
                int adcBits,
                double adcVolts,
                const PinInfo* const info
                )
        :
            _name(name),
            _ioPins(pins),
            _pwmChannels(channels),
            _adcBits(adcBits),
            _adcVolts(adcVolts),
            _pinInfo(info)
    {}
    //----------------------------------------------------


    static ProcDef ESP8266;
    static ProcDef ESP32;

};
#endif
