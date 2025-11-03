#pragma once
#include "../Events/Events.h"


class Gameplay { // manages all game rules and the state
public: 
    void start();
    void statSelection(Events events);
};
