// author: georgiosmatzarapis

#include <algorithm>
#include <iostream>
#include <vector>

static const std::vector<int>
findThreeLargestNumbers(std::vector<int>& ioArray) {
  std::vector<int> sLargestNumbers{};
  int sCounter{};

  while (sCounter != 3) {
    std::vector<int>::iterator sMax{
        std::max_element(ioArray.begin(), ioArray.end())};
    sLargestNumbers.push_back(*sMax);
    ioArray.erase(std::remove(ioArray.begin(), ioArray.end(), *sMax),
                  ioArray.end());
    ++sCounter;
  }

  std::sort(sLargestNumbers.begin(), sLargestNumbers.end());
  return sLargestNumbers;
}

int main() {
  std::vector<int> aInput{141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7};
  std::vector<int> aResult{findThreeLargestNumbers(aInput)};
  std::for_each(aResult.begin(), aResult.end(),
                [](const int& aInt) { std::cout << aInt << std::endl; });
  return 0;
}