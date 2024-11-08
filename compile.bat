@echo off

:: This file is apart of: Touhou Engine
:: Contact: contact@ivan-reshetnikov.dev
:: ************************************
:: The MIT License (MIT)
:: 
:: Copyright (c) 2024, Ivan Reshetnikov.
:: 
:: Permission is hereby granted, free of charge, to any person obtaining a copy
:: of this software and associated documentation files (the "Software"), to deal
:: in the Software without restriction, including without limitation the rights
:: to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
:: copies of the Software, and to permit persons to whom the Software is
:: furnished to do so, subject to the following conditions:
:: 
:: The above copyright notice and this permission notice shall be included in
:: all copies or substantial portions of the Software.
:: 
:: THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
:: IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
:: FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
:: AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
:: LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
:: OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
:: THE SOFTWARE.

echo Copyright (c) 2024, Ivan Reshetnikov.
echo This compile script is licensed under the MIT License.
echo For more information, visit: REPO_LINK

:: Flags for compilation
set "FLAGS=/std:c++17 /W3 /O2 /EHsc /MD"
set "FEATURES=/DENGINE_BUILD_DLL"

:: Set the path for additional libraries (adjust the paths to where your libraries are located)
set "INCLUDE_DIR=./include"
set "LIB_DIR=./lib"
set "LIBS=glfw3.lib opengl32.lib user32.lib gdi32.lib shell32.lib msvcrt.lib"

:: Compile the core DLL
set "CORE_FLAGS=/LD"
set "CORE_FILES=./core/src/core.cpp ./core/src/context.cpp ./core/src/main_window.cpp ./core/src/logging.cpp"
set "CORE_OUT_FILENAME=./bin/core.dll"

:: Define BUILD_DLL to export symbols when compiling the DLL
cl %FLAGS% %CORE_FLAGS% %FEATURES% /I"./core/src" /I"%INCLUDE_DIR%" %CORE_FILES% /Fo"./core/obj/" /Fe"./bin/core.dll" /link /IMPLIB:"./bin/core.lib" /LIBPATH:"%LIB_DIR%" %LIBS% /NODEFAULTLIB:libucrt.lib /NODEFAULTLIB:MSVCRT

:: Compile Main Game Code
set "SOURCE_FILES=./game/src/main.cpp ./game/src/modes/mode.cpp ./game/src/modes/editor.cpp ./game/src/modes/game.cpp"
set "OUT_FILENAME=./bin/game.exe"

del "%OUT_FILENAME%"

:: Link core.lib (generated import library) with main game executable and libraries
cl %FLAGS% /I"./core/src" /I"%INCLUDE_DIR%" %SOURCE_FILES% /Fo"./game/obj/" /EHsc /link /LIBPATH:"./bin" /LIBPATH:"%LIB_DIR%" core.lib %LIBS% /NODEFAULTLIB:libucrt.lib /NODEFAULTLIB:MSVCRT /out:"%OUT_FILENAME%"
