#include "stdafx.h"
#include <Remote\Module.h>
namespace Remote {
	CModule::CModule (const std::string & szModuleName, DWORD dwModuleBase, DWORD dwModuleSize)
	{
		this->m_szModuleName = szModuleName;
		this->m_dwModuleBase = dwModuleBase;
		this->m_dwModuleSize = dwModuleSize;
	}

	CModule::CModule ()
	{
		this->m_szModuleName = "Unknown";
		this->m_dwModuleBase = (DWORD)0;
		this->m_dwModuleSize = (DWORD)0;
	}

	CModule::~CModule ()
	{
	}

	const std::string& CModule::GetModuleName ()
	{
		return this->m_szModuleName;
	}

	DWORD CModule::GetModuleBase ()
	{
		return this->m_dwModuleBase;
	}

	DWORD CModule::GetModuleSize ()
	{
		return this->m_dwModuleSize;
	}

	void CModule::SetModuleName (const std::string & szModuleName)
	{
		this->m_szModuleName = szModuleName;
	}

	void CModule::SetModuleBase (DWORD dwModuleBase)
	{
		this->m_dwModuleBase = dwModuleBase;
	}

	void CModule::SetModuleSize (DWORD dwModuleSize)
	{
		this->m_dwModuleSize = dwModuleSize;
	}
}