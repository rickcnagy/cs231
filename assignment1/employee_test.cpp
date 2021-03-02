#include "employee.h"

#include <iostream>

// A basic test for the Employee class, creating a few employees, modifying
// them, and printing out their info.
int main() {
  std::cout << " ######   ######   #######   #######    ##  " << std::endl;
  std::cout << "##    ## ##    ## ##     ## ##     ## ####  " << std::endl;
  std::cout << "##       ##              ##        ##   ##  " << std::endl;
  std::cout << "##        ######   #######   #######    ##  " << std::endl;
  std::cout << "##             ## ##               ##   ##  " << std::endl;
  std::cout << "##    ## ##    ## ##        ##     ##   ##  " << std::endl;
  std::cout << " ######   ######  #########  #######  ######" << std::endl;

  Employee e1("John", "Doe", 1234.56);
  Employee e2("Jane", "Jones", 7890.12);

  std::cout << "e1: " << e1.getInfo() << std::endl;
  std::cout << "e2: " << e2.getInfo() << std::endl;

  std::cout << "Nice job everyone! Giving all employees a 10% raise..."
            << std::endl;
  e1.raiseSalary(.1);
  e2.raiseSalary(.1);

  std::cout << "e1 salary: " << e1.getFormattedSalary() << std::endl;
  std::cout << "e2 salary: " << e2.getFormattedSalary() << std::endl;

  std::cout << "Changing e2's last name to \"Doe\"..." << std::endl;
  e2.setLastName("Doe");

  std::cout << "e2: " << e2.getInfo() << std::endl;
}
