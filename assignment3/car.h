#include "vehicle.h"

#ifndef CAR_H
#define CAR_H

class Car : public Vehicle {
 public:
  Car(std::string make, std::string model, int productionYear, int price);
  std::string start();
  std::string displayWindowSticker();
};

#endif
