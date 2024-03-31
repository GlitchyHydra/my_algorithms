require "os"
local os = package.loaded['os']

workspace "MyAlgorithms"
	architecture "x64"
	startproject "Algorithms"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GoogleTest"] = "vendor/googletest/googletest"

group "Dependencies"
--	include "Vipera/vendor/GLFW"

group ""

project "Algorithms"
	location "Algorithms"
	kind "ConsoleApp" --SharedLib for dll StaticLib
	language "C++"
	cppdialect "C++17"
	staticruntime "on" --staticruntime off for dll

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "hzpch.h"
	pchsource "Algorithms/src/hzpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
        "%{prj.name}/tests/**.h",
		"%{prj.name}/tests/**.cpp"
	}

	defines 
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
        "%{IncludeDir.GoogleTest}/include",
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
		}
		
		--postbuildcommands
		--{
		--	("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		--}

	filter "configurations:Debug"
		defines ""
        
        --links
        --{
        --"vendor/googletest/build/lib/Debug/gtestd.lib",
        --"vendor/googletest/build/lib/Debug/gtest_maind.lib"
        --}
        links
        {
        "vendor/googletest/build/lib/Debug/gtest.lib",
        "vendor/googletest/build/lib/Debug/gtest_main.lib"
        }
        
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines ""
        
        links {
        "vendor/googletest/build/lib/Release/gtest.lib",
        "vendor/googletest/build/lib/Release/gtest_main.lib"
        }
        
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines ""
		runtime "Release"
		optimize "on"