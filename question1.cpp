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

  Node* pop();
  void push(int);
  void peek();
};

Node* Stack::pop() {
  if (top == NULL) {
    return NULL;
  }
  return top;
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

int main() {
  Stack stack;
  stack.push(1);
  stack.push(1);
  stack.push(1);
  stack.push(1);
  stack.push(1);
  stack.push(1);
  stack.push(1);
  stack.push(1);
  return 0;
}
