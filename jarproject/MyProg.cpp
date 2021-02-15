// A program to manipulate a few jar objects

#include <iostream>

#include "jar.h"

// Edit History:
// 2021-02-14: Added jars 1 through 7 and added getInput() function

int getInput(int& n);

int main() {
  JarType jar1, jar2;

  // Removed the next line as it causes a compilation error
  // jar1.numUnits = 10000;

  jar1.initToEmpty();
  jar2.initToEmpty();

  jar1.add(10);
  jar2 = jar1;
  jar2.add(5);

  std::cout << "Jar1 contains " << jar1.quantity() << std::endl;
  std::cout << "Jar2 contains " << jar2.quantity() << std::endl;

  jar1.add(-5000);
  jar2.subtract(10);

  std::cout << "Jar1 contains " << jar1.quantity() << std::endl;
  std::cout << "Jar2 contains " << jar2.quantity() << std::endl;

  JarType jar3(20);
  std::cout << "Jar3 contains " << jar3.quantity() << std::endl;

  JarType jar4('p');  // Prefill with 16 ounces
  JarType jar5('q');  // Prefill with 32 ounces
  JarType jar6('a');  // Should print invalid request

  std::cout << "Jar4 contains " << jar4.quantity() << std::endl;
  std::cout << "Jar5 contains " << jar5.quantity() << std::endl;
  std::cout << "Jar6 contains " << jar6.quantity() << std::endl;

  JarType jar7;
  int number = 0;

  int status = getInput(number);
  if (status == 0) {
    jar7.add(number);
  }

  std::cout << "Jar7 contains " << jar7.quantity() << std::endl;

  return 0;  // Success
}

// A function to ask the user for a value
// Return status: 0  a valid number is entered
//                1  a valid number is not entered
int getInput(int& n) {
  int temp;

  std::cout << "Please enter the number of units: ";
  std::cin >> temp;

  if (temp > 0) {
    n = temp;
    return 0;
  } else {
    return 1;
  }
}
