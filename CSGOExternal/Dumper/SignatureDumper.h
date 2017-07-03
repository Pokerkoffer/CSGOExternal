#pragma once
#include <Dumper\Dumper.h>
#include <Dumper\NetVarDumper.h>
namespace Dumper {
	class CSignatureDumper : public CDumper
	{
		std::map<std::string, DWORD>* m_pSignatures;
		CSignatureDumper ();
	public:
		~CSignatureDumper ();

		static CSignatureDumper& GetInstance () {
			static CSignatureDumper pInstance;
			return pInstance;
		}

		CSignatureDumper (CSignatureDumper const& oDumpConfig) = delete;
		void operator=(CSignatureDumper const& oDumpConfig) = delete;

		void Dump ();
		DWORD FindSignature (std::string szSignatureName);
	};
}

