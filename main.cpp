#include <iostream>
#include <cmath>

int main() {
  int divisor = 10;
  int number = 975;
  int temp = number;
  int ref = temp;
  int counter = 0;
  int result = 0;
  while (number / divisor > 0) {
    number = number / divisor;
    counter++;
  }
  for(int i = 0; i <= counter; i++) {
    int count = 0;
    while (temp / divisor > 0) {
      temp = temp / divisor;
      count++;
    } 
    std::cout << "temp: " << temp << std::endl;
    temp = ref - (std::pow(divisor, count) * temp);
    std::cout << "temp after: " << temp << std::endl;
    //temp = 975 - 900;
    //ref = 975 - 900;
    //temp = 75 - 70;
    //ref = 5;
    //temp = 5 - 0
    ref = ref - (std::pow(divisor, count) * temp);

  }
}

