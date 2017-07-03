#include "stdafx.h"
#include <Hack\TRIGGER.h>
namespace Hack {
	void CTRIGGER::OnToggle (bool bState)
	{
	}

	CTRIGGER::CTRIGGER (DWORD iToggleKey) : CHack ("TRIGGER", false, iToggleKey)
	{
	}

	CTRIGGER::~CTRIGGER ()
	{
	}

	void CTRIGGER::OnTick ()
	{
		Game::CPlayer* pLocal = Game::CPlayer::GetLocalPlayer ();

		if (!pLocal)
			return;

		if (pLocal->IsDead () || pLocal->IsDormant ())
			return;

		Game::CWeapon* pWeapon = pLocal->GetCurrentWeapon ();

		if (!pWeapon)
			return;

		if (pWeapon->GetClip () <= 0)
			return;

		int iPlayer = pLocal->GetInCrosshair ();
		Game::CPlayer* pPlayer = Game::CPlayer::GetPlayer (iPlayer);

		if (!pPlayer)
			return;

		if (
			iPlayer > -1 && iPlayer < Game::CGlobalVars::GetInstance()->GetMaxClients() &&
			pLocal->GetTeam() != pPlayer->GetTeam() &&
			!pPlayer->IsDead() &&
			!pPlayer->IsDormant () &&
			pLocal->CanAttack() &&
			!Game::CEngine::GetAttack())
		{
			if (Game::CEngine::GetAttack ())
			{
				Game::CEngine::SetAttack (false);
			}
			Game::CEngine::SetSendPacket (false);
			Game::CEngine::Attack ();
			Game::CEngine::SetSendPacket (true);
		}
	}

	void CTRIGGER::OnRender ()
	{
	}
}
