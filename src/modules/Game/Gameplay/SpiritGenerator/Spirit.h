#pragma once
#include <string>
#include <vector>

using namespace std;

class Spirit {
public: 
    int inteligence = 0;
    int speed = 0;
    int strength = 0; 
    int vitality = 0;
    int stamina = 0;

    void getStats(vector<int> vector_stats);
};