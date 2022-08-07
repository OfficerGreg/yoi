workspace "yoi"
	architecture "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "yoi"
	location "yoi"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"YOI_PLATFORM_WIN",
			"YOI_BUILD_DLL" 
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "YOI_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "YOI_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "YOI_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"yoi/vendor/spdlog/include",
		"yoi/src"
	}

	links{
		"yoi"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"YOI_PLATFORM_WIN"
		}


	filter "configurations:Debug"
		defines "YOI_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "YOI_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "YOI_DIST"
		optimize "On"