#include "stdafx.h"
#include <Hack\FAKELAG.h>
namespace Hack {
	void CFAKELAG::OnToggle (bool bState)
	{
		if (!bState && !Game::CEngine::GetSendPacket ()) {
			Game::CEngine::SetSendPacket (true);
		}
		else if (bState) {
			this->m_iTick = 0;
		}
	}

	CFAKELAG::CFAKELAG (DWORD iToggleKey) : CHack ("FAKELAG", false, iToggleKey)
	{
	}

	CFAKELAG::~CFAKELAG ()
	{
	}

	void CFAKELAG::OnTick ()
	{
		Game::CEngine::SetSendPacket ((this->m_iTick = (this->m_iTick++ % 32)) % Game::CEngine::Random<int> (Util::Vector2 (2.f, 8.f)) == 0);
	}

	void CFAKELAG::OnRender ()
	{
	}
}
