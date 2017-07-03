#pragma once
#include "stdafx.h"
#include <Hack\Hack.h>
namespace Hack {
	class CRECOIL : public CHack
	{
		Util::Vector2 vSmoothRecoilControl = Util::Vector2 (100.f);
		Util::Vector2 vPunchReductionRecoilControl[2] = {
			Util::Vector2 (2.f, 2.f),
			Util::Vector2 (2.f, 2.f)
		};
		Util::Vector3 vOldPunch = { 0.f, 0.f, 0.f };

	protected:
		void OnToggle (bool bState);

	public:
		CRECOIL (DWORD iToggleKey);
		~CRECOIL ();

		void OnTick ();
		void OnRender ();
	};
}

