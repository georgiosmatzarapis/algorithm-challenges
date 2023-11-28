#include <iostream>

class LinkedList {
 public:
  int value{};
  LinkedList* next{};

  LinkedList(int value) : value{value} {}
};

LinkedList* removeDuplicatesFromLinkedList(LinkedList*& ioLinkedList) {
  LinkedList* aNode{ioLinkedList};
  int aPreviousValue{};
  LinkedList* aPreviousNode{};

  while (aNode != nullptr) {
    if (aNode->value == aPreviousValue) {
      aPreviousNode->next = aNode->next;
      aNode = aPreviousNode->next;
    } else {
      aPreviousNode = aNode;
      aPreviousValue = aNode->value;
      aNode = aNode->next;
    }
  }
  return ioLinkedList;
}

int main() {
  LinkedList* aLinkedList{new LinkedList{1}};
  aLinkedList->next = new LinkedList{1};
  aLinkedList->next->next = new LinkedList{3};
  aLinkedList->next->next->next = new LinkedList{4};
  aLinkedList->next->next->next->next = new LinkedList{4};
  aLinkedList->next->next->next->next->next = new LinkedList{4};
  aLinkedList->next->next->next->next->next->next = new LinkedList{5};
  aLinkedList->next->next->next->next->next->next->next = new LinkedList{6};
  aLinkedList->next->next->next->next->next->next->next->next =
      new LinkedList{6};

  LinkedList* aNoDuplicates{removeDuplicatesFromLinkedList(aLinkedList)};

  while (aNoDuplicates != nullptr) {
    std::cout << aNoDuplicates->value << std::endl;
    aNoDuplicates = aNoDuplicates->next;
  }

  delete aLinkedList;
  return 0;
}