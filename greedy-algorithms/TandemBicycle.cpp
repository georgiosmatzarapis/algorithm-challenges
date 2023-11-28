#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

int tandemBicycle(std::vector<int>& ioRedShirtSpeeds,
                  std::vector<int>& ioBlueShirtSpeeds, const bool& iFastest) {
  const std::size_t aTimeSize{ioRedShirtSpeeds.size()};
  if (iFastest) {
    std::sort(ioRedShirtSpeeds.begin(), ioRedShirtSpeeds.end());
  } else {
    std::sort(ioRedShirtSpeeds.begin(), ioRedShirtSpeeds.end(),
              std::greater<int>());
  }
  std::sort(ioBlueShirtSpeeds.begin(), ioBlueShirtSpeeds.end(),
            std::greater<int>());

  std::uint16_t aTotalSpeed{};
  for (std::size_t i{0}; i < aTimeSize; ++i) {
    aTotalSpeed += std::max(ioRedShirtSpeeds[i], ioBlueShirtSpeeds[i]);
  }
  return aTotalSpeed;
}

int main() {
  std::vector<int> aRedShirtSpeeds{1, 2, 1, 9, 12, 3, 1, 54, 21, 231, 32, 1};
  std::vector<int> aBlueShirtSpeeds{3, 3, 4, 6, 1, 2, 5, 6, 34, 256, 123, 32};
  bool aIsFastest{true};
  std::cout << tandemBicycle(aRedShirtSpeeds, aBlueShirtSpeeds, aIsFastest)
            << std::endl;
  return 0;
}