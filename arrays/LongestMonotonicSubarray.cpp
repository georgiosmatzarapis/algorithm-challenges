#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

int longestMonotonicSubarray(const std::vector<int>& nums) {
  if (nums.empty()) {
    return 0;
  }

  const std::size_t numCount{nums.size()};
  std::size_t counterI{1};
  std::size_t counterD{1};
  std::size_t maxLength{1};

  for (std::size_t numberIndex{1}; numberIndex < numCount; ++numberIndex) {
    if (nums[numberIndex - 1] < nums[numberIndex]) {
      ++counterI;
      counterD = 1;
    } else if (nums[numberIndex - 1] > nums[numberIndex]) {
      ++counterD;
      counterI = 1;
    } else {
      counterI = 1;
      counterD = 1;
    }
    maxLength = std::max(maxLength, std::max(counterD, counterI));
  }

  return maxLength;
}

int main() {
  assert(longestMonotonicSubarray({1, 4, 3, 3, 2}) == 2);
  assert(longestMonotonicSubarray({1}) == 1);
  assert(longestMonotonicSubarray({5, 4, 3, 2, 1}) == 5);
  assert(longestMonotonicSubarray({1, 2, 3, 4, 5}) == 5);

  std::cout << "All tests passed\n";
  return 0;
}