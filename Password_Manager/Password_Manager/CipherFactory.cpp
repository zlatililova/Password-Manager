#include "CipherFactory.h"
#include "CeasarCipher.h"
#include "TextCodeCipher.h"
#include "Utils.h"

Cipher* CipherFactory::createInstance(const std::string& name, const std::vector<std::string>& arg)
{
    if (name == "CC") {
        if (arg.size() != 1) {
            throw std::invalid_argument("Insufficient arguments for the cipher");
        }
        int shift = 0;
        try {
            shift = stringToInt(arg[0]);
            std::cout << shift;
        }
        catch (std::exception& e) {
            std::cerr << "Error when initiating Ceasar cipher: " << e.what() << std::endl;
            return nullptr;
        }
         return new CeasarCipher(shift);
    }
    else if (name == "TCC") {
        if (arg.size() != 1) {
            throw std::invalid_argument("Insufficient arguments for the cipher");
        }
        return new TextCodeCipher(arg[0]);
    }

    // part of the code that shouldn't be reached
    return nullptr;
}
