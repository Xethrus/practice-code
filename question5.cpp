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
  float get3DigitNumber();
  void intToNode(int); 
  void buildLinked(int *);
  //int reduceInts(int);
};
int * intToArray(int number) {
  int divisor = 10;
  int count = 0;
  int temp = number;
  while (number / divisor > 0) {
    number = number / divisor;
    count++;
  }
  //lookout for array being too small
  int array[count] = {};
  for (int i = 1; i <= count + 1; i++) {
    int power = std::pow(divisor, i);
    array[i-1] = (temp % power);
  }
  return array;
}
int reduceInts(int value) {
  while (value / 10 > 0) {
    value = value / 10;
  }
  return value;
}
int * cycleArray(int * array) {
  int counter = 0;
  int size = sizeof(array) / 4;
  for (int i = 0; i < size; i++) {
    array[i] = reduceInts(array[i]);
  }
  return array;
}
void Linkedlist::buildLinked(int * array) {
  int size = sizeof(array) / 4;
  Node* cursor = head; 
  for(int i = 0; i < size; i++) {
    if(cursor == NULL) {
      break;
    } else {
      cursor->data = array[i];
      cursor = cursor->next; 
    } 
  }
}
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
  int multiplier = std::pow(10, power);
  key = multiplier * key;
  return key;
}
float Linkedlist::get3DigitNumber() {
  Node* cursor = this->head;
  int counter = 0;
  int value1 = 0;
  int value2 = 0;
  for(int i = 0; i  < 6; i++) {
    if ( i < 3 ) {
      int number = giveValueZeroes(cursor->data, i);
      value1 += giveValueZeroes(cursor->data, i);
    }
    if ( i >= 3 && i < 6) {
      value2 += giveValueZeroes(cursor->data, i-3);
    }
    cursor = cursor->next;
  }
  float finalValue = value1 + value2;
  return finalValue;
}
void Linkedlist::printList() {
  Node* cursor = head;
  std::cout << "running1" << std::endl;
  while (cursor != NULL) {
    std::cout << "should be stuff here" << std::endl;
    std::cout << cursor->data << std::endl;
    cursor = cursor->next;
  }
}
int main() {
  Linkedlist list;
  list.insertNode(1);
  list.insertNode(2);
  list.insertNode(3);
  list.insertNode(4);
  list.insertNode(5);
  list.insertNode(6);
  Linkedlist list2;
  list2.buildLinked(cycleArray(intToArray(list.get3DigitNumber())));
  list2.printList();
}
