// SPECIFICATION FILE (jar.h)
// Declare thye abstract data type JarType

// Edit history:

#ifndef JAR_H
#define JAR_H

class JarType {
public:
  void initToEmpty();  // Initialize a jar
  void add(int n);  // Add n units to jar
  int quantity() const;  // Reveal number of units in jar

private:
  int numUnits;
};

#endif
