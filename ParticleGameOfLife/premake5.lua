project "ParticleGameOfLife"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++17"
   --staticruntime "on"

   targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
   objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

   files
   {
      "src/**.h",
      "src/**.cpp"
   }

   includedirs {
      "vendor/SFML"
   }

   filter "system:windows"
      systemversion "latest"

   filter "configurations:Debug"
      runtime "Debug"
      defines { "DEBUG" }
      symbols "on"

   filter "configurations:Release"
      runtime "Release"
      defines { "NDEBUG" }
      optimize "on"
