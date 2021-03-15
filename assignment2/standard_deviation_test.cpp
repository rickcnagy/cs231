// Test the getStandardDeviation() function

#include <iostream>
#include <cmath>

#include "standard_deviation_calculator.h"

void assertEqual(double expected, double actual);
double round5(double value);

int main() {
  assertEqual(0, getStandardDeviation((double[0]){}, 0));
  assertEqual(0, getStandardDeviation((double[1]){1}, 1));
  assertEqual(0, getStandardDeviation((double[1]){-1}, 1));
  assertEqual(1.75506, getStandardDeviation(
                           (double[5]){1.23, 2.34, 3.45, 4.56, 5.67}, 5));
  assertEqual(
      302.7650354,
      getStandardDeviation(
          (double[10]){100, 200, 300, 400, 500, 600, 700, 800, 900, 1000}, 10));
  assertEqual(15.9868947109,
              getStandardDeviation(
                  (double[5]){10.123, 20.234, 30.345, 40.456, 50.567}, 5));
  assertEqual(0, getStandardDeviation((double[5]){1, 1, 1, 1, 1}, 5));
  assertEqual(
      3.027650354,
      getStandardDeviation((double[10]){1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10));
}

void assertEqual(double expected, double actual) {
  if (round5(expected) != round5(actual)) {
    std::cout << "Assertion failed.\n\tExpected: " << expected
              << "\n\tActual: "<< actual << std::endl;
  }
}

double round5(double value) {
  return std::round(value * 100000) / 100000;
}
