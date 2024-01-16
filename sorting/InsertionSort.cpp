// author: georgiosmatzarapis

#include <algorithm>
#include <iostream>
#include <vector>

static std::vector<int> insertionSort(std::vector<int> ioArray) {
  const std::size_t sArraySize{ioArray.size()};
  for (std::size_t sIndex{1}; sIndex != sArraySize; ++sIndex) {
    if (ioArray[sIndex - 1] > ioArray[sIndex]) {
      std::size_t sTempIndex{sIndex};
      while (ioArray[sTempIndex - 1] >= ioArray[sTempIndex] &&
             sTempIndex != 0) {
        std::swap(ioArray[sTempIndex - 1], ioArray[sTempIndex]);
        --sTempIndex;
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