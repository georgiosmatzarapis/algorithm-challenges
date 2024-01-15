// author: georgiosmatzarapis

#include <iostream>

class LinkedList {
 public:
  int value{};
  LinkedList* next{};

  LinkedList(int value) : value{value} {}
};

LinkedList* middleNode(LinkedList*& iLinkedList) {
  if (iLinkedList->next == nullptr) {
    return iLinkedList;
  }

  auto aFast{iLinkedList}, aSlow{iLinkedList};

  while (aFast != nullptr && aFast->next != nullptr) {
    aFast = aFast->next->next;
    aSlow = aSlow->next;
  }

  return aSlow;
}

int main() {
  LinkedList* aLinkedList{new LinkedList{2}};
  aLinkedList->next = new LinkedList{7};
  aLinkedList->next->next = new LinkedList{3};
  aLinkedList->next->next->next = new LinkedList{5};
  aLinkedList->next->next->next->next = new LinkedList{8};
  aLinkedList->next->next->next->next->next = new LinkedList{0};

  auto aMiddleNode = middleNode(aLinkedList);

  while (aMiddleNode != nullptr) {
    std::cout << aMiddleNode->value << std::endl;
    aMiddleNode = aMiddleNode->next;
  }

  delete aLinkedList;
  return 0;
}