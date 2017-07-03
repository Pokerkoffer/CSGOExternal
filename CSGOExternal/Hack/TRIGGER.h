#pragma once
#include "stdafx.h"
#include <Hack\Hack.h>
namespace Hack {
	class CTRIGGER : public CHack
	{
	protected:
		void OnToggle (bool bState);

	public:
		CTRIGGER (DWORD iToggleKey);
		~CTRIGGER ();

		void OnTick ();
		void OnRender ();
	};
}

