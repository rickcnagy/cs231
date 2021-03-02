// SPECIFICATION FILE (jar.h)
// Declare the abstract data type JarType

// Edit history:
// 2021-02-14: Added default, int, and char constructors, added destructor,
//     added add() and subtract() methods.
#ifndef JAR_H
#define JAR_H

class JarType {
 public:
  explicit JarType();
  explicit JarType(int prefillAmount);
  explicit JarType(char abbreviation);
  ~JarType();
  void initToEmpty();    // Initialize a jar
  void add(int n);       // Add n units to jar
  void subtract(int n);  // Subtract n units from jar
  int quantity() const;  // Reveal number of units in jar

 private:
  int numUnits;
};

#endif
