// Password_Manager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "PassFileManager.h"

//int main()
//{
//    //Cipher* c = new CeasarCipher(3);
//    //std::string test("Hello!!!");
//    //std::string enc = c->encrypt(test);
//    //std::cout << enc << " " << c->decrypt(enc);
//
//    /*Cipher* c = new TextCodeCipher("the brown fox jumps over the lazy dog THE BROWN FOX JUMPS OVER THE LAZY DOG");
//    std::cout << c->decrypt("38,2,18,0,59,1,6,34");
//    delete c;*/
//
//
//    PassFileManager::getInstance()->openFile("./test.txt", "aaa");
//    PassFileManager::getInstance()->closeFile();
//}

#include <sstream>
#include <vector>
#include "CommandManager.h"
#include "CreateCommand.h"
#include "OpenCommand.h"
#include "SaveCommand.h"
#include "LoadCommand.h"
#include "UpdateCommand.h"
#include "DeleteCommand.h"
#include "CloseCommand.h"
#include "CipherFactory.h"

// Optional: You can also add a `help` or `exit` command

int main() {
    

    // Register commands
    CommandManager cmdMgr;
    cmdMgr.registerCommand("create", new CreateCommand());
    cmdMgr.registerCommand("open", new OpenCommand());
    cmdMgr.registerCommand("save", new SaveCommand());
    cmdMgr.registerCommand("load", new LoadCommand());
    cmdMgr.registerCommand("update", new UpdateCommand());
    cmdMgr.registerCommand("delete", new DeleteCommand());
    cmdMgr.registerCommand("close", new CloseCommand());

    std::string input;

    std::cout << "Password Manager is running. Type commands. Type 'exit' to quit.\n";

    while (true) {
        try {
            std::cout << ">> ";
            std::getline(std::cin, input);

            if (input.empty()) continue;
            if (input == "exit") break;

            cmdMgr.executeCommand(input);
        }
        catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }

    std::cout << "Goodbye!";
    return 0;
}


