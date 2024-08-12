workspace "dev_main"
    architecture "x64"
    configurations { "Debug" } -- add more as required

outputdir = "%{cfg.buildcfg}-%{cfg.architecture}-%{cfg.system}"

include "Engine/dependencies/bin/Glad"

project "Engine"
    location "Engine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("obj/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    vpaths {
        ["Source Files/Architecture"] = "%{prj.name}/src/Architecture/**.cpp",
        ["Header Files/Architecture"] = "%{prj.name}/src/Architecture/**.h",
        ["Source Files/SDL"] = "%{prj.name}/src/SDL/**.cpp",
        ["Header Files/SDL"] = "%{prj.name}/src/SDL/**.h",
        ["Source Files/*"] = "%{prj.name}/src/**.cpp",
        ["Header Files/*"] = "%{prj.name}/src/**.h"
    }

    includedirs {
        "%{prj.name}/src",
        "Engine/dependencies/spdlog/include",
        "Engine/dependencies/Glad/include",
        "dependencies/bin/SDL/SDL2-2.30.6/include"
    }

    libdirs {
        "dependencies/bin/SDL/SDL2-2.30.6/lib/x64"
    }

    links {
        "SDL2",
        "Glad"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "ENGINE_PLATFORM_WINDOWS",
            "ENGINE_BUILD_DLL"
        }

    postbuildcommands {
        '{COPY} "%{cfg.buildtarget.relpath}" "%{wks.location}/bin/' .. outputdir .. '/Client/"'
    }

    filter "configurations:Debug"
        defines "ENGINE_DEBUG"
        buildoptions "/MD"
        symbols "On"

project "Client"
    location "Client"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("obj/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    vpaths {
        ["Source Files/Client"] = "%{prj.name}/src/Client/**.cpp",
        ["Header Files/Client"] = "%{prj.name}/src/Client/**.h",
        ["Source Files/*"] = "%{prj.name}/src/**.cpp",
        ["Header Files/*"] = "%{prj.name}/src/**.h"
    }

    includedirs {
        "Engine/dependencies/spdlog/include",
        "Engine/src",
        "dependencies/bin/SDL/SDL2-2.30.6/include"
    }

    libdirs {
        "bin/" .. outputdir .. "/Engine",
        "dependencies/bin/SDL/SDL2-2.30.6/lib/x64"
    }

    links {
        "Engine",
        "SDL2"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "ENGINE_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "ENGINE_DEBUG"
        buildoptions "/MD"
        symbols "On"
