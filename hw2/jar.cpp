// IMPLEMENTATION FILE (jar.cpp)
// Implement the abstract data type JarType

// Edit History:

#include "jar.h"

void JarType::initToEmpty()
{
  numUnits = 0;
}

void JarType::add(int n)
{
  numUnits += n;
}

int JarType::quantity() const
{
  return numUnits;
}
