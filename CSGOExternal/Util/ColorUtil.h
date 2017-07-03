#pragma once
#include "stdafx.h"
#include <Util\Vector4.h>

namespace Util
{
	class CColorUtil
	{
		CColorUtil ();
		~CColorUtil ();

	public:
		static Vector4 RGB2HSV (Vector4);
		static Vector4 HSV2RGB (Vector4);
	};
}
