#include <string>

#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle {
 public:
  virtual std::string start() = 0;
  virtual std::string displayWindowSticker() = 0;

 protected:
  Vehicle(std::string make, std::string model, int productionYear, int price);
  std::string getWindowStickerDescription();
  std::string make;
  std::string model;
  int productionYear;
  int price;

 private:
  Vehicle();
  std::string getFormattedPrice_();
};

#endif
