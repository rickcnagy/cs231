#include "car.h"

#include <string>

Car::Car(std::string make, std::string model, int productionYear, int price)
    : Vehicle(make, model, productionYear, price) {}

std::string Car::start() {
  return "Put your car key in the ignition and turn!";
}

std::string Car::displayWindowSticker() {
  return getWindowStickerDescription();
}
