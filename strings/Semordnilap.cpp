// author: georgiosmatzarapis

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

static std::vector<std::vector<std::string>>
semordnilap(const std::vector<std::string>& iWords) {
  std::multimap<std::size_t, std::string> sWordsSizes{};

  std::for_each(iWords.begin(), iWords.end(), [&](const std::string& sWord) {
    sWordsSizes.insert(std::make_pair(sWord.size(), sWord));
  });

  std::vector<std::vector<std::string>> sSemordnilaps{};

  for (auto sIterator{sWordsSizes.begin()}; sIterator != sWordsSizes.end();
       ++sIterator) {
    auto sNextIterator{std::next(sIterator)};
    if (sNextIterator != sWordsSizes.end()) {
      const auto sFirstIteratorWithSameSize{sIterator};
      while (sIterator->first == sNextIterator->first) {
        if (sFirstIteratorWithSameSize->first == sNextIterator->first) {
          const std::string sNextWordReverted{sNextIterator->second.rbegin(),
                                              sNextIterator->second.rend()};
          if (sFirstIteratorWithSameSize->second == sNextWordReverted) {
            sSemordnilaps.emplace_back(std::vector<std::string>{
                sFirstIteratorWithSameSize->second, sNextIterator->second});
            sIterator = sNextIterator;
            break;
          }
          ++sIterator;
          ++sNextIterator;
        }
      }
    }
  }
  return sSemordnilaps;
}

int main() {
  std::vector<std::vector<std::string>> aSemordnilaps{semordnilap(
      std::vector<std::string>{"liver", "dog", "hello", "desserts", "evil",
                               "test", "god", "stressed", "racecar",
                               "palindromes", "semordnilap", "abcd", "live"})};
  std::cout << (aSemordnilaps ==
                std::vector<std::vector<std::string>>{
                    {"dog", "god"},
                    {"evil", "live"},
                    {"desserts", "stressed"},
                    {"palindromes", "semordnilap"}})
            << std::endl;
  return 0;
}