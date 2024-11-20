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

#include "core.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <functional>

namespace Editor
{
    class Window
    {
    public:
        SDL_Window *sdlWindow;
        SDL_Renderer* renderer;
        bool running = false;

        void create();
        void mainLoop();
    
    private:

    };
}