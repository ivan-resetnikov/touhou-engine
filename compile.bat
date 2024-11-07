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
set "FLAGS=/std:c++17 /W3 /O2 /EHsc"
set "FEATURES=/DENGINE_BUILD_DLL"

:: Compile the engine DLL
set "CORE_FLAGS=/LD"
set "CORE_FILES=./engine/src/engine.cpp"
set "CORE_OUT_FILENAME=./bin/engine.dll"


:: Define BUILD_DLL to export symbols when compiling the DLL
cl %FLAGS% %CORE_FLAGS% %FEATURES% /I"./engine/src" "%CORE_FILES%" /Fo"./engine/obj/" /Fe"./bin/engine.dll" /link /IMPLIB:"./bin/engine.lib"

:: Compile Main Game Code
set "SOURCE_FILES=./game/src/game.cpp"
set "OUT_FILENAME=./bin/game.exe"

del "%OUT_FILENAME%"

:: Link core.lib (generated import library) with main game executable
cl %FLAGS% /I"./engine/src" "%SOURCE_FILES%" /Fo"./game/obj/" /EHsc /link /LIBPATH:"./bin" engine.lib /out:"%OUT_FILENAME%"