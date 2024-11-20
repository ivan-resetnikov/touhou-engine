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

#include "game.h"

namespace Game
{
    void keyStateChanged(GLFWwindow* glfwWindow, int key, int scancode, int action, int mods);
    void handleInput(GLFWwindow* glfwWindow);
    void update();
    void draw();

    void errorCallback(int error, const char* description) {
        Core::logCritical("GLFW Error #" + std::to_string(error) + ": " + description);
    }

    void ModeHandler::preInit()
    {
    }

    void ModeHandler::start()
    {
        glfwSetErrorCallback(errorCallback);
        
        window.create();
        window.mainLoop(keyStateChanged, handleInput, update, draw);

        glfwTerminate();
    }

    void keyStateChanged(GLFWwindow* glfwWindow, int key, int scancode, int action, int mods)
    {
    }
    
    void handleInput(GLFWwindow *glfwWindow)
    {
    }
    
    void update()
    {
    }
    
    void draw()
    {
        glClearColor((sin(glfwGetTime() * 5.0) + 1.0) * 0.5, (sin(glfwGetTime() * 7.0) + 1.0) * 0.5, (sin(glfwGetTime() * 2.0) + 1.0) * 0.5, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
}