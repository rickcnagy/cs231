// Logic for parsing a flightdata file

#include "flightdata_parser.h"

#include <regex>

// Parses an individual line. Assumes it matches the following pattern:
// AA123,BOS,LAX,200,345.67
Flight parse_flight_line(std::string line) {
  Flight flight = Flight();

  std::regex line_regex("([^ ]+),([^ ]+),([^ ]+),([^ ]+),([^ ]+)");
  std::smatch match;
  std::regex_search(line, match, line_regex);

  flight.flight_number = match[1];
  flight.origin = match[2];
  flight.destination = match[3];
  flight.passenger_count = std::stoi(match[4]);
  flight.average_price = std::stod(match[5]);

  return flight;
}
