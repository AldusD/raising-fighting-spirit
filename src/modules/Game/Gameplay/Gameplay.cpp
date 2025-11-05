#include <string>
#include <vector>

#include "Gameplay.h"
#include "../Events/Events.h"
#include "Combat.h"
#include "SpiritGenerator/SpiritGenerator.h"
#include "./PlayerHandler/PlayerHandler.h"
#include "./SpiritHandler/SpiritHandler.h"

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

        if (menu_override != ""){          //There must be a menu override after fights
            nextMenu = menu_override;
            menu_override = "";
        }

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

    if (action == "create_game") {
        PlayerHandler playerHandler(dbClient_, events);
        SpiritHandler spiritHandler(dbClient_, events);
        player_name = playerHandler.createPlayer();
        SpiritGenerator spiritgenerator;
        player_stats = spiritgenerator.statSelection(events);
        spiritHandler.createSpirit(player_stats, player_name);
        return "continue";
    }

    if (action == "update_game") {
        PlayerHandler playerHandler(dbClient_, events);
        SpiritHandler spiritHandler(dbClient_, events);
        player_name = playerHandler.updatePlayer();
        SpiritGenerator spiritgenerator;
        player_stats = spiritgenerator.statSelection(events);
        
        return "continue";
    }

    if (action == "delete_game") {
        PlayerHandler playerHandler(dbClient_, events);
        playerHandler.deletePlayer();
        return "continue";
    }

    if (action == "load_game") {
        PlayerHandler playerHandler(dbClient_, events);
        SpiritHandler spiritHandler(dbClient_, events);
        player_name = playerHandler.loadPlayer();
        Spirit spirit = spiritHandler.findSpirit(player_name);
        player_stats = { spirit.intelligence, spirit.speed, spirit.strength, spirit.vitality, spirit.stamina, 1, 1};
    }

    if (action == "minorcombat") {
        Combat combat;
        menu_override = combat.minorcombat(events, player_stats);
        return "continue"; // even if there is things to do, the result is going to tournament selection menu, which is handled by the previous menu 
    }
    if (action == "greatercombat") {
        Combat combat;
        menu_override = combat.greatercombat(events, player_stats);
        return "continue"; // even if there is things to do, the result is going to tournament selection menu, which is handled by the previous menu 
    }
    if (action == "ultimatecombat") {
        Combat combat;
        menu_override = combat.ultimatecombat(events, player_stats);
        return "continue"; // even if there is things to do, the result is going to tournament selection menu, which is handled by the previous menu 
    }
    
    return "continue";
};


