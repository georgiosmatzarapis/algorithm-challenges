#include <cstdint>
#include <iostream>
#include <vector>

std::vector<std::vector<int>>
transposeMatrix(const std::vector<std::vector<int>>& matrix) {
  std::vector<std::vector<int>> aResult{};
  std::uint8_t aIndex{};
  std::size_t aSingleVectorSize = matrix[0].size();

  for (std::uint8_t i = 0; i < aSingleVectorSize; ++i) {
    std::vector<int> temp{};
    for (const std::vector<int>& aVector : matrix) {
      for (std::uint8_t i = 0; i < aVector.size(); ++i) {
        if (i == aIndex) {
          temp.push_back(aVector.at(i));
        }
      }
    }
    aResult.push_back(temp);
    aIndex++;
  }
  return aResult;
}

int main() {
  auto aResult = transposeMatrix({{1, 2, 3}, {4, 5, 6}});
  for (const std::vector<int>& aVector : aResult) {
    for (const int& aNumber : aVector) {
      std::cout << aNumber << std::endl;
    }
  }
  return 0;
}