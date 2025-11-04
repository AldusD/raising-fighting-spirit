#pragma once

#include <string>

#include "../Events/Events.h"
#include "./Printer/Printer.h"
#include "./InputHandler/InputHandler.h"

using namespace std;

// handles what user sees (printer*) and what he responds (inputHandler)
// * = printer is one way to implement, the module based architecture is made so that creating a window UI would not affect anything of the project
class Interface {
    private:
        Printer printer;
        InputHandler inputHandler;
        string handleChoice(Event event);
        string handleInput(Event event);
    public:
        string handleEvent(Event event);
        explicit Interface() : printer(Printer()), inputHandler(InputHandler()) {}
};
