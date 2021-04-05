#include "Divide_Command.h"

Divide_Command::Divide_Command (Stack <int> & stack)
: Binary_Op_Command (stack)
{
  // Nothing here
}

Divide_Command::~Divide_Command (void)
{
  // Nothing Allocated
}

int Divide_Command::evaluate (int num1, int num2) const
{
  return num1/num2;
}

int Divide_Command::getPrecedence (void) const
{
  return this->precedence;
}