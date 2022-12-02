#include <iostream>

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
  while (cursor->next != NULL) { cursor = cursor->next; }
  cursor->next = newNode;
  return newNode;
}

void Linkedlist::changeNext(Node* nodeToChange) {
  Node* cursor = head;
  int counter = 0;
  while (cursor != NULL && counter < 3) {
    cursor = cursor->next;
    counter++;
  } 
  nodeToChange->next = cursor;
}
void Linkedlist::printList() {
  Node* cursor = head;
  while (cursor != NULL) {
    std::cout << cursor->data << std::endl;
    cursor = cursor->next;
  } //not working reads into random mem TODO
}

int main() {
  Linkedlist list;
  list.insertNode(1);
  list.insertNode(2);
  list.insertNode(3);
  list.insertNode(4);
  list.changeNext(list.insertNode(5));
  list.insertNode(6);
  list.insertNode(7);
  list.insertNode(8);
  list.printList();
}
