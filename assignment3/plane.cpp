#include "plane.h"

#include <string>

Plane::Plane(std::string make, std::string model, int productionYear, int price)
    : Vehicle(make, model, productionYear, price) {}

std::string Plane::start() {
  return "Sit down in that cockpit and initiate the start sequence.";
}

std::string Plane::displayWindowSticker() {
  return getWindowStickerDescription();
}
