#include <string>
#include <vector>

#include "Gameplay.h"
#include "../Events/Events.h"
#include "SpiritGenerator/SpiritGenerator.h"

#include <string>

using namespace std;

void Gameplay::start() { // handles game flow between menus and actions
    Menu menu = menus.getMenu("start");

    while (true) {
        Event event = Event(menu.getTitle(), menu.getMessage(), EventTypeEnum::CHOICE, menu.getOptions());
        
        // menu tells what action must be done and to which menu go next
        string selected = events.triggerEvent(event).getMessage();
        string nextMenu = menu.getNextMenu(selected);
        
        // action tells what game should do (specific game features like battling and generating spirit) might change nextMenu or close game
        string action = menu.getAction(selected);
        string newBehavior = handleAction(action);
        
        if (newBehavior == "continue") {
            menu = menus.getMenu(nextMenu);
        }

        if (newBehavior == "exit") {
            return;
        }
    }
}

string Gameplay::handleAction(string action) {
    if (action == "exit") {
        return "exit";
    }

    if (action == "generate_spirit") {
        // calls generate spirit module...
        return "continue"; // even if there is things to do, the result is going to tournament selection menu, which is handled by the previous menu
    }
    
    return "continue";
};


