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

#include "window_e.h"

namespace Editor
{
    void Window::create() {
        Core::logInfo("Initializing SDL, used features: SDL_INIT_VIDEO");
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            Core::logCritical("Failed to initialize SDL!");
            exit(1);
        }

        Core::logInfo("Initializing SDL_image, used features: IMG_INIT_PNG");
        if (!IMG_Init(IMG_INIT_PNG)) {
            Core::logCritical("Failed to initialize SDL_image!");
            SDL_Quit();
            exit(1);
        }

        Core::logInfo("Creating editor window");
        sdlWindow = SDL_CreateWindow("Touhou Engine (Editor)", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
        if (sdlWindow == NULL) {
            Core::logCritical("Could not create game window! SDL error: " + (std::string)SDL_GetError());
            SDL_Quit();
            exit(1);
        }

        renderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED);
        if (!renderer) {
            Core::logCritical("Renderer could not be created! SDL error: " + (std::string)SDL_GetError());
            SDL_DestroyWindow(sdlWindow);
            SDL_Quit();
            exit(1);
        }
    }
    
    void Window::mainLoop() {
        Core::logInfo("Entering main loop");

        SDL_Event event;
        SDL_Texture* texture = IMG_LoadTexture(renderer, "shared/frame.png");

        const float targetFPS = 60.0f;
        const Uint32 targetFrameDelay = 1000.0f / targetFPS;

        running = true;
        while (running) {
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    running = false;
                }
            }

            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
            
            SDL_RenderCopy(renderer, texture, NULL, NULL);

            SDL_RenderPresent(renderer);
            SDL_Delay(targetFrameDelay);
        }

        Core::logInfo("Exiting main loop");
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(sdlWindow);

        Core::logInfo("Cleaning up");
        SDL_Quit();
    }
}