//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Ioshim.h"
#include <ProcDef.h>
#include <assert.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
IoShim::IoShim(const char *type, const char *name)
    : _name(name), _type(type)
{
    assert(name);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
Io::Io(ProcDef& proc)
:
    _processor(proc),
    _pins( proc.ioPins() )
{}

//---------------------------------------------------------------------------
void Io::bind(
                        TControl* comp,
                        int pin,
                        const char* name
                        )
{
    // check pin..
    _processor.assertPinOk(pin);

    if(_pins[pin] != nullptr)
        throw new Exception("Pin# occupied");

    auto label = dynamic_cast<TLabel*>(comp);
    if(label != nullptr)
    {
        _pins[pin] = new LabelShim(label, pin, name);
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------


