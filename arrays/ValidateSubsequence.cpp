// author: georgiosmatzarapis

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

bool isValidSubsequence(std::vector<int> array, std::vector<int> sequence) {
  std::size_t aSequenceSize = sequence.size();
  std::uint8_t aCounter{};
  std::uint8_t aIndex{};

  for (std::vector<int>::iterator it = std::begin(array); it != std::end(array);
       ++it) {
    if (aIndex <= aSequenceSize - 1) {
      if (*it == sequence.at(aIndex)) {
        aIndex++;
        aCounter += 1;
      }
    }
  }
  if (aCounter == aSequenceSize) {
    return true;
  }
  return false;
}

int main() {
  auto aIsValid =
      isValidSubsequence(std::vector<int>{5, 1, 22, 25, 6, -1, 8, 10},
                         std::vector<int>{22, 25, 6});
  std::cout << aIsValid << std::endl;
  return 0;
}