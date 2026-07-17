#pragma once

#include <csignal>

#ifdef PEACH_ENABLE_ASSERTS
    #define PEACH_DEBUGBREAK() raise(SIGTRAP)
    #define PEACH_ASSERT(x, ...) { if(!(x)) { PEACH_ERROR("Assertion Failed: {0}", __VA_ARGS__); PEACH_DEBUGBREAK(); } }
    #define PEACH_CORE_ASSERT(x, ...) { if(!(x)) { PEACH_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); PEACH_DEBUGBREAK(); } }
#else
    #define PEACH_ASSERT(x, ...)
    #define PEACH_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)