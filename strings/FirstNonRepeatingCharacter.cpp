// author: georgiosmatzarapis

#include <cstdint>
#include <iostream>
#include <unordered_set>

static int firstNonRepeatingCharacter(const std::string& iString) {
  const std::size_t sStrSize{iString.size()};
  std::size_t sHelperIndex{};
  std::unordered_set<std::string> sDiscoveredCharacters{};

  for (std::size_t sIndex{}; sIndex != sStrSize; ++sIndex) {
    for (std::size_t sIndexAhead{1 + sHelperIndex}; sIndexAhead != sStrSize;
         ++sIndexAhead) {
      if (iString[sIndex] == iString[sIndexAhead]) {
        sDiscoveredCharacters.insert(std::string(1, iString[sIndex]));
        break;
      }
    }
    if (sDiscoveredCharacters.find(std::string(1, iString[sIndex])) ==
        sDiscoveredCharacters.end()) {
      return static_cast<int>(sIndex);
    }
    ++sHelperIndex;
  }
  return -1;
}

int main() {
  int aResultIndex{
      firstNonRepeatingCharacter(std::string{"lmnopqldsafmnopqsa"})};
  std::cout << (aResultIndex == 7) << std::endl;
  return 0;
}