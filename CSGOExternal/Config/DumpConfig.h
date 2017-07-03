#pragma once
#include "stdafx.h"
#include <Game\Game.h>
namespace Config {
	class CSignature {
		std::string m_szSignatureName;
		std::string m_szModule;
		std::string m_szPattern;
		int m_iOffset;
		int m_iExtra;
		int m_iDumpMode;

	public:
		CSignature ();
		CSignature (std::string szSignatureName, std::string szModule, std::string szPattern, int iOffset, int iExtra, int iDumpMode);
		~CSignature ();

		std::string& GetSignatureName ();
		std::string& GetModuleName ();
		std::string& GetPattern ();
		int GetExtra ();
		int GetOffset ();
		int GetDumpMode ();
	};

	class CNetVar {

		std::string m_szNetVarName;
		std::string m_szTableName;
		std::string m_szPropertyName;
		int m_iOffset;

	public:
		CNetVar (std::string szNetVarName, std::string szTableName, std::string szPropertyName, int iOffset);
		~CNetVar ();

		std::string& GetNetVarName ();
		std::string& GetTableName ();
		std::string& GetPropertyName ();
		int GetOffset ();
	};

	class CDumpConfig
	{
		rapidjson::Document* m_pConfig;
		std::vector<CSignature>* m_pSignatures;
		std::vector<CNetVar>* m_pNetVars;
		CDumpConfig ();

	public:
		~CDumpConfig ();

		static CDumpConfig& GetInstance () {
			static CDumpConfig pInstance;
			return pInstance;
		}

		CDumpConfig (CDumpConfig const& oDumpConfig) = delete;
		void operator=(CDumpConfig const& oDumpConfig) = delete;

		rapidjson::Document* GetConfiguration ();
		std::vector<CSignature>& GetSignatures ();
		std::vector<CNetVar>& GetNetVars ();
	};
}