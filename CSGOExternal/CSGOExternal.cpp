// CSGODumper.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Overlay\Overlay.h>
#include <Overlay\D3D9Overlay.h>
#include <Config\DumpConfig.h>
#include <Dumper\SignatureDumper.h>
#include <Dumper\NetVarDumper.h>
#include <Game\Game.h>
#include <Hack\Hack.h>
#include <Hack\ESP.h>
#include <Hack\BHOP.h>
#include <Hack\FLASH.h>
#include <Hack\FAKELAG.h>
#include <Hack\RECOIL.h>
#include <Hack\TRIGGER.h>
#include <Hack\AIM.h>

Overlay::CD3D9Overlay* pOverlay;

bool bHack = false;
DWORD dwPanicVirtualKey = VK_F8;

std::vector<Hack::CHack*> vHacks;
std::vector<std::thread> vThreads;

int main()
{
#ifdef NDEBUG
	HWND hConsoleWindow = GetConsoleWindow ();
	SetParent (hConsoleWindow, GetShellWindow ());
	ShowWindow (hConsoleWindow, SW_HIDE);
#endif

	Dumper::CSignatureDumper::GetInstance ().Dump ();
	Dumper::CNetVarDumper::GetInstance ().Dump ();

	vHacks.push_back (new Hack::CAIM (VK_INSERT));
	vHacks.push_back (new Hack::CRECOIL (VK_HOME));
	vHacks.push_back (new Hack::CTRIGGER (VK_PRIOR));
	vHacks.push_back (new Hack::CBHOP (VK_DELETE));
	vHacks.push_back (new Hack::CESP (VK_END));
	vHacks.push_back (new Hack::CFLASH (VK_NEXT));
	vHacks.push_back (new Hack::CFAKELAG (VK_UP));

	vThreads.push_back (std::thread ([]()
	{
		while (!bHack)
		{
			std::this_thread::sleep_for (std::chrono::milliseconds (5));

			if (Game::CGame::GetInstance ().IsKeyDown (dwPanicVirtualKey) || !Game::CGame::GetInstance ().IsGameActive())
			{
				while (Game::CGame::GetInstance ().IsKeyDown (dwPanicVirtualKey))
				{
					std::this_thread::sleep_for (std::chrono::milliseconds (1));
				}
				bHack = !bHack;
			}

			std::this_thread::sleep_for (std::chrono::milliseconds (5));
		}
	}));

	for (auto oHack : vHacks) {
		vThreads.push_back (std::thread ([](Hack::CHack* oHack) {
			while (!bHack) {
				std::this_thread::sleep_for (std::chrono::milliseconds (2));
				if (Game::CGame::GetInstance ().IsKeyDown (oHack->ToggleKey ()) && Game::CGame::GetInstance ().IsWindowActive()) {
					while (Game::CGame::GetInstance ().IsKeyDown (oHack->ToggleKey ()))
					{
						std::this_thread::sleep_for (std::chrono::milliseconds (1));
					}
					oHack->Toggle ();
				}

				if (oHack->Is ()) {
					oHack->OnTick ();
				}
			}
		}, oHack));
	}

	pOverlay = new Overlay::CD3D9Overlay ();
	pOverlay->GetSurface ()->PrepareFont ("Default", "Lucidia Consolas", 24, FW_REGULAR, 0, 0, FALSE);
	while (!pOverlay->Create (Game::CGame::GetInstance ().GetWindow ()))
	{
		std::this_thread::sleep_for (std::chrono::milliseconds (120));
	}

	pOverlay->AddToCallback ([](Overlay::IOverlay *pOverlay, std::shared_ptr< Overlay::ISurface > pSurface)
	{
		static auto defaultFont = pSurface->GetSurfaceFontData ("Default");
		if (!bHack)
		{
			pSurface->String (0, 0, "Default", 0xFFFFFFFF, "Menu: Toggles");
			auto x = 1;
			for (auto m : vHacks)
			{
				auto modRect = pSurface->CalculateString ("Default", 0xFFFFFFFF, m->Name ().c_str ());
				modRect.top += (x * defaultFont->m_iSize);
				modRect.left += 12;
				pSurface->String (12, x * defaultFont->m_iSize, "Default", m->Is () ? 0xFF00FF00 : 0xFFFF0000, m->Name ().c_str ());
				x++;
				if (m->Is ()) {
					m->OnRender ();
				}
			}
			pSurface->String (0, pOverlay->GetHeight () - defaultFont->m_iSize, "Default", 0xFFFFFFFF, "CSGO Dumper");
		}
	});

	vThreads.push_back (std::thread ([]()
	{
		while (!bHack && pOverlay->Render ())
		{
			std::this_thread::sleep_for (std::chrono::milliseconds (250));
		}
	}));

#ifndef NDEBUG
	std::cout << "LOADED" << std::endl;
#endif

	for (auto& t : vThreads)
	{
		t.join ();
	}

	while (vHacks.size () > 0)
	{
		auto x = vHacks.back ();
		delete x;
		vHacks.pop_back ();
	}

#ifndef NDEBUG
	std::cout << "Press enter to continue" << std::endl;
	while (_getch () != '\r') {
		std::this_thread::sleep_for (std::chrono::milliseconds (1));
	}
#endif

	Game::CEngine::SetSendPacket (true);

	pOverlay->Shutdown ();
	delete pOverlay;

    return 0;
}

