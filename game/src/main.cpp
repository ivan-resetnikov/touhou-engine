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

#include "core.h"
#include "modes/editor.h"
#include "modes/game.h"

enum class StartupMode {
    GAME,
    EDITOR,
};

std::string stringify_StartupMode(StartupMode value) {
    // @todo: Use switch-case
    return std::string(value == StartupMode::GAME ? "GAME" : "EDITOR");
}

int main(int argc, char* argv[]) {
    // Resolve startup mode
    StartupMode startupMode = StartupMode::GAME;
    if (argc > 1) {
        if (argv[1] == "--editor") {
            startupMode = StartupMode::EDITOR;
        }
        else if (argv[1] == "--game" || argv[1] == "-g") {
            startupMode = StartupMode::GAME;
        }
        else {
            Core::logWarning("Invalid startup mode argument `" + std::string(argv[1]) + "`, defaulting to `StartupMode::GAME`");
        }
    } else {
        Core::logWarning("No startup mode argument provided, defaulting to `StartupMode::GAME`");
    }
    Core::logInfo("Using startup mode `StartupMode::" + stringify_StartupMode(startupMode) + "`");

    // Create mode handler
    Mode* modeHandler = nullptr;

    switch (startupMode)
    {
    case StartupMode::GAME:
        modeHandler = new Game::ModeHandler();
        break;

    case StartupMode::EDITOR:
        modeHandler = new Editor();
        break;
    }

    // Start main loop
    modeHandler->preInit();
    modeHandler->start();

    delete modeHandler;

    return 0;
}