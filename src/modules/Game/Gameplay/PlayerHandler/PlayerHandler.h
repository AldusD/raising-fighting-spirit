#pragma once

#include "../../../Database/Client/Client.h"
#include "../../Events/Events.h"

#include <string>

using namespace std;

class PlayerHandler {
    private:
        Client& dbClient_;
        Events& events;
    public:
        PlayerHandler(Client& dbClient, Events& events) : dbClient_(dbClient), events(events) {};
        string createPlayer();
        string updatePlayer();
        string loadPlayer();
        void deletePlayer();
};
