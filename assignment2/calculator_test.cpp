// Test Calculator class

#include "calculator.h"

#include <cmath>
#include <string>
#include <iostream>

void assertOutputs(std::string input, double expectedMean,
                   double expectedStandardDeviation);
void assertEqual(std::string label, double expected, double actual);
double round5(double value);

int main() {
  assertOutputs("", 0, 0);
  assertOutputs("1", 1, 0);
  assertOutputs("-1", -1, 0);
  assertOutputs("-1 1", 0, 1.41421);
  assertOutputs("1.23 2.34 3.45 4.56 5.67", 3.45, 1.75506);
  assertOutputs("100 200 300 400 500 600 700 800 900 1000", 550, 302.76504);
  assertOutputs("10.123 20.234 30.345 40.456 50.567", 30.345, 15.98689);
  assertOutputs("1 1 1 1 1", 1, 0);
  assertOutputs("1 2 3 4 5 6 7 8 9 10", 5.5, 3.02765);

  std::cout << "All tests passed!" << std::endl;
}

void assertOutputs(std::string input, double expectedMean,
                   double expectedStandardDeviation) {
  Calculator calculator = Calculator(input);
  assertEqual("mean", expectedMean, calculator.getMean());
  assertEqual(
      "standard deviation", expectedStandardDeviation,
      calculator.getStandardDeviation());
}

void assertEqual(std::string label, double expected, double actual) {
  if (round5(expected) != round5(actual)) {
    std::cout << "Assertion failed for " << label << "\n\tExpected: "
              << expected << "\n\tActual: " << actual << std::endl;
  }
}

double round5(double value) { return std::round(value * 100000) / 100000; }
