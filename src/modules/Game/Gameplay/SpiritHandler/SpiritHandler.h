#pragma once

#include "../../../Database/Client/Client.h"
#include "../../Events/Events.h"

#include <string>

using namespace std;

class SpiritHandler {
    private:
        Client& dbClient_;
        Events& events;
    public:
        SpiritHandler(Client& dbClient, Events& events) : dbClient_(dbClient), events(events) {};
        void createSpirit(vector<int> stats, string username);
        Spirit findSpirit(string& username);
};
