#pragma once
#include <Dumper\Dumper.h>
#include <Dumper\SignatureDumper.h>
namespace Dumper {

	class CClientCLass;
	class CRecvTable;
	class CRecvProp;
	enum ePropType;

	class CClientClass {
	public:
		std::string GetNetworkName ();
		CClientClass * GetNextClass ();
		CRecvTable * GetDataTable ();
	};

	class CRecvTable
	{
	public:
		std::string GetTableName ();
		int GetPropertyCount ();
		CRecvProp* GetProperty (int iIndex);
	};

	class CRecvProp
	{
	public:
		std::string GetPropertyName ();
		int GetPropertyOffset ();
		ePropType GetPropertyType ();
		CRecvTable * GetDataTable ();
	};

	enum ePropType
	{
		DPT_Int = 0,
		DPT_Float,
		DPT_Vector,
		DPT_VectorXY,
		DPT_String,
		DPT_Array,
		DPT_DataTable,
		DPT_NUMSendPropTypes
	};

	class CNetVarDumper : public CDumper
	{
	protected:
		CNetVarDumper ();
		DWORD ScanTable (CRecvTable* pTable, std::string szTableName);
		DWORD FindNetVar (std::string szTableName, std::string szPropertyName);

		std::unordered_map<std::string, std::vector<std::pair<std::string, DWORD>>> vNetVars;

		std::map<std::string, DWORD>* m_pNetVars;

	public:
		~CNetVarDumper ();

		static CNetVarDumper& GetInstance () {
			static CNetVarDumper pInstance;
			return pInstance;
		}

		CNetVarDumper (CNetVarDumper const& oDumpConfig) = delete;
		void operator=(CNetVarDumper const& oDumpConfig) = delete;

		void Dump ();
		DWORD FindSignature (std::string szSignatureName);
	};
}
