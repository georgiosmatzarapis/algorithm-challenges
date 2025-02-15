#include <cassert>
#include <iostream>
#include <stack>
#include <vector>

struct TreeNode {
  TreeNode() : val{0}, left{nullptr}, right{nullptr} {}
  explicit TreeNode(int x) : val{x}, left{nullptr}, right{nullptr} {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val{x},
        left{left},
        right{right} {}
  int val;
  TreeNode* left;
  TreeNode* right;
};

std::vector<int> inorderTraversal(TreeNode* root) {
  std::vector<int> inorder{};
  std::stack<TreeNode*> stack{};
  TreeNode* current{root};

  while (current != nullptr || !stack.empty()) {
    while (current != nullptr) {
      stack.push(current);
      current = current->left;
    }

    current = stack.top();
    stack.pop();
    inorder.emplace_back(current->val);

    current = current->right;
  }

  return inorder;
}

int main() {
  auto* root{new TreeNode{1}};
  root->left = new TreeNode{2};
  root->right = new TreeNode{3};
  root->left->left = new TreeNode{4};
  root->left->right = new TreeNode{5};
  root->left->right->left = new TreeNode{6};
  root->left->right->right = new TreeNode{7};
  root->right->right = new TreeNode{8};
  root->right->right->left = new TreeNode{9};

  const std::vector<int> expectedNodeValues{4, 2, 6, 5, 7, 1, 3, 9, 8};
  const std::vector<int> actualNodeValues{inorderTraversal(root)};

  assert(expectedNodeValues.size() == actualNodeValues.size());
  assert(std::equal(expectedNodeValues.begin(), expectedNodeValues.end(),
                    actualNodeValues.begin()));
  std::cout << "Test passed\n";

  // Deletion
  std::stack<TreeNode*> stack{};
  stack.push(root);

  while (!stack.empty()) {
    TreeNode* node{stack.top()};
    stack.pop();

    if (node->left) {
      stack.push(node->left);
    }
    if (node->right) {
      stack.push(node->right);
    }

    delete node;
  }

  root = nullptr;

  return 0;
}