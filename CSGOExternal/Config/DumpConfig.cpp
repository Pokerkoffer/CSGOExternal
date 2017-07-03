#include "stdafx.h"
#include <Config\DumpConfig.h>
namespace Config {

	CDumpConfig::CDumpConfig ()
	{
		this->m_pConfig = new rapidjson::Document ();
		this->m_pSignatures = new std::vector<CSignature> ();
		this->m_pNetVars = new std::vector<CNetVar> ();

		std::ifstream ifs ("config.json");
		rapidjson::IStreamWrapper isw (ifs);
		this->m_pConfig->ParseStream (isw);

		auto pSignatures = this->m_pConfig->GetObject ().FindMember ("Signatures");
		for (auto& pSig : pSignatures->value.GetObject ()) {
			auto pSigData = pSig.value.GetObject ();

			int iOptions = 0;

			if (pSigData.FindMember ("mode_read")->value.GetBool ()) {
				iOptions = iOptions | Remote::CFindOptions::eRead;
			}

			if (pSigData.FindMember ("mode_subtract")->value.GetBool ()) {
				iOptions = iOptions | Remote::CFindOptions::eSubtract;
			}

			CSignature tmpSig = CSignature (
				std::string (pSig.name.GetString ()),
				std::string (pSigData.FindMember ("module")->value.GetString ()),
				std::string (pSigData.FindMember ("pattern")->value.GetString ()),
				pSigData.FindMember ("offset")->value.GetInt (),
				pSigData.FindMember ("extra")->value.GetInt (),
				iOptions
			);
			this->m_pSignatures->push_back (tmpSig);
		}

		auto pNetVars = this->m_pConfig->GetObject ().FindMember ("NetVars");
		for (auto& pNetVar : pNetVars->value.GetObject ()) {
			auto pNetVarData = pNetVar.value.GetObject ();

			auto iOffset = 0;

			if (pNetVarData.HasMember ("offset")) {
				iOffset = pNetVarData.FindMember ("offset")->value.GetInt ();
			}

			CNetVar tmpNetVar = CNetVar (
				std::string(pNetVar.name.GetString()),
				std::string (pNetVarData.FindMember ("table")->value.GetString ()),
				std::string (pNetVarData.FindMember ("netvar")->value.GetString ()),
				iOffset
			);

			this->m_pNetVars->push_back (tmpNetVar);
		}
	}

	CDumpConfig::~CDumpConfig ()
	{
		std::ofstream ofs ("config.json");
		rapidjson::OStreamWrapper osw (ofs);
		rapidjson::Writer<rapidjson::OStreamWrapper> writer (osw);
		this->m_pConfig->Accept (writer);

		this->m_pNetVars->clear ();
		this->m_pSignatures->clear ();

		delete this->m_pNetVars;
		delete this->m_pSignatures;
		delete this->m_pConfig;
	}

	rapidjson::Document* CDumpConfig::GetConfiguration ()
	{
		return this->m_pConfig;
	}

	std::vector<CSignature>& CDumpConfig::GetSignatures ()
	{
		return *this->m_pSignatures;
	}
	std::vector<CNetVar>& CDumpConfig::GetNetVars ()
	{
		return *this->m_pNetVars;
	}

	CSignature::CSignature ()
	{
	}

	CSignature::CSignature (std::string szSignatureName, std::string szModule, std::string szPattern, int iOffset, int iExtra, int iDumpMode)
		: m_szSignatureName (szSignatureName), m_szModule (szModule), m_szPattern (szPattern), m_iOffset (iOffset), m_iExtra (iExtra), m_iDumpMode (iDumpMode)
	{
	}

	CSignature::~CSignature ()
	{
	}

	std::string & CSignature::GetSignatureName ()
	{
		return this->m_szSignatureName;
	}

	std::string & CSignature::GetModuleName ()
	{
		return this->m_szModule;
	}

	std::string & CSignature::GetPattern ()
	{
		return this->m_szPattern;
	}

	int CSignature::GetExtra ()
	{
		return this->m_iExtra;
	}

	int CSignature::GetOffset ()
	{
		return this->m_iOffset;
	}

	int CSignature::GetDumpMode ()
	{
		return this->m_iDumpMode;
	}

	CNetVar::CNetVar (std::string szNetVarName, std::string szTableName, std::string szPropertyName, int iOffset) : m_szNetVarName(szNetVarName), m_szTableName(szTableName), m_szPropertyName (szPropertyName), m_iOffset(iOffset)
	{
	}

	CNetVar::~CNetVar ()
	{
	}

	std::string & CNetVar::GetNetVarName ()
	{
		return this->m_szNetVarName;
	}

	std::string & CNetVar::GetTableName ()
	{
		return this->m_szTableName;
	}

	std::string & CNetVar::GetPropertyName ()
	{
		return this->m_szPropertyName;
	}

	int CNetVar::GetOffset ()
	{
		return this->m_iOffset;
	}

}