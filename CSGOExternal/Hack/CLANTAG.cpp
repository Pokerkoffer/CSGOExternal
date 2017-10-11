#include "stdafx.h"
#include <Hack\CLANTAG.h>
namespace Hack {
	void CCLANTAG::OnToggle (bool bState)
	{
	}

	CCLANTAG::CCLANTAG (DWORD iToggleKey) : CHack ("CLANTAG", false, iToggleKey)
	{
	}

	CCLANTAG::~CCLANTAG ()
	{
	}

	void CCLANTAG::OnTick ()
	{
		if (Game::CGlobalVars::GetInstance ()->GetTickCount () % 2 == 0) {
			Game::CEngine::SetClanTag ("FRESH MEMES\n", "FRESH MEMES\n");
		}
		else {
			Game::CEngine::SetClanTag ("", "");
		}
	}

	void CCLANTAG::OnRender ()
	{
	}
}
