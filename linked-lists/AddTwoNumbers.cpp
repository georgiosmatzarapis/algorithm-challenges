#include <algorithm>
#include <cassert>
#include <iostream>

struct ListNode final {
  explicit ListNode() noexcept : value{0}, next{nullptr} {}
  explicit ListNode(int value) noexcept : value{value}, next{nullptr} {}
  explicit ListNode(int value, ListNode* next) noexcept
      : value{value},
        next{next} {}

  int value;
  ListNode* next;
};

std::string findDigits(ListNode* list) {
  std::string digits{};

  while (list != nullptr) {
    digits += std::to_string(list->value);
    list = list->next;
  }

  return {digits.rbegin(), digits.rend()};
}

ListNode*& addTwoNumbers(ListNode* list1, ListNode* list2) {
  const std::string_view sumStr{std::to_string(std::stoll(findDigits(list1)) +
                                               std::stoll(findDigits(list2)))};
  auto* sumList{new ListNode{}};
  auto* currentNode{sumList};

  std::for_each(sumStr.rbegin(), sumStr.rend(),
                [&sumList, &currentNode](char digitChar) {
                  currentNode->next = new ListNode{digitChar - '0'};
                  currentNode = currentNode->next;
                });

  return sumList->next;
}

int main() {
  ListNode node1{3};
  ListNode node2{4, &node1};
  ListNode list1{2, &node2};

  ListNode node3{4};
  ListNode node4{6, &node3};
  ListNode list2{5, &node4};

  ListNode* sumList{addTwoNumbers(&list1, &list2)};

  assert(sumList->value == 7);
  assert(sumList->next->value == 0);
  assert(sumList->next->next->value == 8);
  std::cout << "Test passed\n";

  while (sumList != nullptr) {
    ListNode* temp{sumList};
    sumList = sumList->next;
    delete temp;
  }

  return 0;
}