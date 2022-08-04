#pragma once

#ifdef YOI_PLATFORM_WIN
	#ifdef YOI_BUILD_DLL
		#define YOI_API __declspec(dllexport)
	#else
		#define YOI_API __declspec(dllimport)
	#endif
#else
	#error Yoi only supports Windows
#endif