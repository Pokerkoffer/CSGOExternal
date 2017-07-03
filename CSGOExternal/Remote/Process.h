#pragma once
#include "stdafx.h"
#include <Remote\Module.h>
namespace Remote {

	enum CFindOptions {
		eNone = 0,
		eRead = 1,
		eSubtract = 2,
		eMax
	};

	class CProcess
	{
	private:


		HANDLE m_hProcess;
		DWORD m_dwProcessID;
		std::string m_szProcessName;
		bool m_bAttached;

		DWORD m_dwProcessRights;

		bool DataCompare (const BYTE* pData, const BYTE* pMask, const char* pszMask);

		void CompilePattern (const std::string& szSignature, std::string& szCompiledSignature, std::string& szCompiledMask);

	public:

		CProcess (const std::string& szProcessName, DWORD dwProcessRights);
		~CProcess ();

		const std::string& GetProcessName ();
		DWORD GetProcessID ();
		HANDLE GetProcessHandle ();

		bool IsAttached ();

		bool Attach ();
		void Detach ();

		bool GetModule (CModule& oModule);

		DWORD FindPattern (CModule& oModule, const std::string& szSignature);
		DWORD FindPattern (CModule& oModule, const std::string & szSignature, int iOptions, int iExtra, int iOffset);

		template <typename _Ty>
		BOOL Read (DWORD dwAddress, _Ty pData, SIZE_T pSize) {
			return ReadProcessMemory (m_hProcess, (LPVOID)dwAddress, (_Ty*)pData, sizeof (_Ty) * pSize, 0);
		}

		template <typename _Ty>
		_Ty Read (DWORD dwAddress) {
			_Ty pData;
			if (!ReadProcessMemory (m_hProcess, (LPVOID)dwAddress, &pData, sizeof (_Ty), 0)) {
			}
			return pData;
		}

		template <typename _Ty>
		BOOL ReadProtect (DWORD dwAddress, _Ty pData, SIZE_T pSize) {
			PDWORD oldProtect;
			VirtualProtectEx (m_hProcess, (LPVOID)dwAddress, sizeof (T), PAGE_EXECUTE_READWRITE, &oldProtect);
			BOLL bRet = ReadProcessMemory (m_hProcess, (LPVOID)dwAddress, (_Ty*)pData, sizeof (_Ty) * pSize, 0);
			VirtualProtectEx (m_hProcess, (LPVOID)dwAddress, sizeof (T), oldProtect, NULL);
			return bRet;
		}

		template <typename _Ty>
		_Ty ReadProtect (DWORD dwAddress) {
			PDWORD oldProtect;
			VirtualProtectEx (m_hProcess, (LPVOID)dwAddress, sizeof (T), PAGE_EXECUTE_READWRITE, &oldProtect);
			_Ty pData;
			if (!ReadProcessMemory (m_hProcess, (LPVOID)dwAddress, &pData, sizeof (_Ty), 0)) {

			}
			VirtualProtectEx (m_hProcess, (LPVOID)dwAddress, sizeof (T), oldProtect, NULL);
			return pData;
		}

		template <typename _Ty>
		BOOL Write (DWORD dwAddress, _Ty pData) {
			return WriteProcessMemory (m_hProcess, (LPVOID)dwAddress, &pData, sizeof (_Ty), 0);
		}

		template <typename _Ty>
		BOOL Write (DWORD dwAddress, _Ty pData, SIZE_T pSize) {
			return WriteProcessMemory (m_hProcess, (LPVOID)dwAddress, (_Ty*)pData, sizeof (_Ty) * pSize, 0);
		}

		template <typename _Ty>
		BOOL WriteProtect (DWORD dwAddress, _Ty pData) {
			PDWORD oldProtect;
			VirtualProtectEx (m_hProcess, (LPVOID)dwAddress, sizeof (T), PAGE_EXECUTE_READWRITE, &oldProtect);
			BOOL bRet = WriteProcessMemory (m_hProcess, (LPVOID)dwAddress, &pData, sizeof (_Ty), 0);
			VirtualProtectEx (m_hProcess, (LPVOID)dwAddress, sizeof (T), oldProtect, NULL);
			return bRet;
		}

		template <typename _Ty>
		BOOL WriteProtect (DWORD dwAddress, _Ty pData, SIZE_T pSize) {
			PDWORD oldProtect;
			VirtualProtectEx (m_hProcess, (LPVOID)dwAddress, sizeof (T), PAGE_EXECUTE_READWRITE, &oldProtect);
			BOOL bRet = WriteProcessMemory (m_hProcess, (LPVOID)dwAddress, (_Ty*)pData, sizeof (_Ty) * pSize, 0);
			VirtualProtectEx (m_hProcess, (LPVOID)dwAddress, sizeof (T), oldProtect, NULL);
			return bRet;
		}
	};
}