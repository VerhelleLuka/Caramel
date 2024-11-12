workspace "Caramel"

    architecture "x64"

    configurations{
        "Debug",
        "Release",
        "Dist"
    }
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Caramel/vendor/GLFW/include" --includes the Premake5file in this folder
IncludeDir["GLAD"] = "Caramel/vendor/GLAD/include" 
IncludeDir["ImGui"] = "Caramel/vendor/imgui" 
IncludeDir["glm"] = "Caramel/vendor/glm" 

include "Caramel/vendor/GLFW"
include "Caramel/vendor/GLAD"
include "Caramel/vendor/imgui"

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
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/glm/glm/**.hpp",
        "%{prj.name}/vendor/glm/glm/**.inl"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.GLAD}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}"
    }

    links
    {
        "GLFW",
        "GLAD",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17" --???
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "CRML_PLATFORM_WINDOWS",
            "CRML_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sanbox")
        }

    filter "configurations:Debug"
        defines "CRML_DEBUG"
        symbols "On"
        buildoptions "/MDd"

    filter "configurations:Release"
        defines "CRML_RELEASE"
        optimize "On"
        buildoptions "/MD"

    filter "configurations:Dist"
        defines "CRML_DIST"
        optimize "On"
        buildoptions "/MD"


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
            "Caramel/src",
                    "%{IncludeDir.glm}"
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
        buildoptions "/MDd"

    
        filter "configurations:Release"
            defines "CRML_RELEASE"
            optimize "On"
        buildoptions "/MD"

        filter "configurations:Dist"
            defines "CRML_DIST"
            optimize "On"
        buildoptions "/MD"



