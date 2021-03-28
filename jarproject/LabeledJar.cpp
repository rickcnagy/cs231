// IMPLEMENTATION FILE (LabeledJar.cpp)

// Edit history:
// 2021-03-21: Create initial LabeledJar implementation

#include "LabeledJar.h"

#include <iostream>

LabeledJar::LabeledJar() {
  label = "Generic";
  std::cout << "Getting labeled jar ready" << std::endl;
}

LabeledJar::LabeledJar(int numUnits) : JarType(numUnits) {
  label = "Generic";
  std::cout << "Getting labeled jar ready with " << numUnits << " units"
            << std::endl;
}

LabeledJar::LabeledJar(std::string label) : label(label) {
  std::cout << "Getting labeled jar called " << label << " ready" << std::endl;
}

LabeledJar::LabeledJar(std::string label, int numUnits) : JarType(numUnits), label(label) {
  std::cout << "Getting labeled jar called "
            << label << " ready with " << numUnits << " units" << std::endl;
}

LabeledJar::~LabeledJar() {
  std::cout << "Destroying labeled jar" << std::endl;
}

std::string LabeledJar::getLabel() const { return label; }
