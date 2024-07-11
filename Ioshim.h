//---------------------------------------------------------------------------

#ifndef IoshimH
#define IoshimH

#include <stdint.h>
#include <vector>
//---------------------------------------------------------------------------
/**
    Generic base IO shim
 */
class IoShim
{
    const char *_type;
    const char *_name;

protected:
    IoShim(const char *type, const char *name);

public:
    const char * __fastcall type() const { return _type; }
    const char * __fastcall name() const { return _name; }
    virtual void __fastcall digitalWrite(int v) {}
    virtual void __fastcall analogWrite(uint16_t v) {}
    virtual bool __fastcall digitalRead(int v) { return false;}
    virtual uint16_t __fastcall analogRead(int v) {return 0;}


};
//---------------------------------------------------------------------------
class LabelShim : public IoShim
{
    TLabel* _label;

    public:
        LabelShim(TLabel* label, int pin, const char* name)
        :   IoShim("Label", name),
            _label(label)
        {}

    virtual void __fastcall digitalWrite(int v)
    { _label->Caption = v ? "ON" : "OFF"; }

    virtual void __fastcall analogWrite(int v)
    { _label->Caption = AnsiString(v); }

};
//---------------------------------------------------------------------------
class Io
{
    class ProcDef& _processor;
    std::vector<IoShim*> _pins;

public:
    Io(ProcDef& proc);

    /**
        Make a shim that can bind to the given control
     */
    void bind(
                        TControl* comp,
                        int pin,
                        const char* name
                        );
};
#endif
