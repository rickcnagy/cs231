#include <fstream>
#include <iostream>
#include <stdexcept>

#include "flightdata_parser.h"

int main() {
  std::ifstream flightdata_file("flightdata.txt");

  if (flightdata_file.fail()) {
    throw std::runtime_error("Could not open flightdata.txt");
  }

  std::string line;
  while (std::getline(flightdata_file, line)) {
    Flight flight = parse_flight_line(line);

    std::cout << "Flight Number: " << flight.flight_number << std::endl
              << "Origin Airport: " << flight.origin << std::endl
              << "Destination Airport: " << flight.destination << std::endl
              << "Number of Passengers: " << flight.passenger_count << std::endl
              << "Average Price: " << flight.average_price << std::endl
              << std::endl;

    if (flightdata_file.peek() != EOF) {
      std::cout << "Continue? y/n: ";
      std::string should_continue;
      std::cin >> should_continue;

      if (should_continue == "y") {
        std::cout << std::endl;
      } else {
        break;
      }
    }
  }

  std::cout << "All done" << std::endl;
}
