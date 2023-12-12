#include <algorithm>
#include <iostream>
#include <vector>

static const int binarySearch(std::vector<int>& ioArray, const int& iTarget) {
  const std::vector<int> sInitArray{ioArray};

  while (ioArray.size() != 0) {
    if (ioArray.size() == 1) {
      return [&]() -> int { return (ioArray[0] == iTarget) ? 0 : -1; }();
    }
    const std::vector<int>::const_iterator sMid{ioArray.begin() +
                                                (ioArray.size() / 2)};
    if (iTarget == *sMid) {
      const std::vector<int>::const_iterator aIntInInitArray{
          std::find(sInitArray.begin(), sInitArray.end(), iTarget)};
      return static_cast<int>(aIntInInitArray - sInitArray.begin());
    } else {
      const long sMidIndex{sMid - ioArray.begin()};
      if (iTarget > *sMid) {
        ioArray = std::vector<int>(ioArray.begin() + sMidIndex, ioArray.end());
      } else {
        ioArray = std::vector<int>(ioArray.begin(), ioArray.end() - sMidIndex);
      }
    }
  }
  return -1;
}

int main() {
  std::vector<int> aVector{1, 2, 21, 33, 45, 45, 61, 71, 72, 73};
  std::cout << binarySearch(aVector, 33) << std::endl;
  return 0;
}