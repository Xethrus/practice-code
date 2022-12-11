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
  Node* getTop();
};

Node* Stack::getTop() {
  return top;
}

void Stack::push(int data) {
  Node* newNode = new Node(data);
  if (top == NULL) {
    top = newNode;
  } else {
    Node* temp = top;
    top = newNode;
    top->below = temp;
  }  
}

int Stack::pop() {
  if (top == NULL) { return 1; }
  Node* temp = top;
  top = top->below;
  return temp->data;
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
  Stack& currentStack();
  void printAll();
};

Stack& ManyStacks::currentStack() {
  return stacks[stacks.size()];
}

void ManyStacks::push(int data) {
  if (currentStack().fullStack) {
    Stack newStack;
    stacks.push_back(newStack);
    newStack.push(data);
    return;
  }
  currentStack().push(data);
}
int ManyStacks::pop() {
  if (currentStack().getTop() == NULL) {
    stacks.erase(stacks.end());
    return currentStack().pop();
  }  
  return currentStack().pop();
}
void ManyStacks::printAll() {
  int size = stacks.size();
}


int main() {
  ManyStacks bigBoy;
  bigBoy.push(1);
  bigBoy.push(1);
  bigBoy.push(1);
  bigBoy.push(1);
  bigBoy.push(1);
  bigBoy.push(1);
  bigBoy.push(1);
  bigBoy.push(1);
  return 0;
}
