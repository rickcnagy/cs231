// Declare the Calculator class

#include <string>
#include <vector>

#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
 public:
  explicit Calculator(std::string input);

  double getStandardDeviation();
  double getMean();

 private:
  std::vector<double> data;
};

#endif
