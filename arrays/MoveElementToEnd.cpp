// author: georgiosmatzarapis

#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> moveElementToEnd(std::vector<int> ioArray, const int iToMove) {
  std::partition(ioArray.begin(), ioArray.end(),
                 [=](const int aInt) { return aInt != iToMove; });
  return ioArray;
}

int main() {
  std::cout << (moveElementToEnd(std::vector<int>{2, 1, 2, 2, 2, 3, 4, 2}, 2) ==
                std::vector<int>{4, 1, 3, 2, 2, 2, 2, 2})
            << std::endl;
  return 0;
}