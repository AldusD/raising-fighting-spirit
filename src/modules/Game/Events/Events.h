#pragma once

#include "./Event/Event.h"
#include "./EventResponse/EventResponse.h"

class Interface;

class Events { // bridge connecting business logic (gameplay mod) and user interaction (interface mod)
private:
    Interface& interface;

public:
    // Constructor takes Interface reference
    explicit Events(Interface& interface) : interface(interface) {}
    
    EventResponse triggerEvent(Event event);
};
