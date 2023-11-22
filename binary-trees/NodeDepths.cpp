#include <cstdint>
#include <iostream>
#include <numeric>
#include <vector>

class BinaryTree {
 public:
  int value{};
  BinaryTree* left{nullptr};
  BinaryTree* right{nullptr};

  BinaryTree(int value) : value{value} {}
};

void calculateBranchDepth(const BinaryTree* iNode, std::vector<int>& oDepths,
                          int ioCounter) {
  if (iNode == nullptr) {
    return;
  }

  oDepths.push_back(ioCounter);
  ++ioCounter;

  calculateBranchDepth(iNode->left, oDepths, ioCounter);
  calculateBranchDepth(iNode->right, oDepths, ioCounter);
}

int nodeDepths(const BinaryTree* root) {
  std::vector<int> aDepths{};
  calculateBranchDepth(root, aDepths, 0);
  return std::reduce(aDepths.begin(), aDepths.end());
}

int main() {
  auto* aBt = new BinaryTree{1};
  aBt->left = new BinaryTree{2};
  aBt->left->left = new BinaryTree{4};
  aBt->left->left->left = new BinaryTree{8};
  aBt->left->left->right = new BinaryTree{9};
  aBt->left->right = new BinaryTree{5};
  aBt->right = new BinaryTree{3};
  aBt->right->left = new BinaryTree{6};
  aBt->right->right = new BinaryTree{7};

  std::cout << nodeDepths(aBt) << std::endl;
  delete aBt;
  return 0;
}