// author: georgiosmatzarapis

#include <algorithm>
#include <iostream>
#include <vector>

static std::vector<int> selectionSort(std::vector<int> ioArray) {
  std::size_t sArraySize{ioArray.size()};
  for (std::size_t sIndex{}; sIndex != sArraySize; ++sIndex) {
    std::size_t sMinIndex{sIndex};
    for (std::size_t sIndexAhead{1 + sIndex}; sIndexAhead != sArraySize;
         ++sIndexAhead) {
      if (ioArray[sIndexAhead] < ioArray[sMinIndex]) {
        sMinIndex = sIndexAhead;
      }
    }
    std::swap(ioArray[sIndex], ioArray[sMinIndex]);
  }
  return ioArray;
}

int main() {
  const std::vector<int> aSortedVector{
      selectionSort(std::vector<int>{8, 5, 2, 9, 5, 6, 3})};
  std::for_each(aSortedVector.begin(), aSortedVector.end(),
                [=](int aElement) { std::cout << aElement << std::endl; });
  return 0;
}