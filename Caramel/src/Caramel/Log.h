#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Caramel
{
	class CARAMEL_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}


//Core log macros
#define CRML_CORE_TRACE(...) ::Caramel::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CRML_CORE_INFO(...)  ::Caramel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CRML_CORE_WARN(...)  ::Caramel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CRML_CORE_ERROR(...) ::Caramel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CRML_CORE_CRITICAL(...) ::Caramel::Log::GetCoreLogger()->critical(__VA_ARGS__)

//Client log macros
#define CRML_TRACE(...)      ::Caramel::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CRML_INFO(...)       ::Caramel::Log::GetClientLogger()->info(__VA_ARGS__)
#define CRML_WARN(...)       ::Caramel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CRML_ERROR(...)      ::Caramel::Log::GetClientLogger()->error(__VA_ARGS__)
#define CRML_CRITICAL(...)      ::Caramel::Log::GetClientLogger()->critical(__VA_ARGS__)

//if distribution build
//#define HZ_CORE_INFO