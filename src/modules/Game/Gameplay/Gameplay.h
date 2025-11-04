#pragma once

#include "../Events/Events.h"
#include "../Interface/Interface.h"

class Gameplay { // manages all game rules and the state
private:
    Interface interface;  // owns the interface instance
    Events events;      // owns the events instance that uses the interface

public:
    // Initialize interface first, then pass it to events
    Gameplay() : interface(), events(interface) {};  
    void start();
};