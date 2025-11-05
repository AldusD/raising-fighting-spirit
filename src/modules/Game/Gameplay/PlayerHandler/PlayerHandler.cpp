#include "PlayerHandler.h"
#include "../../Events/Events.h"

#include <string>

using namespace std;

string PlayerHandler::createPlayer() {
    Event event = Event("create_user", "Tell me warrior, what is your name?", EventTypeEnum::INPUT, {});
    string nameInput = events.triggerEvent(event).getMessage();
    
    // handling wrong names
    bool firstTry = true;
    while (nameInput == "error" || firstTry) {
        firstTry = false;

        // not compliant username
        while (nameInput == "error") {
            Event retryEvent = Event("create_user", "Dont lie to me boy!", EventTypeEnum::INPUT, {});
            nameInput = events.triggerEvent(retryEvent).getMessage();
        }

        // conflict username
        Player player = dbClient_.findPlayer(nameInput);
        if (player.name != "") {
            nameInput = "error";
        }
    }

    // creating user
    dbClient_.insertPlayer(nameInput);

    return nameInput;
};

string PlayerHandler::updatePlayer() {
    Event event = Event("update_user", "Coward!!! Changing how people call you wont change your spirit! How people used to call you?", EventTypeEnum::INPUT, {});
    string nameInput = events.triggerEvent(event).getMessage();
    
    // handling wrong names
    bool firstTry = true;
    while (nameInput == "error" || firstTry) {
        firstTry = false;

        // not compliant username
        while (nameInput == "error") {
            Event retryEvent = Event("create_user", "Dont lie to me boy!", EventTypeEnum::INPUT, {});
            nameInput = events.triggerEvent(retryEvent).getMessage();
        }

        // username not found
        Player player = dbClient_.findPlayer(nameInput);
        if (player.name == "") {
            nameInput = "error";
        }
    }

    Event event2 = Event("new_name", "How the world shall know you now?", EventTypeEnum::INPUT, {});
    string newNameInput = events.triggerEvent(event2).getMessage();

    // handling wrong names
    bool firstTry2 = true;
    while (newNameInput == "error" || firstTry2) {
        firstTry2 = false;

        // not compliant username
        while (newNameInput == "error") {
            Event retryEvent2 = Event("new_name", "Coward and dumb, try again!", EventTypeEnum::INPUT, {});
            newNameInput = events.triggerEvent(retryEvent2).getMessage();
        }

        // conflict username
        Player player = dbClient_.findPlayer(newNameInput);
        if (player.name != "") {
            newNameInput = "error";
        }
    }
    dbClient_.updatePlayer(nameInput, newNameInput);
    return newNameInput;
};

string PlayerHandler::loadPlayer() {
    Event event = Event("load_user", "You look familiar, how you're called again?", EventTypeEnum::INPUT, {});
    string nameInput = events.triggerEvent(event).getMessage();
    
    // handling wrong names
    bool firstTry = true;
    while (nameInput == "error" || firstTry) {
        firstTry = false;

        // not compliant username
        while (nameInput == "error") {
            Event retryEvent = Event("load_user", "nah never heard of that name here, lies wont get you anywhere, try again!", EventTypeEnum::INPUT, {});
            nameInput = events.triggerEvent(retryEvent).getMessage();
        }

        // username not found
        Player player = dbClient_.findPlayer(nameInput);
        if (player.name == "") {
            nameInput = "error";
        }
    }
    
    return nameInput;
};

void PlayerHandler::deletePlayer() {
    Event event = Event("delete_user", "The boy is a killer huh?! Who is the unlucky guy?", EventTypeEnum::INPUT, {});
    string nameInput = events.triggerEvent(event).getMessage();

    // handling wrong names
    bool firstTry = true;
    while (nameInput == "error" || firstTry) {
        firstTry = false;

        // not compliant username
        while (nameInput == "error") {
            Event retryEvent = Event("delete_user", "Come on, you can tell me...", EventTypeEnum::INPUT, {});
            nameInput = events.triggerEvent(retryEvent).getMessage();
        }

        // conflict username
        Player player = dbClient_.findPlayer(nameInput);
        if (player.name == "") {
            nameInput = "error";
        }
    }

    dbClient_.deletePlayer(nameInput);
};
