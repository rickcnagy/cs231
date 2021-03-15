// IMPLEMENTATION FILE (jar.cpp)
// Implement the abstract data type JarType

// Edit History:
// 2021-02-14: Added default, int, and char constructors, added add() and
//     subtract() methods.
// 2021-03-15: Added implementations for copy function and static getJarCount().
#include "jar.h"

#include <iostream>

JarType::JarType() {
  std::cout << "rinsing jar..." << std::endl;
  initToEmpty();
  jarCount++;
}

JarType::JarType(int prefillAmount) : numUnits(prefillAmount) {
  std::cout << "prefilling jar with " << prefillAmount << " ounces..."
            << std::endl;
  jarCount++;
}

JarType::JarType(char abbreviation) {
  if (abbreviation == 'p') {
    std::cout << "prefilling jar with one pint" << std::endl;
    numUnits = 16;
  } else if (abbreviation == 'q') {
    std::cout << "prefilling jar with one quart" << std::endl;
    numUnits = 32;
  } else {
    std::cout << "Invalid abbreviation: '" << abbreviation
              << "'; rinsing jar..." << std::endl;
    initToEmpty();
  }
  jarCount++;
}

JarType::JarType(JarType &other) {
  std::cout << "in copy constructor..." << std::endl;
  numUnits = other.numUnits;
  jarCount++;
}

JarType::~JarType() {
  std::cout << "in deconstructor..." << std::endl;
  jarCount--;
}

void JarType::initToEmpty() { numUnits = 0; }

void JarType::add(int n) {
  if (n > 0) {
    std::cout << "Adding " << n << " units..." << std::endl;
    numUnits += n;
  }
}

void JarType::subtract(int n) {
  if (n > 0 && numUnits > +n) {
    std::cout << "Subtracting " << n << " units..." << std::endl;
    numUnits -= n;
  }
}

int JarType::quantity() const { return numUnits; }

int JarType::getJarCount() { return jarCount; }
