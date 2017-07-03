#include "stdafx.h"
#include <Hack\Hack.h>
namespace Hack {
	CHack::CHack (std::string szName, bool bState, DWORD iToggleKey) : m_szName(szName), m_bState(bState), m_iToggleKey(iToggleKey)
	{
	}

	CHack::~CHack ()
	{
	}

	std::string CHack::Name ()
	{
		return this->m_szName;
	}

	bool CHack::Is ()
	{
		return this->m_bState && this->GetSignOnState() == Game::SignOnState::SIGNONSTATE_FULL;
	}

	void CHack::Toggle ()
	{
		this->m_bState = !this->m_bState;
		this->OnToggle (this->m_bState);
	}

	void CHack::Toggle (bool bState)
	{
		this->m_bState = bState;
		this->OnToggle (this->m_bState);
	}

	DWORD CHack::ToggleKey ()
	{
		return this->m_iToggleKey;
	}

	Game::SignOnState CHack::GetSignOnState ()
	{
		auto oModule = Game::CGame::GetInstance ().GetModule ("engine.dll");
		auto dwClientState = Game::CGame::GetInstance().GetProcess ().Read<int> ((Game::CGame::GetInstance ().GetProcess ().Read<DWORD> (oModule.GetModuleBase () + Dumper::CSignatureDumper::GetInstance ().FindSignature ("dwClientState"))) + Dumper::CSignatureDumper::GetInstance ().FindSignature ("dwClientState_State"));
		return (Game::SignOnState) dwClientState;
	}
}
