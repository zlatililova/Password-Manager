#include "HillCipher.h"
#include <stdexcept>
#include "Utils.h"

bool HillCipher::setKey(const std::vector<std::vector<int>>& key_data) {
    Matrix new_key(key_data);
    if (new_key.getRows() != new_key.getCols()) {
        throw std::invalid_argument("Key matrix must be square!");
    }
    n = new_key.getRows();
    key_matrix = new_key;

    inverse_key_matrix = key_matrix.inverse();

    return true;
}

std::string HillCipher::padPlainText(const std::string& plainText) const {
    std::string padded = plainText;
    while (padded.length() % n != 0) {
        padded += 'X';
    }
    return padded;
}

std::string HillCipher::encrypt(const std::string& key) {
    std::string padded_plaintext = padPlainText(key);
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

std::string HillCipher::decrypt(const std::string& key) {
    if (key.length() % n != 0) {
        throw std::logic_error("Ciphertext length must be a multiple of key dimension for decryption!");
    }

    std::string decryptedtext = "";

    for (size_t i = 0; i < key.size(); i += n) {
        Matrix ciphertext_vec(1, n);
        for (int j = 0; j < n; ++j) {
            ciphertext_vec(0, j) = charToInt(key[i + j]);
        }

        Matrix plaintext_vec = ciphertext_vec * inverse_key_matrix;

        for (int j = 0; j < n; ++j) {
            decryptedtext += intToChar(plaintext_vec(0, j));
        }
    }
    return decryptedtext;
}

HillCipher::HillCipher(int n, const std::string info) : n(n), key_matrix(n,n), inverse_key_matrix(n,n), text(info) {
    if (info.size() != (n * n)) {
        throw std::invalid_argument("Key string must have exactly " + std::to_string(n * n) + " characters.");
    }

    std::vector<std::vector<int>> matrix_data(n, std::vector<int>(n));
    for (int i = 0; i < n * n; ++i) {
        char ch = toUpper(info[i]);
        if (ch < 'A' || ch > 'Z') {
            throw std::invalid_argument("Key string must contain only A-Z letters.");
        }
        int value = ch - 'A';
        matrix_data[i / n][i % n] = value;
    }
    if (!setKey(matrix_data)) {
        throw std::runtime_error("Invalid key: matrix is not invertible modulo 26.");
    }
}

std::string HillCipher::getName() {
    return "HC";
}
std::string HillCipher::getConfig() {
    std::string res;
    res += IntToString(n) + ",";
    res += text;
    return res;
}
