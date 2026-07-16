#pragma once

#include "core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Peach
{

    class Log
    {
    public:
        Log();
        ~Log();

        static void Init();

        inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger> &GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };

}

// Core log macros
#define PEACH_CORE_TRACE(...) ::Peach::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PEACH_CORE_INFO(...) ::Peach::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PEACH_CORE_WARN(...) ::Peach::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PEACH_CORE_ERROR(...) ::Peach::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PEACH_CORE_FATAL(...) ::Peach::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define PEACH_TRACE(...) ::Peach::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PEACH_INFO(...) ::Peach::Log::GetClientLogger()->info(__VA_ARGS__)
#define PEACH_WARN(...) ::Peach::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PEACH_ERROR(...) ::Peach::Log::GetClientLogger()->error(__VA_ARGS__)
#define PEACH_FATAL(...) ::Peach::Log::GetClientLogger()->fatal(__VA_ARGS__)
