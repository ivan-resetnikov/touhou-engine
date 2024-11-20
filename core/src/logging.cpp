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

#include "logging.h"

namespace Core
{
    std::string getTimeFormated()
    {
        auto now = std::chrono::system_clock::now(); // Get the current time point
        auto nowTime = std::chrono::system_clock::to_time_t(now); // Convert to time_t for date
        auto nowNanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch()) % 1'000'000'000; // Get nanoseconds part
        std::stringstream stringStream;
        stringStream << std::put_time(std::localtime(&nowTime), "%Y-%m-%d %H:%M:%S") << "." << std::setw(9) << std::setfill('0') << nowNanoseconds.count();
        return stringStream.str();
    }

#ifndef ENGINE_LOGGING_DISABLE_INFO
    void logInfo(std::string message)
    {
        std::cout << getTimeFormated() << " [INFO]     " << message << std::endl;
    }
#endif

#ifndef ENGINE_LOGGING_DISABLE_WARNING
    void logWarning(std::string message)
    {
        std::cout << getTimeFormated() << " [WARNING]  " << message << std::endl;
    }
#endif

#ifndef ENGINE_LOGGING_DISABLE_CRITICAL
    void logCritical(std::string message) {
        std::cout << getTimeFormated() << " [CRITICAL] " << message << std::endl;
    }
#endif
}