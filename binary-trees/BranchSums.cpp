// author: georgiosmatzarapis

#include <cstdint>
#include <iostream>
#include <vector>

class BinaryTree {
 public:
  int value{};
  BinaryTree* left{nullptr};
  BinaryTree* right{nullptr};

  BinaryTree(int value) : value{value} {}
};

void calculateBranchSums(const BinaryTree* iNode, const int iRunningSum,
                         std::vector<int>& oSums) {
  if (iNode == nullptr) {
    return;
  }
  int running = iRunningSum + iNode->value;

  if (iNode->left == nullptr && iNode->right == nullptr) {
    oSums.push_back(running);
  }
  calculateBranchSums(iNode->left, running, oSums);
  calculateBranchSums(iNode->right, running, oSums);
}

std::vector<int> branchSums(const BinaryTree* root) {
  std::vector<int> aSums{};
  calculateBranchSums(root, 0, aSums);
  return aSums;
}

int main() {
  auto* aBinaryTree = new BinaryTree{1};
  aBinaryTree->left = new BinaryTree{2};
  aBinaryTree->left->left = new BinaryTree{4};
  aBinaryTree->left->left->left = new BinaryTree{8};
  aBinaryTree->left->left->right = new BinaryTree{9};
  aBinaryTree->left->right = new BinaryTree{5};
  aBinaryTree->left->right->left = new BinaryTree{10};
  aBinaryTree->right = new BinaryTree{3};
  aBinaryTree->right->left = new BinaryTree{6};
  aBinaryTree->right->right = new BinaryTree{7};

  std::vector<int> aResult = branchSums(aBinaryTree);
  for (const int& aInt : aResult) {
    std::cout << aInt << std::endl;
  }
  delete aBinaryTree;
  return 0;
}