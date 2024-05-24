#pragma once

#ifdef CRML_PLATFORM_WINDOWS

	#ifdef CRML_BUILD_DLL
		#define CARAMEL_API __declspec(dllexport)
	#else
		#define CARAMEL_API __declspec(dllimport)

	#endif

#else
	#error Caramel only supports windows
#endif

#ifdef CRML_ENABLE_ASSERTS
	#define CRML_ASSERT(x,...) {if(!(x)) {CRML_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak();}
	#define CRML_CORE_ASSERT(x,...) {if(!(x)) {CRML_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak();}
#else
	#define CRML_ASSERT(x,...)
	#define CRML_CORE_ASSERT(x,...)
#endif

#define BIT(x) (1 << x)