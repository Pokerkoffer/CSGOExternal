#include "stdafx.h"
#include <Hack\AIM.h>
namespace Hack {
	void CAIM::OnToggle (bool bState)
	{
	}

	CAIM::CAIM (DWORD iToggleKey) : CHack ("AIM", false, iToggleKey)
	{
	}

	CAIM::~CAIM ()
	{
	}

	void CAIM::OnTick ()
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

		for (int i = 0; i < Game::CGlobalVars::GetInstance ()->GetMaxClients (); i++) {

			if (!pLocal->CanAttack ()) {
				continue;
			}

			auto pPlayer = Game::CPlayer::GetPlayer (i);

			if (pPlayer->IsDead () || pPlayer->IsDormant ()) {
				continue;
			}

			if (pLocal->GetTeam () == pPlayer->GetTeam ()) {
				continue;
			}

			float flFOV = 0.f;
			float flDistance = 0.f;

			Util::Vector3 vEyePos = pLocal->GetEyePosition ();
			Util::Vector3 vTargetPos = pPlayer->GetBonePosition (eTargetBoneAimBot);

			if (Game::CEngine::IsInFOV (vEyePos, vTargetPos, flFOVAimBot, flFOV) &&
				Game::CEngine::RayTrace (vTargetPos - Util::Vector3 (flFOVAimBot), vTargetPos + Util::Vector3 (flFOVAimBot), flDistance)) {
				Util::Vector3 vAimAngle = Game::CEngine::CalculateAngle (vEyePos, vTargetPos);
				vAimAngle -= (pLocal->GetAimPunch () * Game::CEngine::CalculatePunchReduction (vPunchReductionAimBot[0], vPunchReductionAimBot[1]));
				Util::Vector3 vViewAngle = Game::CEngine::GetViewAngle ();
				Util::Vector3 vSmoothAimAngle = Game::CEngine::CalculateSmoothAngle (vViewAngle, vAimAngle, Game::CEngine::Random<float> (vSmoothAimBot));
				Game::CEngine::SetSendPacket (false);
				Game::CEngine::SetViewAngle (vSmoothAimAngle);
				Game::CEngine::SetSendPacket (true);
			}
		}
	}

	void CAIM::OnRender ()
	{
	}
}
