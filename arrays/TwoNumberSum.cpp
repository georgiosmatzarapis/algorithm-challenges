// author: georgiosmatzarapis

#include <iostream>
#include <vector>

std::vector<int> twoNumberSum(std::vector<int> array, int targetSum) {
  for(std::vector<int>::iterator it1 = std::begin(array);
      it1 != std::end(array); ++it1) {
    for(std::vector<int>::iterator it2 = std::begin(array);
        it2 != std::end(array); ++it2) {
      if(*it1 != *it2) {
        int temp_sum{};
        temp_sum = *it1 + *it2;
        if(temp_sum == targetSum) {
          return std::vector<int>{*it1, *it2};
        }
      }
    }
  }

  return {};
}

int main() {
  std::vector<int> aSum = twoNumberSum(std::vector<int>{1, 2, 4, 5}, 9);
  for(const int& i : aSum) {
    std::cout << i << std::endl;
  }
  return 0;
}