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
  //std::cout << "the power is: " << power << std::endl;
  int multiplier = std::pow(10, power);
  key = multiplier * key;
//  std::cout << "key: " << key << std::endl;
 // std::cout << "multi: " << multiplier << std::endl;
  return key;
}
float Linkedlist::get3DigitNumber() {
  Node* cursor = this->head;
  int counter = 0;
  int value1 = 0;
  int value2 = 0;
  //broken use of function lapping number to huge number somehow
  for(int i = 0; i  < 6; i++) {
    if ( i < 3 ) {
      int number = giveValueZeroes(cursor->data, i);
   //   std::cout << value1 << " += " << number << std::endl;
      value1 += giveValueZeroes(cursor->data, i);
    }
    if ( i >= 3 && i < 6) {
      value2 += giveValueZeroes(cursor->data, i-3);
    }
    //std::cout << "cursor data: " << cursor->data << std::endl;
    cursor = cursor->next;
  }
  //std::cout << "value1: " << value1 << std::endl;
  //std::cout << "value2: " << value2 << std::endl;
  float finalValue = value1 + value2;
  return finalValue;
}
/*
int placeValue(int N, int num) {
  int total = 1, value = 0, rem =0;
  while (true) {
    rem = N % 10;
    N = N / 10;
    if (rem == num) {
      value = total * rem;
      break;
    }
    total = total * 10;
  }
  return value;
}
*/
void Linkedlist::intToNode(int value) {
  int counter = 0;
  int divisor = 10;
  int valueHold = value;
  while (value != 0) {
    std::cout << "value3: " << value << std::endl;
    value = value / divisor;
    counter++;
  }
  int size = counter;
  int places[counter] = {};
  counter = 0;
  std::cout << "value1: " << value << std::endl;
  while (valueHold != 0) {
    (value % divisor);
    std::cout << "value % divisor" << (value & divisor) << std::endl;
    std::cout << "value Hold: " << valueHold << std::endl;
    places[counter] = valueHold;
    valueHold = valueHold / divisor;
    counter++;
  }
  Node* cursor = head;
  //issue TODO
  std::cout << "counter1: " << counter << std::endl;
  //need higher counter- TODO
  for(int i = 0; i < size; i++) {
    std::cout << places[i] << std::endl;
  }
  for(int i = counter + 1; i > 0; i--) {
    while(cursor != NULL) {
      std::cout << "places[i]: " << places[i] << std::endl;
      cursor->data = places[i];
      cursor = cursor->next;
    }
  }
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
  std::cout << list.get3DigitNumber() << std::endl;
  list2.intToNode(list.get3DigitNumber());
  list2.printList();
}
