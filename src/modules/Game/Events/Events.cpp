#include "Events.h"
#include "../Interface/Interface.h"
#include "./enums/EventTypeEnum.h"
#include "./EventResponse/EventResponse.h"

#include <string>

using namespace std;

EventResponse Events::triggerEvent(Event event) {
    string response = interface.handleEvent(event);
    return EventResponse(response);
};
