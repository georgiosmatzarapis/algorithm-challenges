#include <cstdint>
#include <iostream>
#include <vector>

class Node {
 public:
  std::string name{};
  std::vector<Node*> children{};

  Node(std::string str) : name{str} {}

  void searchHelper(Node*& iGraph, std::vector<std::string>*& ioArray) {
    if (iGraph == nullptr) {
      return;
    }
    for (std::vector<Node*>::iterator it = iGraph->children.begin();
         it != iGraph->children.end(); ++it) {
      auto aNode = *it;
      ioArray->push_back(aNode->name);
      searchHelper(aNode, ioArray);
    }
  }

  std::vector<std::string> depthFirstSearch(std::vector<std::string>* array) {
    Node* aGraph{this};
    array->push_back(aGraph->name);
    searchHelper(aGraph, array);
    return *array;
  }

  Node* addChild(std::string name) {
    Node* child = new Node(name);
    children.push_back(child);
    return this;
  }

  ~Node() {
    for (const auto& child : children) {
      delete child;
    }
  }
};

int main() {
  auto* aGraph = new Node{"A"};
  aGraph->addChild("B")->addChild("C")->addChild("D");
  aGraph->children[0]->addChild("E")->addChild("F");
  aGraph->children[2]->addChild("G")->addChild("H");
  aGraph->children[0]->children[1]->addChild("I")->addChild("J");
  aGraph->children[2]->children[0]->addChild("K");

  std::vector<std::string> aVector{};
  for (const std::string& aNode : aGraph->depthFirstSearch(&aVector)) {
    std::cout << aNode << std::endl;
  }

  delete aGraph;
  return 0;
}