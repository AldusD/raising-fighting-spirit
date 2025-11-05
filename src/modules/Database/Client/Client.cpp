#include "Client.h"
#include <iostream>

using namespace std;

Client::Client(Database& db) : db_(db) {}

void Client::seed() {
    createTables();
}

void Client::createTables() {
    try {
        auto txn = db_.createWork();
        // players
        txn->exec(R"(
            CREATE TABLE IF NOT EXISTS players (
                id SERIAL PRIMARY KEY,
                name TEXT NOT NULL
            )
        )");

        // spirits 
        // ownerId is not foreign key because there are values for npc tournament belonging
        txn->exec(R"(
            CREATE TABLE IF NOT EXISTS spirits (
                id SERIAL PRIMARY KEY,
                ownerId INT,
                intelligence INT,
                speed INT,
                strength INT,
                vitality INT,
                stamina INT,
                type INT,
                nature INT
            )
        )");
        txn->commit();
    } catch (const exception& e) {
        cerr << "DB createTables error: " << e.what() << endl;
    }
}

void Client::insertPlayer(const string& name) {
    try {
        auto txn = db_.createWork();
        txn->exec_params("INSERT INTO players (name) VALUES ($1)", name);
        txn->commit();
    } catch (const exception& e) {
        cerr << "DB insertPlayer error: " << e.what() << endl;
    }
}

void Client::updatePlayer(const string& name, const string& newName) {
    try {
        auto txn = db_.createWork();
        txn->exec_params("UPDATE players SET name = $1 WHERE name = $2", newName, name);
        txn->commit();
    } catch (const exception& e) {
        cerr << "DB updatePlayer error: " << e.what() << endl;
    }
}

void Client::insertSpirit(const vector<int> stats, const string& name) {
    Player player = findPlayer(name);
    int ownerId = player.id;
    try {
        auto txn = db_.createWork();
        txn->exec_params("INSERT INTO spirits (ownerId, intelligence, speed, strength, vitality, stamina, type, nature) VALUES ($1, $2, $3, $4, $5, $6, $7, $8)",
            ownerId, stats[0], stats[1], stats[2], stats[3], stats[4], stats[5], stats[6]);
        txn->commit();
    } catch (const exception& e) {
        cerr << "DB insertSpirit error: " << e.what() << endl;
    }
};

void Client::deletePlayer(const string& name) {
    try {
        auto txn = db_.createWork();
        txn->exec_params("DELETE FROM players WHERE name = $1", name);
        txn->commit();
    } catch (const exception& e) {
        cerr << "DB updatePlayer error: " << e.what() << endl;
    }
}

Spirit Client::findSpirit(const string& name) {
    Player player = findPlayer(name);
    int ownerId = player.id;
    Spirit spirit;
    try {
        auto txn = db_.createWork();
        pqxx::result r = txn->exec_params(
            "SELECT id, name FROM spirits WHERE ownerId = $1 LIMIT 1",
            ownerId
        );
        txn->commit();
        if (!r.empty()) {
            auto row = r[0];
            player.id = row[""].as<int>();
            player.name = row["name"].as<string>();
        }
    } catch (const exception& e) {
        cerr << "DB findPlayer error: " << e.what() << endl;
    }

    return spirit;
};

Player Client::findPlayer(const string& name) {
    Player player;
    player.name = "";
    player.id = 0;
    try {
        auto txn = db_.createWork();
        pqxx::result r = txn->exec_params(
            "SELECT id, name FROM players WHERE name = $1 LIMIT 1",
            name
        );
        txn->commit();
        if (!r.empty()) {
            auto row = r[0];
            player.id = row["id"].as<int>();
            player.name = row["name"].as<string>();
        }
    } catch (const exception& e) {
        cerr << "DB findPlayer error: " << e.what() << endl;
    }

    return player;
}