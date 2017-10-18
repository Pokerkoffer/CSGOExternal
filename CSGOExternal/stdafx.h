// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN
#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#define NOMINMAX

#define M_RAD2DEG_CONVERSION ( 180.f / M_PI )
#define M_RAD2DEG(rad) float(rad * M_RAD2DEG_CONVERSION)

#define M_DEG2RAD_CONVERSION ( M_PI / 180.f )
#define M_DEG2RAD(deg) float(deg * M_DEG2RAD_CONVERSION)

#include <algorithm>
#include <cstdint>
#include <chrono>
#include <climits>
#include <conio.h>
#include <cstdio>
#include <cstring>
#include <Dwmapi.h>
#include <FCNTL.H>
#include <fstream>
#include <io.h>
#include <iostream>
#include <istream>
#include <iterator>
#include <KnownFolders.h>
#include <math.h>
#include <numeric>
#include <Psapi.h>
#include <random>
#include <ShlObj.h>
#include <sstream>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <tchar.h>
#include <thread>
#include <TlHelp32.h>
#include <Uxtheme.h>
#include <vector>
#include <windows.h>
#include <Windows.h>
#include <xmmintrin.h>
#include <unordered_map>
#include <map>
#include <sys/stat.h>
#include <stdio.h>
#include <tchar.h>
#include <iomanip>

#include <rapidjson\rapidjson.h>
#include <rapidjson\allocators.h>
#include <rapidjson\document.h>
#include <rapidjson\istreamwrapper.h>
#include <rapidjson\ostreamwrapper.h>
#include <rapidjson\stream.h>
#include <rapidjson\writer.h>
#include <rapidjson\reader.h>
#include <rapidjson\pointer.h>

#include <d3d9.h>
#include <d3dx9.h>

#pragma once
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib") 
#pragma comment(lib, "Dwmapi.lib")

#include <vld.h>

namespace Util {
	template<class T>
	constexpr const T& clamp (const T& v, const T& lo, const T& hi) {
		return clamp (v, lo, hi, std::less<> ());
	}
	template<class T, class Compare>
	constexpr const T& clamp (const T& v, const T& lo, const T& hi, Compare comp)
	{
		return assert (!comp (hi, lo)),
			comp (v, lo) ? lo : comp (hi, v) ? hi : v;
	}
}

#include "resource.h"

// TODO: reference additional headers your program requires here
