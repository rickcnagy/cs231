// Implement the Calculator class

#include "calculator.h"

#include <math.h>

#include <iostream>
#include <regex>
#include <string>
#include <vector>

Calculator::Calculator(std::string input) {
  std::regex decimalRegex("([-0-9\\.]+)");
  std::smatch match;

  while (std::regex_search(input, match, decimalRegex)) {
    std::string decimalString = match.str();
    double decimal = std::stod(decimalString);
    data.push_back(decimal);

    input = match.suffix();
  }
}

int Calculator::getDataCount() { return data.size(); }

std::string Calculator::getDataString() {
  std::string dataString;
  for (int i = 0; i < data.size(); i++) {
    dataString.append(std::to_string(data[i]));
    if (i < data.size() - 1) {
      dataString.append(" ");
    }
  }
  return dataString;
}

double Calculator::getStandardDeviation() {
  if (data.size() < 2) {
    return 0;
  }

  double mean = getMean();

  double sumOfSquares = 0;
  for (int i = 0; i < data.size(); i++) {
    double deviation = (data[i] - mean);
    double squaredDeviation = pow(deviation, 2);
    sumOfSquares += squaredDeviation;
  }

  double variance = sumOfSquares / (data.size() - 1);

  return sqrt(variance);
}

double Calculator::getMean() {
  if (data.empty()) {
    return 0;
  }

  double mean = 0;
  for (int i = 0; i < data.size(); i++) {
    mean += data[i];
  }
  return mean / data.size();
}
