workspace "Peach"
    architecture "x86_64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Peach"
    location "Peach"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "pch.h"
    pchsource "Peach/src/pch.cpp"

    files 
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:linux"
        pic "On"

    filter "configurations:Debug"
        defines { "PEACH_DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "PEACH_RELEASE" }
        optimize "On"

    filter "configurations:Dist"
        defines { "PEACH_RELEASE" }
        optimize "On"


project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files 
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Peach/vendor/spdlog/include",
        "Peach/src"
    }

    links
    {
        "Peach"
    }

    filter "configurations:Debug"
        defines { "PEACH_DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "PEACH_RELEASE" }
        optimize "On"

    filter "configurations:Dist"
        defines { "PEACH_RELEASE" }
        optimize "On"