#pragma once
#include <string>
#include <vector>

#include "../Events/Events.h"

using namespace std;

class Combat {
public: 
    int player_hp = 0;
    int player_inteligence = 0;
    int player_speed = 0;
    int player_strength = 0; 
    int player_vitality = 0;
    int player_stamina = 0;

    int foe_hp = 0;
    int foe_damage = 0;

    string minorcombat(Events events, vector<int> player_stats);
    string greatercombat(Events events, vector<int> player_stats);
    string ultimatecombat(Events events, vector<int> player_stats);
    void getPlayerStats(vector<int> player_stats);
};

