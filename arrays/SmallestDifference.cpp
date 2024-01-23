// author: georgiosmatzarapis

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <vector>

/**
 * @brief Time complexity O(n^2)
 */
std::vector<int>
smallestDifferenceBruteForce(const std::vector<int>& iArrayOne,
                             const std::vector<int>& iArrayTwo) {
  const std::size_t aArraySizeOne{iArrayOne.size()};
  const std::size_t aArraySizeTwo{iArrayTwo.size()};
  std::map<int, std::vector<int>> aDistances{};
  std::vector<int> aCurrentPair{};

  for (std::size_t aIndex1{}; aIndex1 != aArraySizeOne; ++aIndex1) {
    for (std::size_t aIndex2{}; aIndex2 != aArraySizeTwo; ++aIndex2) {
      aCurrentPair = {iArrayOne[aIndex1], iArrayTwo[aIndex2]};
      aDistances.insert(std::make_pair(
          std::abs(aCurrentPair[0] - aCurrentPair[1]), aCurrentPair));
    }
  }
  return aDistances.begin()->second;
}

/**
 * @brief Time complexity O(nlogn)
 */
std::vector<int> smallestDifferenceOptimized(std::vector<int> ioArrayOne,
                                             std::vector<int> ioArrayTwo) {
  std::vector<int> aSmallestDifferencePair{};
  const std::size_t aArraySizeOne{ioArrayOne.size()};
  const std::size_t aArraySizeTwo{ioArrayTwo.size()};
  std::sort(ioArrayOne.begin(), ioArrayOne.end());
  std::sort(ioArrayTwo.begin(), ioArrayTwo.end());
  std::size_t aStartOne{};
  std::size_t aStartTwo{};
  std::uint16_t aCurrentDistance{};
  std::uint16_t aMaxDistance{INT16_MAX};

  while (aStartOne != aArraySizeOne && aStartTwo != aArraySizeTwo) {
    aCurrentDistance = std::abs(ioArrayOne[aStartOne] - ioArrayTwo[aStartTwo]);
    if (aCurrentDistance < aMaxDistance) {
      aMaxDistance = aCurrentDistance;
      aSmallestDifferencePair = {ioArrayOne[aStartOne], ioArrayTwo[aStartTwo]};
    }
    if (ioArrayOne[aStartOne] < ioArrayTwo[aStartTwo]) {
      ++aStartOne;
    } else {
      ++aStartTwo;
    }
  }

  return aSmallestDifferencePair;
}

int main() {
  const std::vector<int> aArrayOne{10, 0, 20, 25};
  const std::vector<int> aArrayTwo{1005, 1006, 1014, 1032, 1031};
  const std::vector<int> aExpectedResult{25, 1005};
  std::vector<int> aSmallestDifferenceBruteForce{
      smallestDifferenceBruteForce(aArrayOne, aArrayTwo)};
  std::vector<int> aSmallestDifferenceOptimized{
      smallestDifferenceOptimized(aArrayOne, aArrayTwo)};
  std::cout << (aSmallestDifferenceBruteForce == aExpectedResult &&
                aSmallestDifferenceOptimized == aExpectedResult)
            << std::endl;
  return 0;
}