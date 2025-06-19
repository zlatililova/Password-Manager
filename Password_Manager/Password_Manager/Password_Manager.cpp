// Password_Manager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "PassFileManager.h"
#include <sstream>
#include <vector>
#include "CommandManager.h"


int main() {

    std::string input;

    std::cout << "Password Manager is running. Type commands. Type 'exit' to quit.\n";

    while (true) {
        try {
            std::cout << ">> ";
            std::getline(std::cin, input);

            if (input.empty()) continue;
            if (input == "exit") break;

            CommandManager::getInstance()->executeCommand(input);
        }
        catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }

    std::cout << "Goodbye!";
    return 0;
}


