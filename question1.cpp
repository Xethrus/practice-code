#include <iostream>
class Node {
public:
  int data;
  Node* below;
  Node() { data = 0; below = NULL; }
  Node(int data) {
    this->data = data;
    this->below = NULL;
  }
};
class Stack {
public:
  Node* top;
  int arraySize = 9;
  int array[9] = {1,2,3,4,5,6,7,8,9};
  Node* pop();
  void push(int);
  void peek();
  void fillThreeStacks();
  void printStack();
};

Node* Stack::pop() {
  while (top != NULL) {
    Node* temp = top;
    top = top->below;
    return temp;
  }
  return NULL;
}
void Stack::printStack() {
  Node* temp = pop();
  while (temp != NULL) {
    temp = pop();
    std::cout << "temp: " << temp << std::endl;
    std::cout << "data: " << temp->data << std::endl; 
  }
  return;
}

void Stack::push(int data) {
  Node* newNode = new Node(data);
  if (top != NULL) {
    newNode->below = top;
    top = newNode; 
  } else {
    top = newNode;
  }
  return;
}
void Stack::fillThreeStacks() {
  Stack stack1;
  Stack stack2;
  Stack stack3;
  for (int i = 0; i < arraySize; i += 3) {
    stack1.push(array[i]);
    stack2.push(array[i+1]);
    stack3.push(array[i+2]);
  }
  stack3.printStack();
}
int main() {
  Stack stack;
  stack.fillThreeStacks();
  return 0;
}
