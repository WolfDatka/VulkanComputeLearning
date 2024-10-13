workspace "VulkanComputeLearning"
    architecture "x64"

    configurations {
        "Debug",
        "FastDebug",
        "Release",
    }

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
vulkanDir = "C:/VulkanSDK/1.3.296.0/"

project "Basics"
    location "Basics"
    kind "ConsoleApp"
    language "C++"

    targetdir ("%{prj.location}/Bin/" .. outputDir)
    objdir ("%{prj.location}/Obj/" .. outputDir)

    files {
        "%{prj.location}/Src/**.cpp",
        "%{prj.location}/Headers/**.h",
    }

    includedirs {
        "%{prj.location}/Headers/",
        vulkanDir .. "Include/",
    }

    libdirs {
        vulkanDir .. "Lib/",
    }

    links {
        "vulkan-1",
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"
        defines {
            "WINDOWS",
        }

    filter "configurations:Debug"
        symbols "On"
        optimize "Off"
        defines {
            "DEBUG",
        }

    filter "configurations:FastDebug"
        symbols "On"
        optimize "On"
        defines {
            "FAST_DEBUG",
        }

    filter "configurations:Release"
        symbols "Off"
        optimize "On"
        defines {
            "RELEASE",
        }
