#pragma once
#include "stdafx.h"
namespace Remote {
	class CModule
	{
	private:
		std::string m_szModuleName;
		DWORD m_dwModuleBase;
		DWORD m_dwModuleSize;
	public:
		CModule (const std::string& szModuleName, DWORD dwModuleBase, DWORD dwModuleSize);
		CModule ();
		~CModule ();

		const std::string& GetModuleName ();
		DWORD GetModuleBase ();
		DWORD GetModuleSize ();

		void SetModuleName (const std::string& szModuleName);
		void SetModuleBase (DWORD dwModuleBase);
		void SetModuleSize (DWORD dwModuleSize);
	};
}