#pragma once

#include <vector>
#include <string>

#include <pqxx/pqxx>
#include "../Database.h"
#include "../Models/Player.h"
#include "../Models/Spirit.h"

using namespace std;

class Client {
public:
    explicit Client(Database& db);

    void seed(); // fills db with needed tables and documents (npcs data)
    void createTables();
    void insertPlayer(const string& name);
    void updatePlayer(const string& name, const string& newName);
    void deletePlayer(const string& name);
    void insertSpirit(const vector<int> stats, const string& name);
    Player findPlayer(const string& name);
    Spirit findSpirit(const string& name);

private:
    Database& db_;
};
