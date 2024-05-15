#pragma once

#ifdef CRML_PLATFORM_WINDOWS

	#ifdef CRML_BUILD_DLL
		#define CARAMEL_API __declspec(dllexport)
	#else
		#define CARAMEL_API __dllspec(dllimport)

	#endif

#else
	#error Caramel only supports windows
#endif