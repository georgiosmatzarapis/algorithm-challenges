// author: georgiosmatzarapis

#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> spiralTraverse(std::vector<std::vector<int>> ioArray) {
  std::vector<int> aSpiralTraversed{};

  while (!ioArray.empty()) {
    // Process and delete top side
    aSpiralTraversed.insert(aSpiralTraversed.end(), ioArray[0].begin(),
                            ioArray[0].end());
    ioArray.erase(ioArray.begin());
    if (ioArray.empty()) {
      break;
    }
    // Process and delete right side
    for (std::size_t aIndex{0}; aIndex != ioArray.size() - 1; ++aIndex) {
      aSpiralTraversed.emplace_back(ioArray[aIndex].back());
      ioArray[aIndex].pop_back();
      if (ioArray[aIndex].empty()) {
        ioArray.erase(ioArray.begin() + aIndex);
        --aIndex;
      }
    }
    // Process and delete bottom side
    aSpiralTraversed.insert(aSpiralTraversed.end(), ioArray.back().rbegin(),
                            ioArray.back().rend());
    ioArray.erase(ioArray.end());
    if (ioArray.empty()) {
      break;
    }
    // Process and delete left side
    for (std::size_t aIndex{ioArray.size() - 1}; aIndex != -1; --aIndex) {
      aSpiralTraversed.emplace_back(ioArray[aIndex].front());
      ioArray[aIndex].erase(ioArray[aIndex].begin());
      if (ioArray[aIndex].empty()) {
        ioArray.erase(ioArray.begin() + aIndex);
      }
    }
  }
  return aSpiralTraversed;
}

int main() {
  std::cout
      << "Test 1: "
      << (spiralTraverse(std::vector<std::vector<int>>{
              {1, 2, 3, 4}, {12, 13, 14, 5}, {11, 16, 15, 6}, {10, 9, 8, 7}}) ==
          std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
                           16})
      << std::endl;
  std::cout << "Test 2: "
            << (spiralTraverse(std::vector<std::vector<int>>{{1}}) ==
                std::vector<int>{1})
            << std::endl;
  std::cout << "Test 3: "
            << (spiralTraverse(std::vector<std::vector<int>>{{1, 2}, {4, 3}}) ==
                std::vector<int>{1, 2, 3, 4})
            << std::endl;
  std::cout << "Test 4: "
            << (spiralTraverse(std::vector<std::vector<int>>{
                    {1, 2, 3}, {8, 9, 4}, {7, 6, 5}}) ==
                std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9})
            << std::endl;
  std::cout << "Test 5: "
            << (spiralTraverse(
                    std::vector<std::vector<int>>{{19, 32, 33, 34, 25, 8},
                                                  {16, 15, 14, 13, 12, 11},
                                                  {18, 31, 36, 35, 26, 9},
                                                  {1, 2, 3, 4, 5, 6},
                                                  {20, 21, 22, 23, 24, 7},
                                                  {17, 30, 29, 28, 27, 10}}) ==
                std::vector<int>{19, 32, 33, 34, 25, 8,  11, 9,  6,  7,  10, 27,
                                 28, 29, 30, 17, 20, 1,  18, 16, 15, 14, 13, 12,
                                 26, 5,  24, 23, 22, 21, 2,  31, 36, 35, 4,  3})
            << std::endl;
  std::cout << "Test 6: "
            << (spiralTraverse(std::vector<std::vector<int>>{
                    {4, 2, 3, 6, 7, 8, 1, 9, 5, 10},
                    {12, 19, 15, 16, 20, 18, 13, 17, 11, 14}}) ==
                std::vector<int>{4,  2,  3,  6,  7,  8,  1,  9,  5,  10,
                                 14, 11, 17, 13, 18, 20, 16, 15, 19, 12})
            << std::endl;
  std::cout
      << "Test 7: "
      << (spiralTraverse(std::vector<std::vector<int>>{{27, 12, 35, 26},
                                                       {25, 21, 94, 11},
                                                       {19, 96, 43, 56},
                                                       {55, 36, 10, 18},
                                                       {96, 83, 31, 94},
                                                       {93, 11, 90, 16}}) ==
          std::vector<int>{27, 12, 35, 26, 11, 56, 18, 94, 16, 90, 11, 93,
                           96, 55, 19, 25, 21, 94, 43, 10, 31, 83, 36, 96})
      << std::endl;
  std::cout << "Test 8: "
            << (spiralTraverse(std::vector<std::vector<int>>{
                    {1, 2, 3, 4}, {10, 11, 12, 5}, {9, 8, 7, 6}}) ==
                std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12})
            << std::endl;
  std::cout
      << "Test 9: "
      << (spiralTraverse(std::vector<std::vector<int>>{
              {1, 2, 3}, {12, 13, 4}, {11, 14, 5}, {10, 15, 6}, {9, 8, 7}}) ==
          std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15})
      << std::endl;
  std::cout << "Test 10: "
            << (spiralTraverse(std::vector<std::vector<int>>{{1, 11},
                                                             {2, 12},
                                                             {3, 13},
                                                             {4, 14},
                                                             {5, 15},
                                                             {6, 16},
                                                             {7, 17},
                                                             {8, 18},
                                                             {9, 19},
                                                             {10, 20}}) ==
                std::vector<int>{1,  11, 12, 13, 14, 15, 16, 17, 18, 19,
                                 20, 10, 9,  8,  7,  6,  5,  4,  3,  2})
            << std::endl;
  std::cout << "Test 11: "
            << (spiralTraverse(
                    std::vector<std::vector<int>>{{1, 3, 2, 5, 4, 7, 6}}) ==
                std::vector<int>{1, 3, 2, 5, 4, 7, 6})
            << std::endl;
  std::cout << "Test 12: "
            << (spiralTraverse(std::vector<std::vector<int>>{
                    {1}, {3}, {2}, {5}, {4}, {7}, {6}}) ==
                std::vector<int>{1, 3, 2, 5, 4, 7, 6})
            << std::endl;
  return 0;
}