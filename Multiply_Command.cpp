#include "Multiply_Command.h"

Multiply_Command::Multiply_Command (Stack <int> & stack)
: Binary_Op_Command (stack)
{
  // Nothing here
}

Multiply_Command::~Multiply_Command (void)
{
  // Nothing Allocated
}

int Multiply_Command::evaluate (int num1, int num2) const
{
  return num1*num2;
}