// IMPLEMENTATION FILE (jar.cpp)
// Implement the abstract data type JarType

// Edit History:
// 2021-02-14: Added default, int, and char constructors, added add() and
//     subtract() methods.
// 2021-03-15: Added implementations for copy function and static getJarCount().
// 2021-03-21: Added << and + overloads plus conversion to int.
// 2021-03-28: Add showInfo() implementation and throw exceptions when add() and
//             subtract() are passed invalid values.

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

JarType::~JarType() { jarCount--; }

void JarType::initToEmpty() { numUnits = 0; }

void JarType::add(int n) {
  if (n <= 0) {
    throw std::invalid_argument("Invalid value to add: " + std::to_string(n));
  }

  std::cout << "Adding " << n << " units..." << std::endl;
  numUnits += n;
}

void JarType::subtract(int n) {
  if (n <= 0) {
    throw std::invalid_argument("Invalid value to subtract: " +
                                std::to_string(n));
  } else if (numUnits < n) {
    throw std::invalid_argument(
        "Can't subtract because it would make units negative: " +
        std::to_string(n));
  }

  if (n > 0 && numUnits > +n) {
    std::cout << "Subtracting " << n << " units..." << std::endl;
    numUnits -= n;
  }
}

int JarType::quantity() const { return numUnits; }

int JarType::getJarCount() { return jarCount; }

std::ostream &operator<<(std::ostream &os, const JarType &j) {
  os << "The supplied jar contains " << j.numUnits << " units." << std::endl;
  return os;
}

JarType JarType::operator+(const JarType &j) {
  JarType tmpJar;
  tmpJar.add(this->numUnits + j.numUnits);
  return tmpJar;
}

JarType::operator int() { return numUnits; }

void JarType::showInfo() {
  std::cout << "Jar with " << numUnits << " units." << std::endl;
}
