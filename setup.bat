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
echo This setup script is licensed under the MIT License.
echo For more information, visit: REPO_LINK


set "ORIGINAL_DIR=%cd%"

:: Path to ini file
set "INI_FILE=setup.ini"

:: Read environment mode from INI file, skipping comment lines
for /f "tokens=1,2 delims==" %%a in ('findstr /i /v /b /c:";" /c:"# " "%INI_FILE%" ^| findstr /i "env_mode"') do (
    if /i "%%a" == "env_mode" (
        set "ENV_MODE=%%b"
    )
)


:: Function to initialize MSVC environment
:INIT_MSVC_ENV
    :: MSVC environment setup scripts
    set "MSVC__ENV_SETUP_SCRIPT_PATH=C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build"
    set "MSVC__USE_x86_BUILD_x86=vcvars32.bat"
    set "MSVC__USE_x64_BUILD_x64=vcvars64.bat"

    echo Setting up MSVC compilation environment for %ENV_MODE%...

    :: Set the correct environment setup script based on the ini file
    if "%ENV_MODE%" == "USE_x86_BUILD_x86" (
        set "MSVC__ENV_SETUP_SCRIPT=%MSVC__USE_x86_BUILD_x86%"
    ) else if "%ENV_MODE%" == "USE_x64_BUILD_x64" (
        set "MSVC__ENV_SETUP_SCRIPT=%MSVC__USE_x64_BUILD_x64%"
    ) else (
        echo Invalid environment mode in ini file. Exiting...
        goto :TERMINATE
    )

    cd /d "%MSVC__ENV_SETUP_SCRIPT_PATH%"
    call "%MSVC__ENV_SETUP_SCRIPT%"

    echo Finished environment setup!
    goto :TERMINATE


:: Call the function with the selected environment mode
call :INIT_MSVC_ENV


:: Make sure that the script is back at the dir it was ran from
:TERMINATE
    cd /d "%ORIGINAL_DIR%"
    goto :EOF
