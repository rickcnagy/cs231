// SPECIFICATION FILE (employee.h)

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

// Contains information about employees, storing basic info (name, salary, etc)
// and allowing that information to be changed over time.
class Employee {
 public:
  // Creates an employee with the specified first, last, and salary. salary must
  // be greater than 0.
  explicit Employee(std::string firstName, std::string lastName, double salary);

  // Returns a summary of the information on file for this employee.
  std::string getInfo();

  // Returns a string with the employee's salary, to the nearest cent,
  // appropriately formatted for human eyes.
  std::string getFormattedSalary();
  std::string getFullName();

  // Raises the employee's salary by raiseAmount. For instance, if raise amount
  // is .01, the salary will be raised by 1% (not a very good raise!).
  // raiseAmount must be greater than 0.
  void raiseSalary(double raiseAmount);
  void setLastName(std::string lastName);

 private:
  std::string firstName;
  std::string lastName;
  double salary;
};

#endif
