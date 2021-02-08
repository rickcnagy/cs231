// A program to manipulate a few jar objects

#include "jar.h"
#include <iostream>

// Edit History:

int main()
{
  JarType jar1, jar2;

  jar1.initToEmpty();
  jar2.initToEmpty();

  jar1.add(10);
  jar2 = jar1;
  jar2.add(5);

  std::cout << "\nJar1 contains" << jar1.quantity();
  std::cout << "\nJar2 contains" << jar2.quantity();
  std::cout << std::endl;

  return 0;  // Success
}
