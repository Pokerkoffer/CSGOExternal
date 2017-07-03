#include "stdafx.h"
#include <Hack\RECOIL.h>
namespace Hack {
	void CRECOIL::OnToggle (bool bState)
	{
	}

	CRECOIL::CRECOIL (DWORD iToggleKey) : CHack ("RECOIL", false, iToggleKey)
	{
	}

	CRECOIL::~CRECOIL ()
	{
	}

	void CRECOIL::OnTick ()
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

		Util::Vector3 vNewPunch = pLocal->GetAimPunch() * Game::CEngine::CalculatePunchReduction (vPunchReductionRecoilControl[0], vPunchReductionRecoilControl[1]);

		if (pLocal->GetShotsFired() >= 0 && pLocal->CanAttack () && Game::CEngine::GetAttack ()) {

			Util::Vector3 vAimAngle = Game::CEngine::GetViewAngle ();
			vAimAngle -= (vNewPunch - vOldPunch);
			Util::Vector3 vViewAngle = Game::CEngine::GetViewAngle ();
			Util::Vector3 vSmoothAimAngle = Game::CEngine::CalculateSmoothAngle (vViewAngle, vAimAngle, Game::CEngine::Random<float> (vSmoothRecoilControl));
			Game::CEngine::SetSendPacket (false);
			Game::CEngine::SetViewAngle (vSmoothAimAngle);
			Game::CEngine::SetSendPacket (true);
		}
		pLocal->SetVisualPunch (Util::Vector3 (0.f));

		vOldPunch = vNewPunch;
	}

	void CRECOIL::OnRender ()
	{
	}
}
