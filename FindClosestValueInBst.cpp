#include <iostream>

class BST {
 public:
  int value;
  BST* left{nullptr};
  BST* right{nullptr};

  BST(int val) : value(val){};
  BST& insert(int val);
};

int findClosestValueInBst(BST* tree, int target) {
  int aClosest{tree->value};

  while (tree != nullptr) {
    if (std::abs(target - aClosest) > std::abs(target - tree->value)) {
      aClosest = tree->value;
    }
    if (target > tree->value) {
      tree = tree->right;
    } else {
      tree = tree->left;
    }
  }
  return aClosest;
}

int main() {
  BST* aRoot = new BST(10);
  aRoot->left = new BST(5);
  aRoot->left->left = new BST(2);
  aRoot->left->left->left = new BST(1);
  aRoot->left->right = new BST(5);
  aRoot->right = new BST(15);
  aRoot->right->left = new BST(13);
  aRoot->right->left->right = new BST(14);
  aRoot->right->right = new BST(22);

  auto aResult = findClosestValueInBst(aRoot, 12);
  std::cout << aResult << std::endl;

  delete aRoot;
  return 0;
}