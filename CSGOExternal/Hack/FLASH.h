#pragma once
#include "stdafx.h"
#include <Hack\Hack.h>
namespace Hack {
	class CFLASH : public CHack
	{
	protected:
		void OnToggle (bool bState);

	public:
		CFLASH (DWORD iToggleKey);
		~CFLASH ();

		void OnTick ();
		void OnRender ();
	};
}

