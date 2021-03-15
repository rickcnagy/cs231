// Implement the getStandardDeviation() function

#include <math.h>

#include "standard_deviation_calculator.h"

double getStandardDeviation(double data[], int length) {
  if (length < 2) {
    return 0;
  }

  double sum = 0;
  for (int i = 0; i < length; i++) {
    sum += data[i];
  }

  double mean = sum / length;

  double squaredDeviationSum = 0;
  for (int i = 0; i < length; i++) {
    double deviation = (data[i] - mean);
    squaredDeviationSum += pow(deviation, 2);
  }

  double variance = squaredDeviationSum / (length - 1);

  return sqrt(variance);
}
