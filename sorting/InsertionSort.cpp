// author: georgiosmatzarapis

#include <algorithm>
#include <iostream>
#include <vector>

static std::vector<int> insertionSort(std::vector<int> ioArray) {
  const std::size_t aArraySize{ioArray.size()};
  for (std::size_t aIndex{1}; aIndex != aArraySize; ++aIndex) {
    if (ioArray[aIndex - 1] > ioArray[aIndex]) {
      std::size_t aTempIndex{aIndex};
      while (ioArray[aTempIndex - 1] >= ioArray[aTempIndex] &&
             aTempIndex != 0) {
        std::swap(ioArray[aTempIndex - 1], ioArray[aTempIndex]);
        --aTempIndex;
      }
    }
  }
  return ioArray;
}

int main() {
  const std::vector<int> aSortedVector{
      insertionSort(std::vector<int>{-4, 5, 10, 8, -10, -6, -4, -2, -5, 3})};
  std::for_each(aSortedVector.begin(), aSortedVector.end(),
                [=](int aElement) { std::cout << aElement << std::endl; });
  return 0;
}