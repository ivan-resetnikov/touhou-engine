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

:: Compilation flags
set "FLAGS=/std:c++17 /W3 /O2 /EHsc /MD"
set "FEATURES=/DENGINE_BUILD_DLL"

:: Paths for includes, libraries, and output directories
set "INCLUDE_DIR=./include"
set "LIB_DIR=./lib"
set "BIN_DIR=./bin"
set "LIBS=glfw3.lib opengl32.lib user32.lib gdi32.lib shell32.lib msvcrt.lib"

:: Clear previous builds
if exist "%BIN_DIR%\core.dll" del "%BIN_DIR%\core.dll"
if exist "%BIN_DIR%\core.lib" del "%BIN_DIR%\core.lib"
if exist "%BIN_DIR%\game.exe" del "%BIN_DIR%\game.exe"

:: Create necessary directories
if not exist "%BIN_DIR%" mkdir "%BIN_DIR%"
if not exist "./core/obj" mkdir "./core/obj"
if not exist "./game/obj" mkdir "./game/obj"
if not exist "./game/obj/modes" mkdir "./game/obj/modes"
if not exist "./game/obj/modes/game" mkdir "./game/obj/modes/game"

:: Compile core.dll
cl %FLAGS% /LD %FEATURES% /I"./core/src" /I"%INCLUDE_DIR%" ^
    ./core/src/core.cpp ./core/src/logging.cpp ^
    /Fo"./core/obj/" /Fe"%BIN_DIR%\core.dll" ^
    /link /IMPLIB:"%BIN_DIR%\core.lib" /LIBPATH:"%LIB_DIR%" %LIBS% /NODEFAULTLIB:libucrt.lib /NODEFAULTLIB:MSVCRT

:: Compile game.exe
cl %FLAGS% /I"./core/src" /I"%INCLUDE_DIR%" ^
    ./game/src/main.cpp ./game/src/modes/mode.cpp ./game/src/modes/editor.cpp ^
    ./game/src/modes/game.cpp ./game/src/modes/game/window.cpp ^
    /Fo"./game/obj/" /Fe"%BIN_DIR%\game.exe" ^
    /link /LIBPATH:"%BIN_DIR%" /LIBPATH:"%LIB_DIR%" core.lib %LIBS% /NODEFAULTLIB:libucrt.lib /NODEFAULTLIB:MSVCRT

echo Compilation complete.
