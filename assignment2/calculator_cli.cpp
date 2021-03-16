// A program for calculating mean and standard deviation from user-input numbers

#include <iostream>
#include <string>

#include "calculator.h"

int main() {
  std::cout << "Enter up to 100 floating point numbers delimited by spaces. "
               "Press enter when done."
            << std::endl;
  std::string input;
  std::getline(std::cin, input);

  Calculator calculator = Calculator(input);
  if (calculator.getDataCount() > 100) {
    std::cout << "You inputted too many numbers! Please enter no more than 100 "
              << "numbers." << std::endl;
    return 1;
  }

  double mean = calculator.getMean();
  double standardDeviation = calculator.getStandardDeviation();

  std::cout << "Your data are " << calculator.getDataString() << std::endl;
  std::cout << "The mean of your data is " << mean << std::endl;
  std::cout << "The standard deviation of your data is " << standardDeviation
            << std::endl;

  return 0;
}
