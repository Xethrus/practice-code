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
  stackSize = 0;
  }
  int stackSize;
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
  stackSize++;
}

int Stack::pop() {
  if (top == NULL) { std::cerr << "no content" << std::endl; }
  Node* temp = top;
  top = top->below;
  return temp->data;
}

class ManyStacks {
public: 
  int items;
  std::vector<Stack> stacks;
  ManyStacks() { 
    items = 0;
    Stack newStack;
    stacks.push_back(newStack);
  }
  void push(int);
  int pop();
  Stack& currentStack();
  void printAll();
};

Stack& ManyStacks::currentStack() {
  int index = stacks.size()-1;
  //called a ton
  //std::cout << "the current stack index is: " << index << std::endl;
  if (stacks[index].stackSize == 10) {
    stacks[index].fullStack = true;
  }
  return stacks[index];
}

void ManyStacks::push(int data) {
  if (currentStack().fullStack) {
    std::cout << "this means current stack is full" << std::endl;
    Stack newStack;
    stacks.push_back(newStack);
    newStack.push(data);
    items++;
    return;
  }
  items++;
  std::cout << "it is pushing data to unfull stack" << std::endl;
  currentStack().push(data);
  return;
}
int ManyStacks::pop() {
  if (currentStack().getTop() == NULL) {
    std::cout << "top is null" << std::endl;
    stacks.erase(stacks.end());
    return currentStack().pop();
  }  
  return currentStack().pop();
}
void ManyStacks::printAll() {
  std::cout << "amount of items: " << items << std::endl;
  int size = stacks.size();
  for (int i = 0; i < items; i++) {
    std::cout << pop() << std::endl;
    std::cout << "pop" << std::endl;
  }
  return;
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
  bigBoy.push(1);
  bigBoy.push(1);
  bigBoy.push(1);
  bigBoy.push(1);
  bigBoy.push(1);
  bigBoy.push(1);
  bigBoy.printAll();
  return 0;
}
