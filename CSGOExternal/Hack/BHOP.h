#pragma once
#include "stdafx.h"
#include <Hack\Hack.h>
namespace Hack {
	class CBHOP : public CHack
	{
	protected:
		void OnToggle (bool bState);

	public:
		CBHOP (DWORD iToggleKey);
		~CBHOP ();

		void OnTick ();
		void OnRender ();
	};
}

