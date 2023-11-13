#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> sortedSquaredArray(std::vector<int> array) {
  std::vector<int> aResult{};
  for (const auto& i : array) {
    aResult.push_back(i * i);
  }
  std::sort(aResult.begin(), aResult.end());
  return aResult;
}

int main() {
  auto aResult = sortedSquaredArray(std::vector<int>{-10});
  for (const auto& i : aResult) {
    std::cout << i << std::endl;
  }
  return 0;
}
