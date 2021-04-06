#include "vehicle.h"

#ifndef PLANE_H
#define PLANE_H

class Plane : public Vehicle {
 public:
  Plane(std::string make, std::string model, int productionYear, int price);
  std::string start();
  std::string displayWindowSticker();
};

#endif
