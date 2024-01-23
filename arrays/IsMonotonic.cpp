// author: georgiosmatzarapis

#include <cstdint>
#include <iostream>
#include <vector>

bool isMonotonic(const std::vector<int>& iArray) {
  const std::size_t aArraySize{iArray.size()};

  if (!aArraySize || aArraySize == 1) {
    return true;
  }

  std::uint8_t aCounterOne{};
  std::uint8_t aCounterTwo{};

  for (std::size_t aIndex{}; aIndex != aArraySize - 1; ++aIndex) {
    if (iArray[aIndex] >= iArray[aIndex + 1]) {
      ++aCounterOne;
    }
  }
  for (std::size_t aIndex{}; aIndex != aArraySize - 1; ++aIndex) {
    if (iArray[aIndex] <= iArray[aIndex + 1]) {
      ++aCounterTwo;
    }
  }
  if (aCounterOne == (aArraySize - 1) || aCounterTwo == (aArraySize - 1)) {
    return true;
  }
  return false;
}

int main() {
  std::cout << (isMonotonic(std::vector<int>{1, 2}) == true) << std::endl;
  return 0;
}