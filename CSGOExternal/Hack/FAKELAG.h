#pragma once
#include "stdafx.h"
#include <Hack\Hack.h>
namespace Hack {
	class CFAKELAG : public CHack
	{
		int m_iTick;

	protected:
		void OnToggle (bool bState);

	public:
		CFAKELAG (DWORD iToggleKey);
		~CFAKELAG ();

		void OnTick ();
		void OnRender ();
	};
}

