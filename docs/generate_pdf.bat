@echo off
pandoc VulkanEngine_Documentation.md -o VulkanEngine_Documentation.pdf --pdf-engine=xelatex -V geometry:margin=1in -V mainfont:Calibri -V monofont:Consolas 