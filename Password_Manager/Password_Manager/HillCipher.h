#pragma once
#include "Cipher.h"
#include "Matrix.h"

class HillCipher: public Cipher
{
public: 
	HillCipher(int n, const std::string info);
	std::string encrypt(const std::string& key) override;
	std::string decrypt(const std::string& key) override;
	std::string getName() override;
	std::string getConfig() override;

    bool setKey(const std::vector<std::vector<int>>& key_data);


private:
	std::string padPlainText(const std::string& plainText) const;
    Matrix key_matrix;
    Matrix inverse_key_matrix;
    int n;   
	std::string text;
  


};

