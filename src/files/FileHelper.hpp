#pragma once

#include <vector>
#include <string>

bool fileExists(const std::string& filename);
std::vector<std::string> getWordsFromFile(const std::string& filename);
std::vector<std::string> writeWordsIntoFile(const std::string& filename, const std::string& textRow);
