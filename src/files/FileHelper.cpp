#include "FileHelper.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>

bool fileExists(const std::string &filename) {
    std::ifstream file(filename);
    return file.good();
}

std::vector<std::string> getWordsFromFile(const std::string &filename) {
    if (std::filesystem::exists(filename)) {
        std::ifstream myFile(filename);
        std::vector<std::string> words;
        std::string tempWord;
        if (myFile.is_open()) {
            while (myFile >> tempWord) {
                words.push_back(tempWord);
            }
            myFile.close();
        }

        return words;
    }

    std::cerr << "This file does not exist.\n";
    return {};
}

std::vector<std::string> writeWordsIntoFile(const std::string &filename, const std::string &textRow) {
    std::ofstream myFile(filename, std::ios::app);

    if (myFile.is_open()) {
        myFile << textRow << "\n";

        myFile.close();
    }
    else {
        std::cerr << "Error opening file!\n";
    }
}
