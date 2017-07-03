#include "stdafx.h"
#include <Dumper\NetVarDumper.h>
namespace Dumper {
	CNetVarDumper::CNetVarDumper () : CDumper ()
	{
		this->m_pNetVars = new std::map<std::string, DWORD> ();
	}

	CNetVarDumper::~CNetVarDumper ()
	{
		delete this->m_pNetVars;
	}

	DWORD CNetVarDumper::ScanTable (CRecvTable * pTable, std::string szTableName)
	{
		for (int i = 0; i < pTable->GetPropertyCount (); i++) {
			CRecvProp* pProp = pTable->GetProperty (i);

			if (pProp->GetPropertyType () == ePropType::DPT_DataTable) {
				CRecvTable* pPropTable = pProp->GetDataTable ();
				if (pProp->GetPropertyName () == "baseclass") {
					this->vNetVars[szTableName].push_back ({ pPropTable->GetTableName (), pProp->GetPropertyOffset () });
				}
				else {
					this->vNetVars[szTableName].push_back ({ pProp->GetPropertyName (), pProp->GetPropertyOffset () });
				}
				this->ScanTable (pPropTable, szTableName);
			}
			else {
				if (isdigit (pProp->GetPropertyName ().c_str ()[0])) {
					continue;
				}
				this->vNetVars[szTableName].push_back ({ pProp->GetPropertyName (), pProp->GetPropertyOffset () });
			}
		}
		return 0;
	}

	DWORD CNetVarDumper::FindNetVar (std::string szTableName, std::string szPropertyName)
	{
		auto x = this->vNetVars[szTableName];
		for (auto p : x) {
			if (p.first == szPropertyName) {
				return p.second;
			}
		}
		return 0;
	}

	void CNetVarDumper::Dump ()

	{
		auto pFirstClass = Game::CGame::GetInstance().GetProcess().Read<CClientClass*>(Game::CGame::GetInstance().GetModule("client.dll").GetModuleBase() + CSignatureDumper::GetInstance ().FindSignature ("dwGetAllClasses"));

		if (!pFirstClass)
			return;

		for (CClientClass* pClass = pFirstClass; pClass; pClass  = pClass->GetNextClass ()) {
			CRecvTable* pTable = pClass->GetDataTable ();
			this->ScanTable (pTable, pTable->GetTableName ());
		}

		this->m_pNetVars->clear ();
		for (auto pNetVar : Config::CDumpConfig::GetInstance ().GetNetVars ()) {
			this->m_pNetVars->insert (std::make_pair (pNetVar.GetNetVarName(), this->FindNetVar (pNetVar.GetTableName (), pNetVar.GetPropertyName ()) + pNetVar.GetOffset()));
		}
	}

	DWORD CNetVarDumper::FindSignature (std::string szNetVarName)
	{
		if (this->m_pNetVars->find (szNetVarName) != this->m_pNetVars->end ()) {
			return this->m_pNetVars->at (szNetVarName);
		}
		else {
			return 0;
		}
	}

	std::string CRecvProp::GetPropertyName ()
	{
		char szPropertyName[128];
		for (int i = 0; i < 128; i++) {
			szPropertyName[i] = szPropertyName[i] = Game::CGame::GetInstance ().GetProcess ().Read<char> (Game::CGame::GetInstance ().GetProcess ().Read<DWORD> ((DWORD)this) + i);
			if (szPropertyName[i] == 0x0) {
				break;
			}
		}
		return std::string (szPropertyName);
	}

	int CRecvProp::GetPropertyOffset ()
	{
		return Game::CGame::GetInstance ().GetProcess ().Read<int> ((DWORD) this + 0x2C);
	}

	ePropType CRecvProp::GetPropertyType ()
	{
		return Game::CGame::GetInstance ().GetProcess ().Read<ePropType> ((DWORD) this + 0x4);
	}

	CRecvTable* CRecvProp::GetDataTable ()
	{
		return Game::CGame::GetInstance ().GetProcess ().Read<CRecvTable*> ((DWORD) this + 0x28);
	}

	std::string CRecvTable::GetTableName ()
	{
		char szTableName[64];
		for (int i = 0; i < 64; i++) {
			szTableName[i] = Game::CGame::GetInstance ().GetProcess ().Read<char> (Game::CGame::GetInstance ().GetProcess ().Read<DWORD> ((DWORD)this + 0xC) + i);
			if (szTableName[i] == 0x0) {
				break;
			}
		}
		return std::string (szTableName);
	}

	int CRecvTable::GetPropertyCount ()
	{
		return Game::CGame::GetInstance ().GetProcess ().Read<int> ((DWORD) this + 0x4);
	}

	CRecvProp* CRecvTable::GetProperty (int iIndex)
	{
		return (CRecvProp*) (Game::CGame::GetInstance ().GetProcess ().Read<DWORD> ((DWORD) this) + (iIndex * 0x3C));
	}

	std::string CClientClass::GetNetworkName ()
	{
		char szNetworkName[64];
		for (int i = 0; i < 64; i++) {
			szNetworkName[i] = Game::CGame::GetInstance ().GetProcess ().Read<char> (Game::CGame::GetInstance ().GetProcess ().Read<DWORD> ((DWORD)this + 0x8) + i);
			if (szNetworkName[i] == 0x0) {
				break;
			}
		}
		return std::string (szNetworkName);
	}

	CClientClass * CClientClass::GetNextClass ()
	{
		return Game::CGame::GetInstance ().GetProcess ().Read<CClientClass*> ((DWORD)this + 0x10);;
	}

	CRecvTable * CClientClass::GetDataTable ()
	{
		return Game::CGame::GetInstance ().GetProcess ().Read<CRecvTable*> ((DWORD) this + 0xC);
	}
}