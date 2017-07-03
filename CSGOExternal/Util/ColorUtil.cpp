#include "stdafx.h"
#include <Util\ColorUtil.h>

namespace Util
{
	CColorUtil::CColorUtil ()
	{ }

	CColorUtil::~CColorUtil ()
	{ }

	Vector4 CColorUtil::RGB2HSV (Vector4 in)
	{
		Vector4 out (0.f);
		float min, max, delta;

		min = in.m_flIPos < in.m_flJPos ? in.m_flIPos : in.m_flJPos;
		min = min < in.m_flKPos ? min : in.m_flKPos;

		max = in.m_flIPos > in.m_flJPos ? in.m_flIPos : in.m_flJPos;
		max = max > in.m_flKPos ? max : in.m_flKPos;

		out.m_flKPos = max;
		delta = max - min;
		if (delta < 0.00001)
		{
			out.m_flJPos = 0;
			out.m_flIPos = 0;
			return out;
		}

		if (max > 0.0)
		{
			out.m_flJPos = (delta / max);
		}
		else
		{
			out.m_flJPos = 0.0;
			out.m_flIPos = NAN;
			return out;
		}

		if (in.m_flIPos >= max)
			out.m_flIPos = (in.m_flJPos - in.m_flKPos) / delta;
		else
			if (in.m_flJPos >= max)
				out.m_flIPos = 2.0f + (in.m_flKPos - in.m_flIPos) / delta;
			else
				out.m_flIPos = 4.0f + (in.m_flIPos - in.m_flJPos) / delta;

		out.m_flIPos *= 60.0;

		if (out.m_flIPos < 0.0)
			out.m_flIPos += 360.0;

		return out;
	}

	Vector4 CColorUtil::HSV2RGB (Vector4 in)
	{
		Vector4 out (0.f);
		float hh, p, q, t, ff;
		long i;

		if (in.m_flJPos == 0)
		{
			out.m_flIPos = in.m_flIPos;
			out.m_flJPos = in.m_flJPos;
			out.m_flKPos = in.m_flKPos;
			return out;
		}

		hh = in.m_flIPos;
		if (hh >= 360.0)
		{
			hh = 0.0;
		}
		hh /= 60.0;
		i = (long)hh;
		ff = hh - i;
		p = in.m_flKPos * (1.0f - in.m_flJPos);
		q = in.m_flKPos * (1.0f - (in.m_flJPos * ff));
		t = in.m_flKPos * (1.0f - (in.m_flJPos * (1.0f - ff)));

		switch (i)
		{
		case 0:
		{
			out.m_flIPos = in.m_flKPos;
			out.m_flJPos = t;
			out.m_flKPos = p;
			break;
		}
		case 1:
		{
			out.m_flIPos = q;
			out.m_flJPos = in.m_flKPos;
			out.m_flKPos = p;
			break;
		}
		case 2:
		{
			out.m_flIPos = p;
			out.m_flJPos = in.m_flKPos;
			out.m_flKPos = t;
			break;
		}
		case 3:
		{
			out.m_flIPos = p;
			out.m_flJPos = q;
			out.m_flKPos = in.m_flKPos;
			break;
		}
		case 4:
		{
			out.m_flIPos = t;
			out.m_flJPos = p;
			out.m_flKPos = in.m_flKPos;
			break;
		}
		case 5:
		default:
		{
			out.m_flIPos = in.m_flKPos;
			out.m_flJPos = p;
			out.m_flKPos = q;
			break;
		}
		}

		return out;
	}
}