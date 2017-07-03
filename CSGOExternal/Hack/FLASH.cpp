#include "stdafx.h"
#include <Hack\FLASH.h>
namespace Hack {
	void CFLASH::OnToggle (bool bState)
	{
	}

	CFLASH::CFLASH (DWORD iToggleKey) : CHack ("FLASH", false , iToggleKey)
	{
	}

	CFLASH::~CFLASH ()
	{
	}

	void CFLASH::OnTick ()
	{
		Game::CPlayer* pLocal = Game::CPlayer::GetLocalPlayer ();

		if (!pLocal)
			return;

		if (pLocal->IsDead () || pLocal->IsDormant ())
			return;

		if (pLocal->GetVelocity ().Length () <= 0.f)
			return;

		if (pLocal->GetFlashDuration() > 0.f)
		{
			pLocal->SetFlashDuration(0.f);
		}
	}

	void CFLASH::OnRender ()
	{
	}
}
