// author: georgiosmatzarapis

#include <algorithm>
#include <iostream>
#include <vector>

static const std::vector<int> bubbleSort(std::vector<int> ioArray) {
  std::size_t sArraySize{ioArray.size()};
  bool sIsSwapped{};

  for (std::size_t sIndex1{}; sIndex1 < sArraySize - 1; ++sIndex1) {
    sIsSwapped = false;
    for (std::size_t sIndex2{}; sIndex2 < sArraySize - sIndex1 - 1; ++sIndex2) {
      if (ioArray[sIndex2] > ioArray[sIndex2 + 1]) {
        std::swap(ioArray[sIndex2], ioArray[sIndex2 + 1]);
        sIsSwapped = true;
      }
    }
    if (sIsSwapped == false) {
      break;
    }
  }

  return ioArray;
}

int main() {
  std::vector<int>* aUnsortedVector{new std::vector<int>{6, 3, 2, 9, 10, 2, 0}};
  const std::vector<int> aSortedVector{bubbleSort(*aUnsortedVector)};
  std::for_each(aSortedVector.begin(), aSortedVector.end(),
                [](const int aInt) { std::cout << aInt << std::endl; });
  delete aUnsortedVector;
  return 0;
}