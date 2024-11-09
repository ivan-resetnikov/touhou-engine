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

#include "window.h"

namespace Game
{
    WindowStatus Window::create() {
        window = glfwCreateWindow(640, 480, "Touhou Engine", NULL, NULL);
        if (!window) {
            const char* description;
            int code = glfwGetError(&description);
            Core::logCritical("Could not create game window, GLFW Error " + std::to_string(code) + ": " + description);

            glfwTerminate();

            return WindowStatus::CREATE_ERROR;
        }

        glfwMakeContextCurrent(window);
        glfwSwapInterval(1);

        return WindowStatus::CREATE_SUCCESS;
    }
    
    void Window::mainLoop()
    {
        while (!glfwWindowShouldClose(window)) {
            glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(window);

            glfwPollEvents();
        }
    }
}