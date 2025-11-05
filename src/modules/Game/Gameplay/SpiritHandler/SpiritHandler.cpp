#include "SpiritHandler.h"


void SpiritHandler::createSpirit(vector<int> stats, string username) {
    dbClient_.insertSpirit(stats, username);
};


Spirit SpiritHandler::findSpirit(string& username) {
    return dbClient_.findSpirit(username);
};