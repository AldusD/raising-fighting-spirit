#include "Menus.h"

#include "./Menu/Menu.h"
//#include "../SpiritGenerator/Spirit.h" //wait a bit dude

#include <string>

using namespace std;

// handles predefined menus rendering them by title

Menu Menus::getMenu(string menuTitle) {
    if (menuTitle == "start") {
        vector<string> options = { "New Game", "Load Game", "Update Game", "Exit -_-" };
        string message = "May your Spirit be pure, may you Will be strong\n";
        vector<string> actions = { "create_player", "", "", "exit" };
        vector<string> nextMenus = { "enemy_select", "update_user", "update_user",  "update_user" }; // TODO change it to correct values
        return Menu(menuTitle, message, options, actions, nextMenus);
    }

    if (menuTitle == "update_user") {
        vector<string> options = { "Delete Game", "Update Game" };
        string message = "Which operation you want to do?\n";
        vector<string> actions = { "", "" }; // TODO change it to correct values
        vector<string> nextMenus = { "start", "start" }; // TODO change it to correct values
        return Menu(menuTitle, message, options, actions, nextMenus);
    }
    if (menuTitle == "enemy_select") {
        vector<string> options = { "Minor spirit", "Greater Spirit", "Ultimate Spirit" };
        string message = "Which opponent do you wish to face?\n";
        vector<string> actions = { "minorcombat", "greatercombat", "ultimatecombat" };
        vector<string> nextMenus = { "enemy_select", "enemy_select", "enemy_select" }; 
        return Menu(menuTitle, message, options, actions, nextMenus);
    }

    if (menuTitle == "victory_countrymouse") {
        vector<string> options = { "Play again", "Exit" };
        string message = "Your spirit has defeated the minor spirit of the country mouse! Congratulations!\n";
        vector<string> actions = { "", "exit" };
        vector<string> nextMenus = { "enemy_select", "enemy_select" }; 
        return Menu(menuTitle, message, options, actions, nextMenus);
    }

    if (menuTitle == "loss_countrymouse") {
        vector<string> options = { "Play again", "Exit" };
        string message = "You have been defeated by the minor spirit of the country mouse. If you had followed your Will by attacking with your greatest atributes, the result might have been different.\n";
        vector<string> actions = { "", "exit" };
        vector<string> nextMenus = { "enemy_select", "enemy_select" }; 
        return Menu(menuTitle, message, options, actions, nextMenus);
    }

    if (menuTitle == "victory_landshark") {
        vector<string> options = { "Play again", "Exit" };
        string message = "Your spirit has defeated the greater spirit of the landshark! Congratulations! Doing so was a great proof of your Will!\n";
        vector<string> actions = { "", "exit" };
        vector<string> nextMenus = { "enemy_select", "enemy_select" }; 
        return Menu(menuTitle, message, options, actions, nextMenus);
    }

    if (menuTitle == "loss_landshark") {
        vector<string> options = { "Play again", "Exit" };
        string message = "You have been defeated by the greater spirit of the landshark. If you had followed your Will by attacking with your greatest atributes, the result might have been different.\n";
        vector<string> actions = { "", "exit" };
        vector<string> nextMenus = { "enemy_select", "enemy_select" }; 
        return Menu(menuTitle, message, options, actions, nextMenus);
    }

    if (menuTitle == "victory_conquest") {
        vector<string> options = { "Play again", "Exit" };
        string message = "Your spirit has defeated the greatest foe there is, by defeating Conquest itself, there are no more foes to conquer! Your WILL reigns supreme!\n";
        vector<string> actions = { "", "exit" };
        vector<string> nextMenus = { "enemy_select", "enemy_select" }; 
        return Menu(menuTitle, message, options, actions, nextMenus);
    }

    if (menuTitle == "loss_conquest") {
        vector<string> options = { "Play again", "Exit" };
        string message = "You have been defeated by the ultimate spirit of conquest. Only a near perfect spirit with near perfect choices could every hope to destroy it.\n";
        vector<string> actions = { "", "exit" };
        vector<string> nextMenus = { "enemy_select", "enemy_select" }; 
        return Menu(menuTitle, message, options, actions, nextMenus);
    }

    return Menu("error t", "error msg", vector<string>{"error"}, vector<string>{"start"}, vector<string>{"error"});
};