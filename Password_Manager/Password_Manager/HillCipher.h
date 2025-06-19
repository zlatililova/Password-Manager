#pragma once
#include "Cipher.h"
#include "Matrix.h"

class HillCipher: Cipher
{
public: 
	HillCipher(std::string text);
	std::string encrypt(const std::string& key) override;
	std::string decrypt(const std::string& key) override;
	std::string getName() override;
	std::string getConfig() override;



private:
    Matrix key_matrix;
    Matrix inverse_key_matrix;
    int n; // Dimension of the key matrix

    // Converts a char (A-Z) to an int (0-25)
   

    // Pads the plaintext to be a multiple of n
    std::string padPlaintext(const std::string& plaintext) const {
        std::string padded = plaintext;
        while (padded.length() % n != 0) {
            padded += 'X'; // Pad with 'X' or any other agreed-upon character
        }
        return padded;
    }

public:
    HillCipher() : n(0) {}

    // Set the key matrix and calculate its inverse
    bool setKey(const std::vector<std::vector<int>>& key_data) {
        Matrix new_key(key_data);
        if (new_key.rows != new_key.cols) {
            std::cerr << "Error: Key matrix must be square!" << std::endl;
            return false;
        }
        n = new_key.rows;
        key_matrix = new_key;

        try {
            inverse_key_matrix = key_matrix.inverse();
            return true;
        }
        catch (const std::runtime_error& e) {
            std::cerr << "Error setting key: " << e.what() << std::endl;
            return false;
        }
    }

    // Encrypt plaintext
    std::string encrypt(const std::string& plaintext) {
        if (n == 0) {
            std::cerr << "Error: Key not set!" << std::endl;
            return "";
        }

        std::string padded_plaintext = padPlaintext(plaintext);
        std::string ciphertext = "";

        for (size_t i = 0; i < padded_plaintext.length(); i += n) {
            Matrix plaintext_vec(1, n);
            for (int j = 0; j < n; ++j) {
                plaintext_vec(0, j) = charToInt(padded_plaintext[i + j]);
            }

            Matrix ciphertext_vec = plaintext_vec * key_matrix;

            for (int j = 0; j < n; ++j) {
                ciphertext += intToChar(ciphertext_vec(0, j));
            }
        }
        return ciphertext;
    }

    // Decrypt ciphertext
    std::string decrypt(const std::string& ciphertext) {
        if (n == 0) {
            std::cerr << "Error: Key not set!" << std::endl;
            return "";
        }
        if (ciphertext.length() % n != 0) {
            std::cerr << "Error: Ciphertext length must be a multiple of key dimension for decryption!" << std::endl;
            return "";
        }

        std::string decryptedtext = "";

        for (size_t i = 0; i < ciphertext.length(); i += n) {
            Matrix ciphertext_vec(1, n);
            for (int j = 0; j < n; ++j) {
                ciphertext_vec(0, j) = charToInt(ciphertext[i + j]);
            }

            Matrix plaintext_vec = ciphertext_vec * inverse_key_matrix;

            for (int j = 0; j < n; ++j) {
                decryptedtext += intToChar(plaintext_vec(0, j));
            }
        }
        return decryptedtext;
    }
};

