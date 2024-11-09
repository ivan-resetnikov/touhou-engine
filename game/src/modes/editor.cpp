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

#include "editor.h"

void Editor::preInit()
{
}

void Editor::start()
{
    SDL_Window *window;

    Core::logInfo("Initializing SDL, used features: SDL_INIT_VIDEO");
    SDL_Init(SDL_INIT_VIDEO);

    Core::logInfo("Creating editor window");
    window = SDL_CreateWindow("Touhou Engine Editor", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        Core::logCritical("Could not create game window, SDL error: " + (std::string)SDL_GetError());
        return;
    }

    Core::logInfo("Entering main loop");
    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }
        SDL_Delay(16);
    }

    Core::logInfo("Exiting main loop");
    SDL_DestroyWindow(window);

    Core::logInfo("Cleaning up");
    SDL_Quit();
}
