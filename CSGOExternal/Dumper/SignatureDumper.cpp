#include "stdafx.h"
#include <Dumper\SignatureDumper.h>
namespace Dumper {
	CSignatureDumper::CSignatureDumper () : CDumper()
	{
		this->m_pSignatures = new std::map<std::string, DWORD> ();
	}

	CSignatureDumper::~CSignatureDumper ()
	{
		delete this->m_pSignatures;
	}

	void CSignatureDumper::Dump ()
	{
		this->m_pSignatures->clear ();
		for (auto pSig : Config::CDumpConfig::GetInstance ().GetSignatures ()) {
			this->m_pSignatures->insert (std::make_pair (pSig.GetSignatureName(), Game::CGame::GetInstance ().GetProcess ().FindPattern (Game::CGame::GetInstance ().GetModule (pSig.GetModuleName ()), pSig.GetPattern (), pSig.GetDumpMode (), pSig.GetExtra (), pSig.GetOffset ())));
		}
	}

	DWORD CSignatureDumper::FindSignature (std::string szSignatureName)
	{
		if (this->m_pSignatures->find (szSignatureName) != this->m_pSignatures->end ()) {
			return this->m_pSignatures->at (szSignatureName);
		}
		else {
			return 0;
		}
	}
}
