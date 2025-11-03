#include <string>
#include <vector>
#include <iostream> //REMOVE THIS AFTER I FINISH TESTING

#include "Gameplay.h"
#include "../Events/Events.h"

using namespace std;

void Gameplay::start () {
    Events events;

    //starting event turned into comment for testing purposes

    //vector<string> options = { "New game", "Load game", "Exit -_-" };
    //Event startGameEvent = Event("start", "May your Spirit be pure, may you Will be strong", EventTypeEnum::CHOICE, options);
    //events.triggerEvent(startGameEvent);

    statSelection(events);
}

void Gameplay::statSelection (Events events) { //I have no clue if this is supposed to be here, but it was my best guess

    int unspent_points = 3;

    vector<string> stats_names = { "inteligence", "speed", "strength", "vitality", "stamina" };
    vector<int> stats_numbers = {1, 1, 1, 1, 1};

    while (unspent_points != 0) {

        vector<string> printable_stats = {"", "", "", "", ""};
        for (int for_counter = 0; for_counter < 5; for_counter++){ 
            printable_stats[for_counter] = stats_names[for_counter] + " (current: " + std::to_string(stats_numbers[for_counter]) + ")"; //creates the printed line
        }

        Event statIncrease = Event("", "Choose which stat to increase, you have " + std::to_string(unspent_points) + " unspent points", EventTypeEnum::CHOICE, printable_stats);
        string str_stat_to_increase = events.triggerEvent(statIncrease).getMessage(); //this gets the result of the event

        int int_stat_to_increase = std::stoi(str_stat_to_increase);

        stats_numbers[int_stat_to_increase-1]++ ; //the -1 is to offset the difference between the vector and the answer from the player (vector starts at 0, player answer at 1)

        unspent_points -= 1;
    }
    // THERE NEEDS TO BE A WAY TO SAVE THE STATS SOMEWHERE, THEY ARE STORED IN stats_names!
}