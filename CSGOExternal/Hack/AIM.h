#pragma once
#include "stdafx.h"
#include <Hack\Hack.h>
namespace Hack {
	class CAIM : public CHack
	{
		float flFOVAimBot = 4.f;

		Util::Vector2 vSmoothAimBot = Util::Vector2 (100.f);
		Util::Vector2 vPunchReductionAimBot[2] = {
			Util::Vector2 (2.f, 2.f),
			Util::Vector2 (2.f, 2.f)
		};

		Game::Bone eTargetBoneAimBot = Game::Bone::BONE_HEAD;

	protected:
		void OnToggle (bool bState);

	public:
		CAIM (DWORD iToggleKey);
		~CAIM ();

		void OnTick ();
		void OnRender ();
	};
}

