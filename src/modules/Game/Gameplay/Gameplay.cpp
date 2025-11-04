#include <string>
#include <vector>

#include "Gameplay.h"
#include "../Events/Events.h"

using namespace std;

void Gameplay::start() {
    vector<string> options = { "New game", "Load game", "Exit -_-" };
    Event startGameEvent = Event("start", "May your Spirit be pure, may you Will be strong\n", EventTypeEnum::CHOICE, options);
    events.triggerEvent(startGameEvent);  // Use the member events which has the injected interface
}