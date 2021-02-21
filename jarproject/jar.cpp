// IMPLEMENTATION FILE (jar.cpp)
// Implement the abstract data type JarType

// Edit History:
// 2021-02-14: Added default, int, and char constructors, added add() and
//     subtract() methods.
#include "jar.h"

#include <iostream>

JarType::JarType() {
  std::cout << "rinsing jar..." << std::endl;
  initToEmpty();
}

JarType::JarType(int prefillAmount): numUnits(prefillAmount) {
  std::cout << "prefilling jar with " << prefillAmount << " ounces..."
            << std::endl;
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
}

JarType::~JarType() {}

void JarType::initToEmpty() { numUnits = 0; }

void JarType::add(int n) {
  if (n > 0) {
    std::cout << "Adding " << n << " units..." << std::endl;
    numUnits += n;
  }
}

void JarType::subtract(int n) {
  if (n > 0 && numUnits >+ n) {
    std::cout << "Subtracting " << n << " units...";
    numUnits -= n;
  }
}

int JarType::quantity() const { return numUnits; }
