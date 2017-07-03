#include "stdafx.h"
#include <Hack\BHOP.h>
namespace Hack {
	void CBHOP::OnToggle (bool bState)
	{
	}

	CBHOP::CBHOP (DWORD iToggleKey) : CHack("BHOP", false, iToggleKey)
	{
	}

	CBHOP::~CBHOP ()
	{
	}

	void CBHOP::OnTick ()
	{
		Game::CPlayer* pLocal = Game::CPlayer::GetLocalPlayer ();

		if (!pLocal)
			return;

		if (pLocal->IsDead () || pLocal->IsDormant ())
			return;

		if (pLocal->GetVelocity ().Length () <= 0.f)
			return;

		while (Game::CGame::GetInstance ().IsKeyDown (VK_SPACE) && Game::CGame::GetInstance().IsWindowActive()) {

			if (Game::CEngine::GetJump ()) {
				Game::CEngine::SetJump (false);
			}

			if (pLocal->GetFlags () & (FL_ONGROUND | FL_PARTIALGROUND)) {
				Game::CEngine::Jump ();
			}
		}
	}

	void CBHOP::OnRender ()
	{
	}
}
