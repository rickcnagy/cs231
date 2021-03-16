// Declare the Calculator class

#include <string>
#include <vector>

#ifndef CALCULATOR_H
#define CALCULATOR_H

// A calculator that takes in a space-delimited input string, breaks it up into
// discrete numbers, and then can run various calculations on it (mean,
// standard deviation).
class Calculator {
 public:
  explicit Calculator(std::string input);

  int getDataCount();
  std::string getDataString();
  double getStandardDeviation();
  double getMean();

 private:
  std::vector<double> data;
};

#endif
