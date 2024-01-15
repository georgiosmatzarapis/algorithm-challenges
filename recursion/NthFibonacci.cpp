// author: georgiosmatzarapis

#include <iostream>

int getNthFib(const int& iN) {
  if (iN <= 2) {
    return iN - 1;
  } else {
    return getNthFib(iN - 1) + getNthFib(iN - 2);
  }
}

int main() {
  std::cout << getNthFib(10) << std::endl;
  return 0;
}