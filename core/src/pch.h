/***********************************
This file is apart of: Generic Touhou Engine
Contact: contact@ivan-reshetnikov.dev
Contact chanel for legal matters: legal@ivan-reshetnikov.dev
************************************
The Generic Touhou Engine Usage Terms

Copyright (c) 2024, Ivan Reshetnikov.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
***********************************/

#pragma once

// Features
#define ENGINE_PLATFORM_WINDOWS
// #define ENGINE_LOGGING_DISABLE_INFO
// #define ENGINE_LOGGING_DISABLE_CRITICAL
// #define ENGINE_LOGGING_DISABLE_WARNING

// Includes
#include <GLFW/glfw3.h>

#include <cstdint>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <ctime>

#include <chrono>
#include <ctime>
#include <iomanip>

// Platform resolution
#ifdef ENGINE_PLATFORM_WINDOWS
    #ifdef ENGINE_BUILD_DLL
        #define ENGINE_API __declspec(dllexport)
    #else
        #define ENGINE_API __declspec(dllimport)
    #endif
#endif
