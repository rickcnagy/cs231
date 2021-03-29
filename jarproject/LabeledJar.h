// SPECIFICATION FILE (LabeledJar.h)
// Declare data type LabeledJar

// Edit history:
// 2021-03-21: Create initial LabeledJar class.
// 2021-03-28: Add virtual showInfo() along with virtual JarType::showInfo().

#include <string>

#include "jar.h"

#ifndef LABELEDJAR_H
#define LABELEDJAR_H

class LabeledJar : public JarType {
 public:
  LabeledJar();
  LabeledJar(int numUnits);
  LabeledJar(std::string label);
  LabeledJar(std::string label, int numUnits);
  ~LabeledJar();

  std::string getLabel() const;

  virtual void showInfo();

 private:
  std::string label;
};

#endif
