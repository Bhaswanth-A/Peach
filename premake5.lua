workspace "Peach"
    architecture "x86_64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "GLFW"
    location "Peach/vendor/GLFW"
    kind "StaticLib"
    language "C"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "Peach/vendor/GLFW/include/GLFW/*.h",
        "Peach/vendor/GLFW/src/*.c",
        "Peach/vendor/GLFW/src/*.h"
    }

    includedirs
    {
        "Peach/vendor/GLFW/include",
        "Peach/vendor/GLFW/src"
    }

    filter "system:linux"
        defines { "_GLFW_X11" }
        pic "On"
        links { "dl", "pthread", "X11", "Xrandr", "Xinerama", "Xcursor", "Xi", "Xxf86vm", "Xrender", "Xfixes", "Xext" }

    filter "system:windows"
        defines { "_GLFW_WIN32" }
        links { "gdi32", "opengl32", "shell32" }

    filter "system:macosx"
        defines { "_GLFW_COCOA" }

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
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/src/Window.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/vendor/GLFW/include"
    }

    links
    {
        "GLFW"
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