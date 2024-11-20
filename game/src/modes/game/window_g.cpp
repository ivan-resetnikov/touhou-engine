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

#include "window_g.h"

namespace Game
{
    WindowStatus Window::create() {
        if (glfwInit() == GLFW_FALSE) {
            Core::logCritical("Could not initialize GLFW!");
            return WindowStatus::CREATE_ERROR;
        }

        Core::logInfo("Creating game window, using features: OpenGL Core Profile Context 3.3");
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
        
        glfwWindow = glfwCreateWindow(640, 480, "Touhou Engine", NULL, NULL);
        if (!glfwWindow) {
            const char* description;
            int code = glfwGetError(&description);
            Core::logCritical("Could not create game window, GLFW Error #" + std::to_string(code) + ": " + description + "!");

            glfwTerminate();

            return WindowStatus::CREATE_ERROR;
        }

        Core::logInfo("Setting up window context");
        glfwMakeContextCurrent(glfwWindow);
        glfwSwapInterval(1);

        return WindowStatus::CREATE_SUCCESS;
    }
    
    void Window::mainLoop(
        GLFWkeyfun keyStateChanged,
        std::function<void(GLFWwindow*)> handleInput,
        std::function<void()> update,
        std::function<void()> draw
    ) {
        Core::logInfo("Entering main loop");
        
        glfwSetKeyCallback(glfwWindow, keyStateChanged);
        while (!glfwWindowShouldClose(glfwWindow)) {
            glfwPollEvents();
            handleInput(glfwWindow);

            update();

            draw();

            glfwSwapBuffers(glfwWindow);
        }
        Core::logInfo("Exiting main loop");

        Core::logInfo("Cleaning up");
        glfwTerminate();
    }
}