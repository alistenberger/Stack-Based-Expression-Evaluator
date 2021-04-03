#include "Subtract_Command.h"

Subtract_Command::Subtract_Command (Stack <int> & stack)
: Binary_Op_Command (stack)
{
  // Nothing here
}

Subtract_Command::~Subtract_Command (void)
{
  // Nothing Allocated
}

int Subtract_Command::evaluate (int num1, int num2) const
{
  return num1-num2;
}