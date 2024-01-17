// author: georgiosmatzarapis

#include <cstdint>
#include <iostream>

static std::string caesarCypherEncryptor(const std::string& iStr,
                                         const int iKey) {
  std::string sEncryptedStr{};
  const std::size_t sStrSize{iStr.size()};
  std::uint8_t sKeyDifference{};

  for (std::size_t sIndex{}; sIndex != sStrSize; ++sIndex) {
    sKeyDifference = iStr[sIndex] - 'a';
    const int sAsciiCode{(sKeyDifference + iKey) % 26 + 'a'};
    sEncryptedStr.push_back(static_cast<char>(sAsciiCode));
  }

  return sEncryptedStr;
}

int main() {
  std::string aEncryptedStr{caesarCypherEncryptor(std::string{"zzcd"}, 1)};
  std::cout << (aEncryptedStr == "aade") << std::endl;
  return 0;
}