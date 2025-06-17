#include "CipherFactory.h"
#include "CeasarCipher.h"
#include "TextCodeCipher.h"
#include "Utils.h"

Cipher* CipherFactory::createInstance(std::string& name, std::string& arg)
{
    if (name == "CC") {
        int shift = 0;
        try {
            shift = stringToInt(arg);
        }
        catch (std::exception& e) {
            std::cerr << "Error when initiating Ceasar cipher: " << e.what() << std::endl;
            return nullptr;
        }
         return new CeasarCipher(shift);
    }
    else if (name == "TCC") {
        return new TextCodeCipher(arg);
    }

    // part of the code that shouldn't be reached
    return nullptr;
}
