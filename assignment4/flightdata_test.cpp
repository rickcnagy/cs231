// Basic tests for the flightdata parser

#include <assert.h>

#include <iostream>

#include "flightdata_parser.h"

int main() {
  std::ifstream flightdata_file("flightdata.txt");
  std::string line = std::getline(flightdata_file);
  Flight flight = parse_flight_line(line);

  assert(flight.flight_number == "AA123");
  assert(flight.origin == "BOS");
  assert(flight.destination == "LAX");
  assert(flight.passenger_count == 200);
  assert(flight.average_price == 345.67);

  std::cout << "Success!" << std::endl;

  return 0;
}
