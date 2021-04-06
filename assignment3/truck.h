#include "vehicle.h"

#ifndef TRUCK_H
#define TRUCK_H

class Truck : public Vehicle {
 public:
  Truck(std::string make, std::string model, int productionYear, int price);
  std::string start();
  std::string displayWindowSticker();
};

#endif
