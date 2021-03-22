// SPECIFICATION FILE (jar.h)
// Declare the abstract data type JarType

// Edit history:
// 2021-02-14: Added default, int, and char constructors, added destructor,
//     added add() and subtract() methods.
// 2021-03-15: Added reveal() friend function, copy function, and static
//             getJarCount().

#include <iostream>

#ifndef JAR_H
#define JAR_H

class JarType {
 public:
  static int getJarCount();

  friend int reveal(JarType j);
  friend std::ostream &operator<<(std::ostream &os, const JarType &j);

  JarType operator+(const JarType &j);
  operator int();

  explicit JarType();
  JarType(int prefillAmount);
  explicit JarType(char abbreviation);
  JarType(JarType &other);
  ~JarType();
  void initToEmpty();    // Initialize a jar
  void add(int n);       // Add n units to jar
  void subtract(int n);  // Subtract n units from jar
  int quantity() const;  // Reveal number of units in jar

 private:
  static int jarCount;

  int numUnits;
};

#endif
