#pragma once
#include "stdafx.h"
#include <Hack\Hack.h>
namespace Hack {
	class CESP : public CHack
	{
	protected:
		void OnToggle (bool bState);

	public:
		CESP (DWORD iToggleKey);
		~CESP ();

		void OnTick ();
		void OnRender ();
	};
}

