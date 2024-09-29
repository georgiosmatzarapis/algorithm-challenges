// author: georgiosmatzarapis

#include <iostream>

class MinMaxStack final {
 public:
  MinMaxStack(const MinMaxStack&) = delete;
  MinMaxStack& operator=(const MinMaxStack&) = delete;
  MinMaxStack(MinMaxStack&&) = delete;
  MinMaxStack& operator=(MinMaxStack&&) = delete;
  MinMaxStack() = default;
  ~MinMaxStack() {
    while (topNode_) {
      Node* temp{topNode_};
      topNode_ = topNode_->next;
      delete temp;
    }
  }

  int peek() {
    if (topNode_) {
      return topNode_->value;
    }
    return -1;
  }

  int pop() {
    if (topNode_) {
      Node* nodeToDelete{topNode_};
      int toReturn{nodeToDelete->value};
      topNode_ = topNode_->next;
      delete nodeToDelete;
      return toReturn;
    }
    return -1;
  }

  void push(int number) {
    Node* newNode{new Node{number}};

    if (!topNode_) {
      newNode->minValue = number;
      newNode->maxValue = number;
    } else {
      newNode->minValue = std::min(number, topNode_->minValue);
      newNode->maxValue = std::max(number, topNode_->maxValue);
    }

    newNode->next = topNode_;
    topNode_ = newNode;
  }

  int getMin() {
    if (topNode_) {
      return topNode_->minValue;
    }
    return -1;
  }

  int getMax() {
    if (topNode_) {
      return topNode_->maxValue;
    }
    return -1;
  }

 private:
  struct Node {
    int value{};
    int minValue{};
    int maxValue{};
    Node* next{nullptr};
  };

  Node* topNode_{nullptr};
};

int main() {
  MinMaxStack stack{};
  stack.push(5);
  std::cout << stack.getMin() << std::endl;
  std::cout << stack.getMax() << std::endl;
  std::cout << stack.peek() << std::endl;
  stack.push(7);
  std::cout << stack.getMin() << std::endl;
  std::cout << stack.getMax() << std::endl;
  std::cout << stack.peek() << std::endl;
  stack.push(2);
  stack.push(2);
  std::cout << stack.getMin() << std::endl;
  std::cout << stack.getMax() << std::endl;
  std::cout << stack.peek() << std::endl;
  std::cout << stack.pop() << std::endl;
  std::cout << stack.pop() << std::endl;

  return 0;
}
