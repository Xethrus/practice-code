#include <iostream>
#include <cmath>

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
  Linkedlist() { head = NULL; }

  void insertNode(int);
  void printList();
  int get3DigitNumber();
};

void Linkedlist::insertNode(int data) {
  Node* newNode = new Node(data);
  if (head == NULL) {
    head = newNode;
    return;
  }
  Node* temp = head;
  while (temp->next != NULL) { temp = temp->next; }
  temp->next = newNode;
}
int giveValueZeroes(int key, int power) {
  std::cout << "the power is: " << power << std::endl;
  int multiplier = std::pow(10, power);
  key = multiplier * key;
  return key;
}
int Linkedlist::get3DigitNumber() {
  Node* cursor = this->head;
  int counter = 0;
  int value1;
  int value2;
  //broken use of function lapping number to huge number somehow
  for(int i = 0; i  < 3; i++) {
    value1 = value1 + giveValueZeroes(cursor->data, i);
    std::cout << "cursor data: " << cursor->data << std::endl;
    cursor = cursor->next;
    }
  for(int i = 0; i < 3; i++) {
    value2 = value2 + giveValueZeroes(cursor->data, i);
    std::cout << "value2 in for loop: " << value2 << std::endl;
    std::cout << "cursor data: " <<  cursor->data << std::endl;
    cursor = cursor->next;
  }
  std::cout << "value1: " << value1 << std::endl;
  std::cout << "value2: " << value2 << std::endl;
  int finalValue = value1 + value2;
  return finalValue;
}

int main() {
  Linkedlist list;
  list.insertNode(1);
  list.insertNode(2);
  list.insertNode(3);
  list.insertNode(4);
  list.insertNode(5);
  list.insertNode(6);
  list.get3DigitNumber();
}