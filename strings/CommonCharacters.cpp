// author: georgiosmatzarapis

#include <cstdint>
#include <iostream>
#include <unordered_set>
#include <vector>

static std::vector<std::string>
commonCharacters(const std::vector<std::string>& iStrings) {
  std::unordered_set<std::string> sUniqueChars{};

  for (const std::string& sString : iStrings) {
    const std::size_t sStrSize{sString.size()};
    for (std::size_t sIndex{}; sIndex != sStrSize; ++sIndex) {
      sUniqueChars.insert(std::string(1, sString[sIndex]));
    }
  }

  std::uint8_t sCounter{};
  const std::size_t sInputSize{iStrings.size()};
  std::vector<std::string> sCommonCharacters{};

  for (const std::string& sUniqueChar : sUniqueChars) {
    for (const std::string& sString : iStrings) {
      if (sString.find(sUniqueChar) != std::string::npos) {
        ++sCounter;
      }
    }
    if (sCounter == sInputSize) {
      sCommonCharacters.push_back(sUniqueChar);
    }
    sCounter = 0;
  }

  return sCommonCharacters;
}

int main() {
  std::vector<std::string> aRes{
      commonCharacters(std::vector<std::string>{"abc", "bcd", "cbad"})};
  std::cout << (aRes == std::vector<std::string>{"c", "b"}) << std::endl;
  return 0;
}