#include <iostream>
#include <vector>
#define LIMIT 10 

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
  Node* top;
public:
  Stack() { 
  top = nullptr;
  fullStack = false;
  }
  bool fullStack;
  int pop();
  void push(int);
};

void push(int data) {
  Node* newNode = new Node(data);
  if (top == NULL) {
    top = newNode;
  } else {
    Node* temp = top;
    top = newNode;
    top->below = temp;
  }  
}

class ManyStacks {
public: 
  std::vector<Stack> stacks;
  ManyStacks() { 
    Stack newStack;
    stacks.push_back(newStack);
  }
  void push(int);
  int pop();
  Stack currentStack();
}

Stack& ManyStacks::currentStack() {
  return &stacks[stacks.size()];
}

void ManyStacks::push(int data) {
  if (currentStack().fullStack) {
    Stack newStack;
    stacks.push_back(newStack);
    newStack.push(data);
  }
  currentStack().push(data);
}

int main() {
  return 0;
}
