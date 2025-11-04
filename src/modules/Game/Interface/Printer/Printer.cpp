#include "Printer.h"
#include "./Messages/Messages.h"

#include <string>
#include <vector>

#include <iostream>

using namespace std;

Printer::Printer() : messages() {}

void Printer::printChoice(const string& title, const string& message, const vector<string>& options) {
    printSpecialMessage(title);
    cout << message << "\n"; //there was a lack of /n here
    printOptions(options);
}

void Printer::printInput(const string& title, const string& message) {
    printSpecialMessage(title);
    cout << message << "\n\n";
    printFreeField();
}

void Printer::printSpecialMessage(const string& title) {
    string specialMessage = messages.getMessage(title);

    if (specialMessage.length() > 0) {
        cout << specialMessage << "\n"; //there was a lack of /n here
    }
}

void Printer::printOptions(const vector<string>& options) {
    string message = "Press: \n";
    for (size_t i = 0; i < options.size(); ++i) {
        message += "(" + to_string(i + 1) + ")" + " for ";
        message += options[i];
        message += "\n";
    }
    cout << message << "\n";
}

void Printer::printFreeField() {
    cout << "Write your answer\n";
}

void Printer::printSingleMessage(string message) {
    cout << message;
}