#include "stdafx.h"
#include <Hack\ESP.h>
namespace Hack {
	void CESP::OnToggle (bool bState)
	{
	}

	CESP::CESP (DWORD iToggleKey) : CHack ("ESP", false, iToggleKey)
	{
	}

	CESP::~CESP ()
	{
	}

	void CESP::OnTick ()
	{
		Game::CPlayer* pLocal = Game::CPlayer::GetLocalPlayer ();

		if (!pLocal)
			return;

		if (pLocal->IsDead () || pLocal->IsDormant ())
			return;

		Game::CGlowObjectManager* pGlowObjectManager = Game::CGlowObjectManager::GetInstance ();

		for (int i = 0; i < pGlowObjectManager->GetGlowObjectCount (); i++) {
			Game::CGlowObject* pGlowObject = pGlowObjectManager->GetGlowObject (i);
			if (pGlowObject) {
				Game::CBase* pEntity = pGlowObject->GetEntity ();
				if (pEntity->GetID () == Game::CCSPLAYER) {
					Game::CPlayer* pPlayer = (Game::CPlayer*)pEntity;
					if (!pPlayer)
						continue;

					if (pPlayer->IsDead () || pPlayer->IsDormant ())
						continue;

					Util::Vector4 vColor = Util::Vector4 (0.f);

					if (pPlayer->GetTeam () == Game::TEAM_COUNTER_TERRORISTS) {
						vColor += Util::Vector4 (float (144.f / 255.f), float (154.f / 255.f), float (221.f / 255.f), 0.75f);
					}
					else if (pPlayer->GetTeam () == Game::TEAM_TERRORISTS) {
						vColor += Util::Vector4 (float (223.f / 255.f), float (175.f / 255.f), float (86.f / 255.f), 0.75f);
					}

					if (pLocal->GetTeam () != pPlayer->GetTeam ()) {
						vColor = Util::CColorUtil::HSV2RGB ({ (float)std::floor ((pPlayer->GetHealth ()) * 120 / 100), 1.f, 1.f, 0.f }) + Util::Vector4 (0.f, 0.f, 0.f, 1.f);
						if (pLocal->GetInCrosshair () == pPlayer->GetIndex ()) {
							vColor = Util::Vector4 (1.f);
							auto flDistance = pLocal->GetPosition ().Distance (pPlayer->GetPosition ());
							if (flDistance < 20.f) {
								pGlowObject->SetGlowStyle (1);
							}
							else {
								pGlowObject->SetGlowStyle (2);
							}
						}
					}
					else {

						switch (Game::CPlayerResource::GetInstance ()->GetCompetitiveTeammateColor (pPlayer->GetIndex ()))
						{
						case Game::COMP_COLOR_YELLOW:
						{
							vColor = Util::Vector4 (1.f, 1.f, 0.f, 0.75f);
							break;
						}
						case Game::COMP_COLOR_PURPLE:
						{
							vColor = Util::Vector4 (1.f, 0.f, 1.f, 0.75f);
							break;
						}
						case Game::COMP_COLOR_GREEN:
						{
							vColor = Util::Vector4 (0.f, 1.f, 0.f, 0.75f);
							break;
						}
						case Game::COMP_COLOR_BLUE:
						{
							vColor = Util::Vector4 (0.f, 0.f, 1.f, 0.75f);
							break;
						}
						case Game::COMP_COLOR_ORANGE:
						{
							vColor = Util::Vector4 (1.f, (69.f / 255.f), 0.f, 0.75f);
							break;
						}
						}
					}

					pGlowObject->SetColor (vColor);
					pGlowObject->SetVelocity (0.f);
					pGlowObject->SetRenderWhenOccluded (true);
					pGlowObject->SetRenderWhenUnoccluded (false);
				}
			}
		}
	}

	void CESP::OnRender ()
	{
	}
}
