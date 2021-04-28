// Headers for the flightdata parser

#include <string>
#include <vector>

// Struct to contain a Flight as specified in flightdata.txt
struct Flight {
  std::string flight_number;
  std::string origin;
  std::string destination;
  int passenger_count;
  double average_price;
};

Flight parse_flight_line(std::string line);
