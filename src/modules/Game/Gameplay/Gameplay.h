#pragma once
#include "../Events/Events.h"


#include <string>

#include "../Events/Events.h"
#include "../Interface/Interface.h"
#include"./Menus/Menus.h"

using namespace std;

class Gameplay { // manages all game rules and the state
private:
    Interface interface;
    Events events;
    Menus menus;
    string handleAction(string actionType);
public:
    Gameplay() : interface(), events(interface), menus() {};  
    void start();
};