workspace "MyProject"
   architecture "x86_64"
   startproject "App"

   configurations { "Debug", "Release", "Dist" }

OutputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Corrected paths:
include "Core/Build-Core.lua"
include "App/Build-App.lua"
