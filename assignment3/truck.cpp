#include "truck.h"

#include <string>

Truck::Truck(std::string make, std::string model, int productionYear, int price)
    : Vehicle(make, model, productionYear, price) {}

std::string Truck::start() {
  return "Put your truck key in the ignition and turn!";
}

std::string Truck::displayWindowSticker() {
  return getWindowStickerDescription();
}
