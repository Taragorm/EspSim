//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "PsiBitmap.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//

static inline void ValidCtrCheck(TPsiBitmap *)
{
	new TPsiBitmap(NULL);
}
//---------------------------------------------------------------------------
__fastcall TPsiBitmap::TPsiBitmap(TComponent* Owner)
	: TControl(Owner)
{
}
//---------------------------------------------------------------------------
namespace Psibitmap
{
	void __fastcall PACKAGE Register()
	{
		TComponentClass classes[1] = {__classid(TPsiBitmap)};
		RegisterComponents(L"Samples", classes, 0);
	}
}
//---------------------------------------------------------------------------
