#include "vehicle.h"

#include <iomanip>
#include <locale>
#include <sstream>
#include <string>

Vehicle::Vehicle(std::string make, std::string model, int productionYear,
                 int price)
    : make(make), model(model), productionYear(productionYear), price(price) {}

std::string Vehicle::getWindowStickerDescription() {
  return std::to_string(productionYear) + " " + make + " " + model + ", " +
         getFormattedPrice_();
}

std::string Vehicle::getFormattedPrice_() {
  std::stringstream stream;
  stream.imbue(std::locale(""));
  stream << "$" << std::fixed << std::setprecision(2) << price;
  return stream.str();
}
