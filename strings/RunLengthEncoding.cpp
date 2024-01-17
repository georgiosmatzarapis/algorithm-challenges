// author: georgiosmatzarapis

#include <cstdint>
#include <iostream>

static std::string runLengthEncoding(const std::string& iStr) {
  std::string sRunLengthEncoding{};
  std::size_t sStrSize{iStr.size()};
  std::uint8_t sCounter{};

  for (std::size_t sIndex{}; sIndex != sStrSize; ++sIndex) {
    ++sCounter;
    if (sCounter == 9 || iStr[sIndex] != iStr[sIndex + 1]) {
      const std::string sStrToStore{std::to_string(sCounter) + iStr[sIndex]};
      sRunLengthEncoding += sStrToStore;
      sCounter = 0;
    }
  }

  return sRunLengthEncoding;
}

int main() {
  std::string aStr{runLengthEncoding(
      std::string{"........______=========AAAA   AAABBBB   BBB"})};
  std::cout << (aStr == "8.6_9=4A3 3A4B3 3B") << std::endl;
  return 0;
}