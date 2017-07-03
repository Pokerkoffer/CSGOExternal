#pragma once
#include "stdafx.h"
#include <Game\Game.h>
#include <Config\DumpConfig.h>
namespace Dumper {
	class CDumper
	{
	public:
		CDumper ();
		virtual ~CDumper ();
		virtual void Dump () = 0;
		virtual DWORD FindSignature (std::string szSignatureName) = 0;
	};
}