// A program to manipulate a few jar objects

#include <iostream>

#include "jar.h"

// Edit History:
// 2021-02-14: Added jars 1 through 7 and added getInput() function
// 2021-02-21: Made getInput() take a template type.
// 2021-03-15: Added reveal() friend function, added rack[] pointer array, and
//             added checks to JarType::getJarCount().

template <typename T>
int getInput(T& n);

int reveal(JarType j);

int JarType::jarCount = 0;

int main() {
  std::cout << "jarCount starts at " << JarType::getJarCount() << std::endl;

  JarType jar1, jar2;

  std::cout << "After jar1 and jar2, jarCount is: " << JarType::getJarCount()
            << std::endl;

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

  int status = getInput<int>(number);
  if (status == 0) {
    jar7.add(number);
  }

  std::cout << "Jar7 contains " << jar7.quantity() << std::endl;

  JarType shelf[3];
  shelf[0] = jar1;
  shelf[1] = jar2;
  shelf[2] = jar5;

  for (int i = 0; i < 3; i++) {
    shelf[i].add((i + 1) * 10);
  }

  for (int i = 0; i < 3; i++) {
    std::cout << shelf[i].quantity() << std::endl;
  }

  JarType* jarPointer = nullptr;
  jarPointer = &jar1;
  std::cout << "Showing quantities in jar1 via a pointer variable: "
            << jarPointer->quantity() << std::endl;

  JarType* rack = new JarType[5];
  rack[0].add(1);
  (*(rack + 1)).add(2);
  (rack + 2)->add(3);

  std::cout << "The value in the first jar is " << rack[0].quantity()
            << std::endl;
  std::cout << "The value in the second jar is " << rack[1].quantity()
            << std::endl;
  std::cout << "The value in the third jar is " << rack[2].quantity()
            << std::endl;

  delete[] rack;

  JarType jar31(jar1);
  std::cout << "The value in the (original) jar 1 is " << jar1.quantity()
            << std::endl;
  std::cout << "The value in the (copied) jar 31 is " << jar31.quantity()
            << std::endl;

  std::cout << "The value of reveal(jar1) is: " << std::endl
            << reveal(jar1) << std::endl;

  std::cout << "jarCount ends at " << JarType::getJarCount() << std::endl;

  return 0;  // Success
}

int reveal(JarType j) { return j.numUnits; }

// A function to ask the user for a value
// Return status: 0  a valid number is entered
//                1  a valid number is not entered
template <typename T>
int getInput(T& n) {
  T temp;

  std::cout << "Please enter the number of units to add to this jar: ";
  std::cin >> temp;

  if (temp > 0) {
    n = temp;
    return 0;
  } else {
    return 1;
  }
}
