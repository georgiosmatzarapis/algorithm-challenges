// author: georgiosmatzarapis

#include <iostream>

static bool generateDocument(const std::string& iCharacters,
                             std::string ioDocument) {

  for (char sCharacter : iCharacters) {
    const size_t sPosition{ioDocument.find(sCharacter)};
    if (sPosition != std::string::npos) {
      ioDocument.erase(sPosition, 1);
    }
  }

  return ioDocument.size() ? false : true;
}

int main() {
  bool aIsDocumentGenerationPossible{
      generateDocument(std::string{" prAom g:-bleazinm!)"},
                       std::string{"Amazing problem! :-)"})};
  std::cout << aIsDocumentGenerationPossible << std::endl;
  return 0;
}