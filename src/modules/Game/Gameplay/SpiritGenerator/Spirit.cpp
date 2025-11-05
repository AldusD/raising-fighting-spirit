#include <string>
#include <vector>
#include "Spirit.h"

using namespace std;

void Spirit::setStats (vector<int> vector_stats) { 
    inteligence = vector_stats[0];
    speed = vector_stats[1];
    strength = vector_stats[2];
    vitality = vector_stats[3];
    stamina = vector_stats[4];
}
