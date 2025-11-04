#pragma once
#include <string>
#include <vector>
#include "Combat.h"
#include <iostream>
using namespace std;

string Combat::minorcombat (Events events, vector<int> player_stats){
    getPlayerStats (player_stats);

    string result = "";
    player_hp = 8+2*player_vitality; //thus the hp is 10 + 2*amount invested, and the game is balanced for a player that took no vitality
    foe_hp = 15;
    foe_damage = 2;
    int last_damage_dealt = 0; //damage of the last attack you dealt
    vector<string> attack_options = {"strike a weak spot", "multi attack", "quick jab", "tire out your opponent", "dodge and retaliate", "wait for an opening"};

    // the first round has a different text than the rest, because it announces what the enemy is, so its outside the while loop
    Event mouse_start_round = Event("", "You face off against the minor spirit of the country mouse, a humble foe with a skittish demeanor, choose your attacks wisely ", EventTypeEnum::CHOICE, attack_options);
    int chosen_attack = stoi(events.triggerEvent(mouse_start_round).getMessage()) -1; //this gets the result of the event, the -1 offsets, in int so I can use it for vector manipulation


    if (chosen_attack == 0) {
        last_damage_dealt = player_strength+player_inteligence;
    }
    if (chosen_attack == 1) {
        last_damage_dealt = player_strength+player_stamina;
    }
    if (chosen_attack == 2) {
        last_damage_dealt = player_strength+player_speed;
    }
    if (chosen_attack == 3) {
        last_damage_dealt = player_speed+player_stamina;
    }
    if (chosen_attack == 4) {
        last_damage_dealt = player_speed+player_inteligence;
    }
    if (chosen_attack == 5) {
        last_damage_dealt = player_stamina+player_inteligence;
    }

    foe_hp -= last_damage_dealt;
    player_hp -= foe_damage;

    //rest of the fight
    while (foe_hp > 0 and player_hp > 0){
        Event mouse_start_round = Event("", "Your spirit uses " + attack_options[chosen_attack] + " and deals " + std::to_string(last_damage_dealt) + " damage to the minor spirit of the country mouse!" + "\nThe spirit of the country mouse bites your spirit for 2 points of damage! Your current health is " + to_string(player_hp) + "\nBy using moves that align with the strengths of your spirit, you have greater chances of victory", EventTypeEnum::CHOICE, attack_options);
        chosen_attack = stoi(events.triggerEvent(mouse_start_round).getMessage()) -1; //this gets the result of the event, the -1 offsets

        if (chosen_attack == 0) {
            last_damage_dealt = player_strength+player_inteligence;
        }
        if (chosen_attack == 1) {
            last_damage_dealt = player_strength+player_stamina;
        }
        if (chosen_attack == 2) {
            last_damage_dealt = player_strength+player_speed;
        }
        if (chosen_attack == 3) {
            last_damage_dealt = player_speed+player_stamina;
        }
        if (chosen_attack == 4) {
            last_damage_dealt = player_speed+player_inteligence;
        }
        if (chosen_attack == 5) {
            last_damage_dealt = player_stamina+player_inteligence;
        }

        foe_hp -= last_damage_dealt;

        if (foe_hp <= 0){
            result = "victory_countrymouse";
            break;
        }
        
        player_hp -= foe_damage;

        if (player_hp <= 0){
            result = "loss_countrymouse";
            break;
        }



    }
    return result;
}

string Combat::greatercombat (Events events, vector<int> player_stats){
    getPlayerStats (player_stats);

    string result = "";
    player_hp = 8+2*player_vitality; //thus the hp is 10 + 2*amount invested, and the game is balanced for a player that took no vitality
    foe_hp = 20;
    foe_damage = 3;
    int last_damage_dealt = 0; //damage of the last attack you dealt
    vector<string> attack_options = {"strike a weak spot", "multi attack", "quick jab", "tire out your opponent", "dodge and retaliate", "wait for an opening"};

    // the first round has a different text than the rest, because it announces what the enemy is, so its outside the while loop
    Event mouse_start_round = Event("", "You face off against the greater spirit of the landshark, its gigantic jaw bites in anticipation as it swims through the ground in your direction, choose your attacks wisely ", EventTypeEnum::CHOICE, attack_options);
    int chosen_attack = stoi(events.triggerEvent(mouse_start_round).getMessage()) -1; //this gets the result of the event, the -1 offsets, in int so I can use it for vector manipulation


    if (chosen_attack == 0) {
        last_damage_dealt = player_strength+player_inteligence;
    }
    if (chosen_attack == 1) {
        last_damage_dealt = player_strength+player_stamina;
    }
    if (chosen_attack == 2) {
        last_damage_dealt = player_strength+player_speed;
    }
    if (chosen_attack == 3) {
        last_damage_dealt = player_speed+player_stamina;
    }
    if (chosen_attack == 4) {
        last_damage_dealt = player_speed+player_inteligence;
    }
    if (chosen_attack == 5) {
        last_damage_dealt = player_stamina+player_inteligence;
    }

    foe_hp -= last_damage_dealt;
    player_hp -= foe_damage;

    //rest of the fight
    while (foe_hp > 0 and player_hp > 0){
        Event mouse_start_round = Event("", "Your spirit uses " + attack_options[chosen_attack] + " and deals " + std::to_string(last_damage_dealt) + " damage to the minor spirit of the landshark!" + "\nThe spirit of the land shark tears apart your spirit for 3 points of damage! Your current health is " + to_string(player_hp) + "\nBy using moves that align with the strengths of your spirit, you have greater chances of victory", EventTypeEnum::CHOICE, attack_options);
        chosen_attack = stoi(events.triggerEvent(mouse_start_round).getMessage()) -1; //this gets the result of the event, the -1 offsets

        if (chosen_attack == 0) {
            last_damage_dealt = player_strength+player_inteligence;
        }
        if (chosen_attack == 1) {
            last_damage_dealt = player_strength+player_stamina;
        }
        if (chosen_attack == 2) {
            last_damage_dealt = player_strength+player_speed;
        }
        if (chosen_attack == 3) {
            last_damage_dealt = player_speed+player_stamina;
        }
        if (chosen_attack == 4) {
            last_damage_dealt = player_speed+player_inteligence;
        }
        if (chosen_attack == 5) {
            last_damage_dealt = player_stamina+player_inteligence;
        }

        foe_hp -= last_damage_dealt;

        if (foe_hp <= 0){
            result = "victory_landshark";
            break;
        }
        
        player_hp -= foe_damage;

        if (player_hp <= 0){
            result = "loss_landshark";
            break;
        }



    }
    return result;
}

string Combat::ultimatecombat (Events events, vector<int> player_stats){
    getPlayerStats (player_stats);

    string result = "";
    player_hp = 8+2*player_vitality; //thus the hp is 10 + 2*amount invested, and the game is balanced for a player that took no vitality
    foe_hp = 70;
    foe_damage = 1;
    int last_damage_dealt = 0; //damage of the last attack you dealt
    vector<string> attack_options = {"strike a weak spot", "multi attack", "quick jab", "tire out your opponent", "dodge and retaliate", "wait for an opening"};

    // the first round has a different text than the rest, because it announces what the enemy is, so its outside the while loop
    Event mouse_start_round = Event("", "You face off against the ultimate spirit of conquest, it towers over you, emanating a menancing and opressive aura, choose your attacks wisely ", EventTypeEnum::CHOICE, attack_options);
    int chosen_attack = stoi(events.triggerEvent(mouse_start_round).getMessage()) -1; //this gets the result of the event, the -1 offsets, in int so I can use it for vector manipulation


    if (chosen_attack == 0) {
        last_damage_dealt = player_strength+player_inteligence;
    }
    if (chosen_attack == 1) {
        last_damage_dealt = player_strength+player_stamina;
    }
    if (chosen_attack == 2) {
        last_damage_dealt = player_strength+player_speed;
    }
    if (chosen_attack == 3) {
        last_damage_dealt = player_speed+player_stamina;
    }
    if (chosen_attack == 4) {
        last_damage_dealt = player_speed+player_inteligence;
    }
    if (chosen_attack == 5) {
        last_damage_dealt = player_stamina+player_inteligence;
    }

    foe_hp -= last_damage_dealt;
    player_hp -= foe_damage;

    //rest of the fight
    while (foe_hp > 0 and player_hp > 0){
        Event mouse_start_round = Event("", "Your spirit uses " + attack_options[chosen_attack] + " and deals " + std::to_string(last_damage_dealt) + " damage to the ultimate spirit of conquest!" + "\nThe spirit of conquest slowly drains your spirit's Will to keep for 1 point of damage, you feel as if your attacks barely injure it! Your current health is " + to_string(player_hp) + "\nBy using moves that align with the strengths of your spirit, you have greater chances of victory", EventTypeEnum::CHOICE, attack_options);
        chosen_attack = stoi(events.triggerEvent(mouse_start_round).getMessage()) -1; //this gets the result of the event, the -1 offsets

        if (chosen_attack == 0) {
            last_damage_dealt = player_strength+player_inteligence;
        }
        if (chosen_attack == 1) {
            last_damage_dealt = player_strength+player_stamina;
        }
        if (chosen_attack == 2) {
            last_damage_dealt = player_strength+player_speed;
        }
        if (chosen_attack == 3) {
            last_damage_dealt = player_speed+player_stamina;
        }
        if (chosen_attack == 4) {
            last_damage_dealt = player_speed+player_inteligence;
        }
        if (chosen_attack == 5) {
            last_damage_dealt = player_stamina+player_inteligence;
        }

        foe_hp -= last_damage_dealt;

        if (foe_hp <= 0){
            result = "victory_conquest";
            break;
        }
        
        player_hp -= foe_damage;

        if (player_hp <= 0){
            result = "loss_conquest";
            break;
        }



    }
    return result;
}



void Combat::getPlayerStats (vector<int> player_stats) { 
    player_inteligence = player_stats[0];
    player_speed = player_stats[1];
    player_strength = player_stats[2];
    player_vitality = player_stats[3];
    player_stamina = player_stats[4];

}