workspace "ParticleGameOfLife"
   configurations { "Debug", "Release" }
   architecture "x64"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "ParticleGameOfLife"
