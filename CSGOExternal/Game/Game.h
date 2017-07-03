#pragma once
#include "stdafx.h"
#include <Remote\Process.h>
namespace Game {
	class CGame
	{
		std::string m_szExecutablePath;

		HWND m_hWindow;
		std::string m_szWindowTitle;

		Remote::CProcess* m_pProcess;
		std::map<std::string, Remote::CModule*>* m_pModules;

		CGame ();

	public:
		~CGame ();

		static CGame& GetInstance () {
			static CGame pInstance;
			return pInstance;
		}

		CGame (CGame const& oGame) = delete;
		void operator=(CGame const& oGame) = delete;

		bool Attach ();
		void Detach ();

		std::string& GetExecutablePath ();

		HWND GetWindow ();
		std::string& GetWindowTitle ();

		Remote::CProcess& GetProcess ();
		Remote::CModule& GetModule (std::string szModuleName);

		bool IsWindowActive ();
		bool IsGameActive ();

		void SendKey (DWORD dwKey, int iDelayMillis);
		bool IsKeyDown (DWORD dwKey);
		bool IsKeyUp (DWORD dwKey);
	};
}