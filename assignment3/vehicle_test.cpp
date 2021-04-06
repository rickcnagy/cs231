#include "vehicle.h"

#include <array>
#include <iostream>
#include <string>

#include "car.h"
#include "plane.h"
#include "truck.h"

void assertEquals(std::string expected, std::string actual);

int main() {
  Vehicle** vehicles = new Vehicle*[6];
  vehicles[0] = new Car("Honda", "Pilot", 2012, 16891);
  vehicles[1] = new Car("Subaru", "Outback", 2020, 26645);
  vehicles[2] = new Truck("Ford", "F-150", 2021, 28940);
  vehicles[3] = new Truck("RAM", "1500", 2021, 32795);
  vehicles[4] = new Plane("Boeing", "737 MAX", 2014, 997000000);
  vehicles[5] = new Plane("Airbus", "A380", 2005, 445600000);

  // Car
  assertEquals("Put your car key in the ignition and turn!",
               vehicles[0]->start());
  assertEquals("2020 Subaru Outback, $26,645",
               vehicles[1]->displayWindowSticker());

  // Truck
  assertEquals("Put your truck key in the ignition and turn!",
               vehicles[2]->start());
  assertEquals("2021 RAM 1500, $32,795", vehicles[3]->displayWindowSticker());

  // Plane
  assertEquals("Sit down in that cockpit and initiate the start sequence.",
               vehicles[4]->start());
  assertEquals("2005 Airbus A380, $445,600,000",
               vehicles[5]->displayWindowSticker());

  return 0;
}

void assertEquals(std::string expected, std::string actual) {
  if (expected == actual) {
    std::cout << "✅ " << expected << std::endl;
  } else {
    std::cout << "❌ expected '" << actual << "' to be '" << expected << "'"
              << std::endl;
  }
}
