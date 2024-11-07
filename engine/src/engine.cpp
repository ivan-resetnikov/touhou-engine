/***********************************
This file is apart of: Touhou Engine
Contact: contact@ivan-reshetnikov.dev
************************************
The MIT License (MIT)

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

#include "engine.h"

namespace Engine
{
    void hello() {
        GLFWwindow* window;

        if (!glfwInit())
            return;

        window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
        if (!window) {
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(window);

        while (!glfwWindowShouldClose(window)) {
            glClear(GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(window);

            glfwPollEvents();
        }

        glfwTerminate();
    }

    IniData parseIniFile(const std::string& filePath) {
        IniData iniData;
        std::ifstream file(filePath);
        std::string line, currentSection;

        if (!file.is_open()) {
            throw std::runtime_error("Unable to open file: " + filePath);
        }

        while (std::getline(file, line)) {
            // Remove any comments starting with ';' or '#'
            size_t commentPos = line.find_first_of(";#");
            if (commentPos != std::string::npos) {
                line = line.substr(0, commentPos);
            }

            // Trim whitespace from both ends
            line.erase(0, line.find_first_not_of(" \t\r\n"));
            line.erase(line.find_last_not_of(" \t\r\n") + 1);

            if (line.empty()) {
                continue;  // skip empty lines
            }

            // Handle section headers
            if (line.front() == '[' && line.back() == ']') {
                currentSection = line.substr(1, line.size() - 2);
                iniData[currentSection] = {};  // Initialize a new section
            }
            // Handle key-value pairs
            else {
                size_t delimiterPos = line.find('=');
                if (delimiterPos == std::string::npos) {
                    throw std::runtime_error("Malformed line: " + line);
                }

                std::string key = line.substr(0, delimiterPos);
                std::string value = line.substr(delimiterPos + 1);

                // Trim whitespace from key and value
                key.erase(0, key.find_first_not_of(" \t"));
                key.erase(key.find_last_not_of(" \t") + 1);
                value.erase(0, value.find_first_not_of(" \t"));
                value.erase(value.find_last_not_of(" \t") + 1);

                // Add key-value to the current section
                iniData[currentSection][key] = value;
            }
        }

        file.close();
        return iniData;
    }

    // Function to print the parsed data (for demonstration)
    void printIniData(const IniData& data) {
        for (const auto& section : data) {
            std::cout << "[" << section.first << "]\n";
            for (const auto& kv : section.second) {
                std::cout << "`" << kv.first << "` = `" << kv.second << "`\n";
            }
            std::cout << "\n";
        }
    }
}