@echo off
%VULKAN_SDK%\Bin\glslc.exe shaders/triangle.vert -o shaders/vert.spv
%VULKAN_SDK%\Bin\glslc.exe shaders/triangle.frag -o shaders/frag.spv
pause 