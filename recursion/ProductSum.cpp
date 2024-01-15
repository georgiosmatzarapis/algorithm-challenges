// author: georgiosmatzarapis

#include <any>
#include <cstdint>
#include <iostream>
#include <vector>

static const std::type_info& sIntTypeId{typeid(int)};

static std::uint16_t CalculateSum(std::uint16_t ioSum, std::uint8_t& ioCounter,
                                  const std::vector<std::any>& iArray) {
  for (const std::any& sItem : iArray) {
    if (sItem.type() == sIntTypeId) {
      ioSum += std::any_cast<int>(sItem);
    } else {
      ++ioCounter;
      ioSum +=
          ioCounter * CalculateSum(0, ioCounter,
                                   std::any_cast<std::vector<std::any>>(sItem));
      --ioCounter;
    }
  }
  return ioSum;
}

int productSum(const std::vector<std::any>& iArray) {
  std::uint16_t aSum{};
  std::uint8_t aCounter{1};
  return CalculateSum(aSum, aCounter, iArray);
}

int main() {
  const std::vector<std::any> aVector{
      5, 2, std::vector<std::any>{7, -1}, 3,
      std::vector<std::any>{6, std::vector<std::any>{-13, 8}, 4}};
  std::cout << productSum(aVector) << std::endl;
  return 0;
}