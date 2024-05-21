workspace "Caramel"

    architecture "x64"

    configurations{
        "Debug",
        "Release",
        "Dist"
    }
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Caramel"
    location "Caramel"
    kind "SharedLib" -- =dynamic library
    language "C++"

    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "crmlpch.h"
    pchsource "Caramel/src/crmlpch.cpp"

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

    filter "system:windows"
        cppdialect "C++17" --???
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "CRML_PLATFORM_WINDOWS",
            "CRML_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sanbox")
        }

    filter "configurations:Debug"
        defines "CRML_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "CRML_RELEASE"
        optimize "On"
    filter "configurations:Dist"
        defines "CRML_DIST"
        optimize "On"

    --filter {"system: windows", "configurations:Release"}
    --    buildoptions "/MT"

project "Sanbox"
        location "Sanbox"
        kind "ConsoleApp"
        language "C++"

        targetdir("bin/" .. outputdir .. "/%{prj.name}")
        objdir("bin-int/" .. outputdir .. "/%{prj.name}")

        files
        {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }
    
        includedirs
        {
            "Caramel/vendor/spdlog/include",
            "Caramel/src"
        }

        links
        {
            "Caramel"
        }
    
        filter "system:windows"
            cppdialect "C++17" --???
            staticruntime "On"
            systemversion "latest"
    
            defines
            {
                "CRML_PLATFORM_WINDOWS"
            }
    
    
        filter "configurations:Debug"
            defines "CRML_DEBUG"
            symbols "On"
    
        filter "configurations:Release"
            defines "CRML_RELEASE"
            optimize "On"
        filter "configurations:Dist"
            defines "CRML_DIST"
            optimize "On"


