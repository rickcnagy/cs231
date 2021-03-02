// IMPLEMENTATION FILE (employee.cpp)

#include "employee.h"

#include <string>
#include <iomanip>
#include <sstream>

Employee::Employee(std::string firstName, std::string lastName, double salary)
    : firstName(firstName), lastName(lastName), salary(salary) {
  assert(salary > 0);
}

std::string Employee::getInfo() {
  return getFullName() + " | salary: " + getFormattedSalary();
}

std::string Employee::getFullName() { return firstName + " " + lastName; }

std::string Employee::getFormattedSalary() {
  std::stringstream stream;
  stream << "$" << std::fixed << std::setprecision(2) << salary;
  return stream.str();
}

void Employee::raiseSalary(double raiseAmount) {
  assert(raiseAmount > 0);
  salary *= 1 + raiseAmount;
}

void Employee::setLastName(std::string newLastName) { lastName = newLastName; }
