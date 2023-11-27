#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

bool classPhotos(std::vector<int>& ioRedShirtHeights,
                 std::vector<int>& ioBlueShirtHeights) {
  std::uint8_t aTallerRedShirtStudents{};
  std::uint8_t aTallerBlueShirtStudents{};
  const size_t aRowLength = ioRedShirtHeights.size();

  std::sort(ioRedShirtHeights.begin(), ioRedShirtHeights.end());
  std::sort(ioBlueShirtHeights.begin(), ioBlueShirtHeights.end());

  for (size_t i = 0; i < aRowLength; ++i) {
    if (ioRedShirtHeights[i] > ioBlueShirtHeights[i]) {
      ++aTallerRedShirtStudents;
      continue;
    }
    if (ioRedShirtHeights[i] < ioBlueShirtHeights[i]) {
      ++aTallerBlueShirtStudents;
      continue;
    }
  }
  return (aTallerRedShirtStudents == aRowLength ||
          aTallerBlueShirtStudents == aRowLength);
}

int main() {
  std::vector<int>* aRedShirtHeights{new std::vector<int>{5, 8, 1, 3, 4}};
  std::vector<int>* aBlueShirtHeights{new std::vector<int>{6, 9, 2, 4, 5}};
  std::cout << classPhotos(*aRedShirtHeights, *aBlueShirtHeights) << std::endl;
  delete aRedShirtHeights;
  delete aBlueShirtHeights;
  return 0;
}