// author: georgiosmatzarapis

#include <algorithm>
#include <iostream>
#include <vector>

static std::vector<std::vector<int>> threeNumberSum(std::vector<int> ioArray,
                                                    const int iTargetSum) {
  std::vector<std::vector<int>> sTriplets{};
  const std::size_t sArraySize{ioArray.size()};
  std::sort(ioArray.begin(), ioArray.end());

  for (std::size_t sIndex{}; sIndex != sArraySize - 2; ++sIndex) {
    std::size_t sLeft{sIndex + 1};
    std::size_t sRight{sArraySize - 1};
    while (sLeft < sRight) {
      const int sCurrentSum{ioArray[sIndex] + ioArray[sLeft] + ioArray[sRight]};
      if (sCurrentSum == iTargetSum) {
        sTriplets.emplace_back(
            std::vector<int>{ioArray[sIndex], ioArray[sLeft], ioArray[sRight]});
        ++sLeft;
        --sRight;
      } else if (sCurrentSum < iTargetSum) {
        ++sLeft;
      } else if (sCurrentSum > iTargetSum) {
        --sRight;
      }
    }
  }
  return sTriplets;
}

int main() {
  std::vector<std::vector<int>> aTriplets{
      threeNumberSum(std::vector<int>{12, 3, 1, 2, -6, 5, -8, 6}, 0)};
  std::cout << (aTriplets == std::vector<std::vector<int>>{{-8, 2, 6},
                                                           {-8, 3, 5},
                                                           {-6, 1, 5}})
            << std::endl;
  return 0;
}