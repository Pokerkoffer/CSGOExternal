#pragma once
#include "stdafx.h"
#include <Hack\SDK.h>
#include <Game\Game.h>
#include <Dumper\SignatureDumper.h>
#include <Dumper\NetVarDumper.h>
namespace Hack {
	class CHack
	{
		std::string m_szName;
		bool m_bState = false;
		DWORD m_iToggleKey = 0;

	protected:
		virtual void OnToggle (bool bState) = 0;

	public:
		CHack (std::string szName, bool bState, DWORD iToggleKey);
		virtual ~CHack ();

		virtual void OnTick () = 0;
		virtual void OnRender () = 0;

		std::string Name ();
		bool Is ();
		void Toggle ();
		void Toggle (bool bState);
		DWORD ToggleKey ();

		Game::SignOnState GetSignOnState ();
	};
}

