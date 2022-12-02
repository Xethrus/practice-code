#include <iostream>
#include <vector>

class Node {
public:
  int data;
  Node* next;
  Node() { data = 0; next = NULL; }
  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

class Linkedlist {
  Node* head;
public:
  Linkedlist() { 
    head = NULL;
  }
  void changeNext(Node*); 
  Node* findNodeRepeat();
  Node* insertNode(int);
  void printList();
};

Node* Linkedlist::insertNode(int data) {
  Node* newNode = new Node(data);
  if (head == NULL) {
    head = newNode;
    return head;
  }
  Node* cursor = head;
  Node* exampleNode;
  while (cursor != NULL) { 
    cursor = cursor->next; 
    exampleNode = findNodeRepeat();
    std::cout << exampleNode->data << std::endl;
    if(findNodeRepeat() == cursor) {
      cursor->next = newNode;
      return newNode;
    }
  }
  cursor->next = newNode;
}
Node* Linkedlist::findNodeRepeat() {
  Node* cursor = head;
  std::vector<Node*> nodes;
  while (cursor != NULL) {
    for(auto& node : nodes) {
      if (cursor == node) {
        return node;
      }
    }
    nodes.push_back(cursor);
    cursor = cursor->next;
  }
}
/*Node* Linkedlist::findNodeRepeat() {
  Node* cursor = head;
  std::vector<Node *> nodesFound;
  std::vector<Node *>::iterator finder;
  while (cursor != NULL) {
    finder = std::find(nodesFound.begin(), nodesFound.end(),cursor);
    if(finder != nodesFound.end()) {
      return nodesFound[finder- nodesFound.begin()];
    } else {
      nodesFound.push_back(cursor);
      cursor = cursor->next;
    }
  }
}
*/
void Linkedlist::printList() {
  Node* cursor = head;
  while (cursor != NULL) {
    std::cout << cursor->data << std::endl;
    cursor = cursor->next;
  } 
  std::cout << cursor->data << std::endl;

}

int main() {
  Linkedlist list;
  list.insertNode(1);
  list.insertNode(2);
  list.insertNode(3);
  list.insertNode(4);
  Node *a = list.insertNode(5);
  list.insertNode(6);
  Node *c = list.insertNode(7);
  c->next = a;
  list.insertNode(7);
  list.insertNode(8);
  list.findNodeRepeat();
  list.printList();
}
