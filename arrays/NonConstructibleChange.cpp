#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

int nonConstructibleChange(std::vector<int>& coins) {
  std::sort(coins.begin(), coins.end());
  std::uint8_t aSum{};
  for (const auto& aCoin : coins) {
    if (aCoin > (aSum + 1)) {
      return (aSum + 1);
    } else {
      aSum += aCoin;
    }
  }
  return (aSum + 1);
}

int main() {
  std::vector<int> aCoins{5, 7, 1, 1, 2, 3, 22};
  std::uint8_t aResult = nonConstructibleChange(aCoins);
  std::cout << static_cast<int>(aResult) << std::endl;
  return 0;
}