#include "PasswordFile.h"
#include <sstream>
#include "CipherFactory.h"
#include "Utils.h"

PasswordFile::PasswordFile(const std::string& name, Cipher* cipher, const std::string& password) : filePath(name), cipher(nullptr), configPassword(password)
{
	this->cipher = cipher;
}

PasswordFile::PasswordFile() : filePath(""), configPassword(""), cipher(nullptr)
{}

PasswordFile::~PasswordFile()
{
	delete cipher;
}

void PasswordFile::savePassword(const std::string& site, const std::string& user, const std::string& pass)
{
	std::vector<WebsiteEntity>* entry;
	WebsiteEntity newElem;
	newElem.username = user;
	newElem.password = cipher->encrypt(pass);

	if (!entries.contains(site)) {
		entries.insert(site, std::vector<WebsiteEntity>());
	}

	entry = entries.get(site);
	entry->push_back(newElem);

}

const std::string PasswordFile::loadPassword(const std::string& site, const std::string& user) const
{
	if (!entries.contains(site)) {
		throw std::invalid_argument("No passwords for this site!");
	}

	const std::vector<WebsiteEntity>* entry = entries.get(site);
	std::string pass = "";
	for (int i = 0; i < entry->size(); i++) {
		if (entry->at(i).username == user) {
			pass = entry->at(i).password;
			break;
		}
	}

	if (pass == "") {
		throw std::invalid_argument("No password for this user!");
	}
	

	return cipher->decrypt(pass);
}

const std::vector<WebsiteEntity> PasswordFile::loadAllPasswords(const std::string& site) const
{
	if (!entries.contains(site)) {
		throw std::invalid_argument("No passwords for this site!");
	}
	const std::vector<WebsiteEntity>* entry = entries.get(site);
	return *entry;
}

void PasswordFile::updatePassword(const std::string& site, const std::string& user, const std::string& newPass)
{
	if (!entries.contains(site)) {
		throw std::invalid_argument("No passwords for this site!");
	}

	std::vector<WebsiteEntity>* entry = entries.get(site);
	for (int i = 0; i < entry->size(); i++) {
		if (entry->at(i).username == user) {
			entry->at(i).password = newPass;
			return;
		}
	}

	//code is reached only if such user was not found
	throw std::invalid_argument("No password for this user!");
	

}

void PasswordFile::deletePassword(const std::string& site, const std::string& user)
{
	if (!entries.contains(site)) {
		throw std::invalid_argument("No passwords for this site!");
	}

	std::vector<WebsiteEntity>* entry = entries.get(site);
	for (int i = 0; i < entry->size(); i++) {
		if (entry->at(i).username == user) {
			entry->erase(entry->begin() + i);
			return;
		}
	}

	//code is reached only if such user was not found
	throw std::invalid_argument("No password for this user!");


	
}

void PasswordFile::deserialize(const std::string& path, const std::string& plainText)
{
		std::istringstream ss(plainText);
		std::string line;
		std::string cipherName;
		int lineCount = 0;
		std::string currentSite;

		filePath = path;

		while (std::getline(ss, line)) {
			if (line.empty()) continue;

			if (lineCount == 0) {
				configPassword = line;
			}
			else if (lineCount == 1) {
				cipherName = line;
			}
			else if (lineCount == 2) {
				std::string cipherConfig = line;
				std::vector<std::string> args = parseVector(cipherConfig);

				cipher = CipherFactory::createInstance(cipherName, args);
			}
			else if (line[0] != '\t') {
				// Website line
				currentSite = line;
				if(!entries.contains(currentSite))
					entries.insert(currentSite, std::vector<WebsiteEntity>());
			}
			else {
				// User entry line (tab-separated)
				size_t firstTab = line.find('\t');
				size_t secondTab = line.find('\t', firstTab + 1);

				if (secondTab == std::string::npos) {
					throw std::runtime_error("Error deserializing the file!");
				}

				std::string username = line.substr(firstTab + 1, secondTab - (firstTab + 1));
				std::string password = line.substr(secondTab + 1);

				savePassword(currentSite, username, password);
			}

			lineCount++;
		}
	}


std::string PasswordFile::serialize()
{
	std::string out;

	out += configPassword + "\n";

	out += cipher->getName() + "\n";
	out += "cipherConfig\n";

	for (auto& siteEntry : entries) {
		out += siteEntry.key + "\n";

		for (auto& userEntry : siteEntry.value) {
			out += "\t" + userEntry.username + "\t" + userEntry.password + "\n";
		}

		out += "\n";
	}

	return out;

}

std::string PasswordFile::getConfigPassword() const
{
	return configPassword;
}

std::string PasswordFile::getFilePath() const
{
	return filePath;
}
