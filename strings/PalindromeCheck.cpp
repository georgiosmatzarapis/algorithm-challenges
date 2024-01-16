// author: georgiosmatzarapis

#include <algorithm>
#include <cstdint>
#include <iostream>

static bool isPalindrome(const std::string& iStr) {
  std::uint8_t sIndex{};
  const std::size_t sStringSize{iStr.size()};
  sIndex = (sStringSize % 2 == 1) ? 1 : 0;

  std::string sFirstPiece{iStr.substr(0, sStringSize / 2)};
  std::string sSecondPiece{iStr.substr(sStringSize / 2 + sIndex, -1)};
  std::reverse(sSecondPiece.begin(), sSecondPiece.end());

  return (sFirstPiece == sSecondPiece) ? true : false;
}

int main() {
  std::cout << isPalindrome(std::string{"abcdcba"}) << std::endl;
  return 0;
}