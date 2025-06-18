// Password_Manager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "PassFileManager.h"

int main()
{
    //Cipher* c = new CeasarCipher(3);
    //std::string test("Hello!!!");
    //std::string enc = c->encrypt(test);
    //std::cout << enc << " " << c->decrypt(enc);

    /*Cipher* c = new TextCodeCipher("the brown fox jumps over the lazy dog THE BROWN FOX JUMPS OVER THE LAZY DOG");
    std::cout << c->decrypt("38,2,18,0,59,1,6,34");
    delete c;*/


    PassFileManager::getInstance()->createFile("./test.txt", "CC", std::vector<std::string>{"3"}, "abc");
    PassFileManager::getInstance()->closeFile();
}

