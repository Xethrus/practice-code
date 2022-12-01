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
  Node* last;
public:
  Linkedlist() { 
    head = NULL;
    last->next = head;
  }
  
  void insertNode(int);
  void printList();
};

void Linkedlist::insertNode(int data) {
  Node* newNode = new Node(data);
  if (head == NULL) {
    head = newNode;
    head->next = last;
    return;
  }
  Node* cursor = head;
  while (cursor->next != last) { cursor = cursor->next; }
  cursor->next = newNode;
  newNode->next = last;
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
  list.insertNode(5);
  list.insertNode(6);
  list.insertNode(7);
  list.insertNode(8);
  list.printList();
}
