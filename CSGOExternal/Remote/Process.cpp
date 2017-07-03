#include "stdafx.h"
#include <Remote\Process.h>
namespace Remote {

	void CProcess::CompilePattern (const std::string& szSignature, std::string & szCompiledSignature, std::string & szCompiledMask)
	{
		std::stringstream szStringStream (szSignature);
		std::istream_iterator<std::string> szStreamBegin (szStringStream);
		std::istream_iterator<std::string> szStreamEnd;
		std::vector<std::string> vSzSignature (szStreamBegin, szStreamEnd);
		for (auto &szStr : vSzSignature)
		{
			if (!szStr.compare ("?"))
			{
				szCompiledSignature.append (1, '\0');
				szCompiledMask.append ("?");
			}
			else
			{
				szCompiledSignature.append (1, (char)std::stoi (szStr, 0, 16));
				szCompiledMask.append ("x");
			}
		}
	}

	bool CProcess::DataCompare (const BYTE* pData, const BYTE* pMask, const char* pszMask)
	{
		for (; *pszMask; ++pszMask, ++pData, ++pMask)
		{
			if (*pszMask == 'x' && *pData != *pMask)
			{
				return false;
			}
		}

		return (*pszMask == NULL);
	}

	CProcess::CProcess (const std::string& szProcessName, DWORD dwProcessRights = PROCESS_ALL_ACCESS)
	{
		this->m_szProcessName = szProcessName;
		this->m_dwProcessRights = dwProcessRights;
	}

	CProcess::~CProcess ()
	{
	}

	const std::string& CProcess::GetProcessName ()
	{
		return this->m_szProcessName;
	}

	DWORD CProcess::GetProcessID ()
	{
		return this->m_dwProcessID;
	}

	HANDLE CProcess::GetProcessHandle ()
	{
		return this->m_hProcess;
	}

	bool CProcess::IsAttached ()
	{
		return this->m_bAttached;
	}

	bool CProcess::Attach ()
	{
		HANDLE handle = CreateToolhelp32Snapshot (TH32CS_SNAPPROCESS, NULL);
		PROCESSENTRY32 entry;
		entry.dwSize = sizeof (entry);

		do
			if (!strcmp (entry.szExeFile, this->m_szProcessName.c_str ()))
			{
				this->m_dwProcessID = entry.th32ProcessID;
				CloseHandle (handle);

				this->m_hProcess = OpenProcess ((DWORD)this->m_dwProcessRights, false, (DWORD)this->m_dwProcessID);

				this->m_bAttached = true;

				return true;
			}
		while (Process32Next (handle, &entry));

		return false;
	}

	void CProcess::Detach ()
	{
		this->m_bAttached = false;
		CloseHandle (this->m_hProcess);
	}

	bool CProcess::GetModule (CModule& oModule)
	{
		HANDLE module = CreateToolhelp32Snapshot (TH32CS_SNAPMODULE, (DWORD)m_dwProcessID);
		MODULEENTRY32 mEntry;
		mEntry.dwSize = sizeof (mEntry);

		do
		{
			if (!strcmp (mEntry.szModule, (LPSTR)(oModule.GetModuleName ().c_str ())))
			{
				CloseHandle (module);
				oModule.SetModuleBase ((DWORD)mEntry.hModule);
				oModule.SetModuleSize (mEntry.modBaseSize);
				return true;
			}
		} while (Module32Next (module, &mEntry));
		oModule.SetModuleBase ((DWORD)0);
		oModule.SetModuleSize ((DWORD)0);
		return false;
	}

	DWORD CProcess::FindPattern (CModule& oModule, const std::string& szSignature)
	{
		std::string szCompiledSignature = "";
		std::string szCompiledMask = "";
		this->CompilePattern (szSignature, szCompiledSignature, szCompiledMask);

		const char* szSig = szCompiledSignature.c_str ();
		const char* szMask = szCompiledMask.c_str ();

		BYTE* pData = new BYTE[oModule.GetModuleSize ()];
		SIZE_T nBytesRead;

		if (!ReadProcessMemory (this->m_hProcess, (LPVOID)oModule.GetModuleBase (), pData, oModule.GetModuleSize (), &nBytesRead))
		{
			delete pData;
			return NULL;
		}

		for (DWORD i = 0; i < oModule.GetModuleSize (); i++)
		{
			if (this->DataCompare ((const BYTE*)(pData + i), (const BYTE*)szSig, szMask))
			{
				delete pData;
				return oModule.GetModuleBase () + i;
			}
		}

		delete pData;
		return NULL;
	}

	DWORD CProcess::FindPattern (CModule& oModule, const std::string & szSignature, int iOptions, int iExtra, int iOffset)
	{
		DWORD result = this->FindPattern (oModule, szSignature);

		if (iOptions & eRead) {
			result = this->Read<DWORD> (result + iExtra);
		}
		else {
			result = result + iExtra;
		}

		if (iOptions & eSubtract) {
			result = result - oModule.GetModuleBase ();
		}

		result = result + iOffset;

		return result;
	}
}