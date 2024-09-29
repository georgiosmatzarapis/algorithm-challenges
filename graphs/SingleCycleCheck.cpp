// author: georgiosmatzarapis

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

bool hasSingleCycle(const std::vector<int>& array) {
  const int arraySize{static_cast<int>(array.size())};
  int indexCounter{0};
  std::map<std::size_t, int> board{};

  std::transform(array.begin(), array.end(), std::inserter(board, board.end()),
                 [index = 0](int value) mutable {
                   return std::make_pair(index++, value);
                 });

  while (indexCounter != arraySize) {
    auto tempBoard{board};

    tempBoard.erase(indexCounter);
    int jumpTo{indexCounter + array[indexCounter]};

    for (std::size_t _{1}; _ != arraySize; ++_) {
      // fix indices
      while (jumpTo >= arraySize) {
        jumpTo -= arraySize;
      }
      while (jumpTo < 0) {
        jumpTo += arraySize;
      }

      tempBoard.erase(jumpTo);
      jumpTo += array[jumpTo];
    }

    if (tempBoard.size() != 0) {
      return false;
    }

    ++indexCounter;
  }
  return true;
}

int main() {
  std::cout << (hasSingleCycle({2, 3, 1, -4, -4, 2}) == true) << std::endl;
  std::cout << (hasSingleCycle({3, 5, 5, -5, -2, -5, -12, -2, -1, 2, -6, 1, 1,
                                2, -5, 2}) == false)
            << std::endl;
  std::cout << (hasSingleCycle({10, 11, -6, -23, -2, 3, 88, 908, -26}) == true)
            << std::endl;
  return 0;
}
