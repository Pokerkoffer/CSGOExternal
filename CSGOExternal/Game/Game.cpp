#include "stdafx.h"
#include <Game\Game.h>
namespace Game {
	CGame::CGame ()
	{
		this->m_pProcess = new Remote::CProcess ("csgo.exe", PROCESS_ALL_ACCESS);
		this->m_pModules = new std::map<std::string, Remote::CModule*>();
		if (!this->Attach ()) {
			throw std::exception ("CAttach failed");
		}
	}

	CGame::~CGame ()
	{
		this->Detach ();
		for (auto mods : *this->m_pModules) {
			delete mods.second;
		}
		this->m_pModules->clear ();

		delete this->m_pModules;
		delete this->m_pProcess;
	}

	bool CGame::Attach ()
	{
		while (!this->m_pProcess->Attach ())
		{
			std::this_thread::sleep_for (std::chrono::milliseconds (120));
		}

		for (auto &oModule : *this->m_pModules) {
			while (!this->m_pProcess->GetModule (*oModule.second))
			{
				std::this_thread::sleep_for (std::chrono::milliseconds (120));
			}
		}

		while (!this->m_hWindow)
		{
			this->m_hWindow = FindWindow ("Valve001", NULL);
			std::this_thread::sleep_for (std::chrono::milliseconds (120));
		}

		char tempWindowTitle[256];
		GetWindowText (this->m_hWindow, tempWindowTitle, sizeof (tempWindowTitle));
		this->m_szWindowTitle = std::string (tempWindowTitle);

		char tempExecutablePath[MAX_PATH];
		GetModuleFileName (NULL, tempExecutablePath, sizeof (tempExecutablePath));
		std::string::size_type tempExecutablePathFileNamePosition = std::string (tempExecutablePath).find_last_of ("\\/");
		this->m_szExecutablePath = std::string (tempExecutablePath).substr (0, tempExecutablePathFileNamePosition);

		return true;
	}

	void CGame::Detach ()
	{
		this->m_pProcess->Detach ();
	}

	std::string& CGame::GetExecutablePath ()
	{
		return this->m_szExecutablePath;
	}

	HWND CGame::GetWindow ()
	{
		return this->m_hWindow;
	}

	std::string& CGame::GetWindowTitle ()
	{
		return this->m_szWindowTitle;
	}

	Remote::CProcess& CGame::GetProcess ()
	{
		return *this->m_pProcess;
	}

	Remote::CModule& CGame::GetModule (std::string szModuleName)
	{
		if (this->m_pModules->find (szModuleName) != this->m_pModules->end ()) {
			return *this->m_pModules->at (szModuleName);
		}
		else {
			Remote::CModule *oModule = new Remote::CModule (szModuleName, 0, 0);
			while (!this->m_pProcess->GetModule (*oModule))
			{
				std::this_thread::sleep_for (std::chrono::milliseconds (120));
			}

			this->m_pModules->insert (std::make_pair (szModuleName, oModule));

			return *oModule;
		}
	}

	bool CGame::IsWindowActive ()
	{
		return (GetForegroundWindow () == this->m_hWindow);
	}

	bool CGame::IsGameActive ()
	{
		return WaitForSingleObject (this->m_pProcess->GetProcessHandle (), 0) == WAIT_TIMEOUT;
	}

	void CGame::SendKey (DWORD dwKey, int iDelayMillis)
	{
		SendMessage (this->m_hWindow, WM_KEYDOWN, (int)dwKey, 0x00000001 | (LPARAM)(MapVirtualKey ((int)dwKey, 0) << 16));
		std::this_thread::sleep_for (std::chrono::milliseconds (iDelayMillis));
		SendMessage (this->m_hWindow, WM_KEYUP, (int)dwKey, 0x00000001 | (LPARAM)(MapVirtualKey ((int)dwKey, 0) << 16));
	}

	bool CGame::IsKeyDown (DWORD dwKey)
	{
		return (GetAsyncKeyState ((int)dwKey) & 0x8000) != 0;
	}

	bool CGame::IsKeyUp (DWORD dwKey)
	{
		return (GetAsyncKeyState ((int)dwKey) & 0x0001) != 0;
	}

}