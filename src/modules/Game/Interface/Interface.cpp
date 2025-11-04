#include "Interface.h"

#include "./Printer/Printer.h"
#include "./InputHandler/InputHandler.h"
#include "../shared/MessagesEnum/MessagesEnum.h"

using namespace std;

string Interface::handleEvent(Event event) {
    string response;

    if (event.getType() == EventTypeEnum::CHOICE) {
        int range = (int) event.getOptions().size() + 1; //the 1 offsets the difference between the two types of values
        printer.printChoice(event.getTitle(), event.getMessage(), event.getOptions());
        
        string choice = inputHandler.handleChoiceInput(range);
        while(choice == "error") {
            printer.printSingleMessage(MessagesEnum::INVALID_CHOICE);
            choice = inputHandler.handleChoiceInput(range);  // Remove 'string' - update existing variable
        }
        return choice;
    }
    
    if (event.getType() == EventTypeEnum::INPUT) {
        printer.printInput(event.getTitle(), event.getMessage());
        return inputHandler.handleTextInput();
    }
    
    return "error"; // just so it compiles
};