#pragma once
#include "stdafx.h"
#include <Hack\Hack.h>
namespace Hack {
	class CCLANTAG : public CHack
	{
	protected:
		void OnToggle (bool bState);

	public:
		CCLANTAG (DWORD iToggleKey);
		~CCLANTAG ();

		void OnTick ();
		void OnRender ();
	};
}

