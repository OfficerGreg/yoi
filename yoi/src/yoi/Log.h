#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <memory>

namespace yoi {

	class YOI_API Log
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

//Core Log 
#define YOI_CORE_TRACE(...)	::yoi::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define YOI_CORE_INFO(...)	::yoi::Log::GetCoreLogger()->info(__VA_ARGS__)
#define YOI_CORE_WARN(...)	::yoi::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define YOI_CORE_ERROR(...)	::yoi::Log::GetCoreLogger()->error(__VA_ARGS__)
#define YOI_CORE_FATAL(...)	::yoi::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client Log 
#define YOI_CLIENT_TRACE(...)	::yoi::Log::GetClientLogger()->trace(__VA_ARGS__)
#define YOI_CLIENT_INFO(...)	::yoi::Log::GetClientLogger()->info(__VA_ARGS__)
#define YOI_CLIENT_WARN(...)	::yoi::Log::GetClientLogger()->warn(__VA_ARGS__)
#define YOI_CLIENT_ERROR(...)	::yoi::Log::GetClientLogger()->error(__VA_ARGS__)
#define YOI_CLIENT_FATAL(...)	::yoi::Log::GetClientLogger()->fatal(__VA_ARGS__)
