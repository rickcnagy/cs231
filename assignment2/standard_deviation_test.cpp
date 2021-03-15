// Test the getStandardDeviation() function

#include <iostream>

#include "standard_deviation_calculator.h"

void assertEqual(double expected, double actual);

int main() {
  assertEqual(0, getStandardDeviation((double[0]){}));
  assertEqual(0, getStandardDeviation((double[1]){1}));
  assertEqual(0, getStandardDeviation((double[1]){-1}));
  assertEqual(1.755064101,
              getStandardDeviation((double[5]){1.23, 2.34, 3.45, 4.56, 5.67}));
  assertEqual(302.7650354,
              getStandardDeviation((double[10]){100, 200, 300, 400, 500, 600,
                                                700, 800, 900, 1000}));
  assertEqual(15.98689471, getStandardDeviation((double[5]){
                               10.123, 20.234, 30.345, 40.456, 50.567}));
  assertEqual(0, getStandardDeviation((double[5]){1, 1, 1, 1, 1}));
  assertEqual(3.027650354, getStandardDeviation(
                               (double[10]){1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
}

void assertEqual(double expected, double actual) {
  if (expected != actual) {
    std::cout << "Assertion failed.\n\tExpected: " << expected
              << "\n\tActual: "<< actual << std::endl;
  }
}
