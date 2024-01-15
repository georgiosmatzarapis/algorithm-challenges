// author: georgiosmatzarapis

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

int minimumWaitingTime(std::vector<int>& ioQueries) {
  std::uint8_t aTotalWaiting{};
  std::sort(ioQueries.begin(), ioQueries.end());

  for (std::vector<int>::iterator it = ioQueries.begin(); it != ioQueries.end();
       ++it) {
    const auto index{std::distance(ioQueries.begin(), it)};
    if (index != 0) {
      for (int i = 0; i < index; ++i) {
        const int& aQuery{ioQueries[i]};
        aTotalWaiting += aQuery;
      }
    }
  }
  return aTotalWaiting;
}

int main() {
  std::vector<int> aQueries{1, 1, 1, 4, 5, 6, 8, 1, 1, 2, 1};
  std::cout << minimumWaitingTime(aQueries) << std::endl;
  return 0;
}