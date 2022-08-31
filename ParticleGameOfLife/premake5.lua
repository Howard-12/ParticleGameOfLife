project "ParticleGameOfLife"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++17"
   staticruntime "off"

   targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
   objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

   files
   {
      "src/**.h",
      "src/**.cpp"
   }

   includedirs 
   {
      "vendor/SFML1/include"
   }
   
   links 
   {
      --"vendor/SFML/lib/**.lib"
      "vendor/SFML1/lib/sfml-graphics-d.lib", 
      "vendor/SFML1/lib/sfml-window-d.lib",
      "vendor/SFML1/lib/sfml-system-d.lib",
      "vendor/SFML1/bin/sfml-graphics-d-2.dll"
   }

   defines 
   {

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
