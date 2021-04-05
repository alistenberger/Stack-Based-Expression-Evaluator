#include "Modulus_Command.h"

Modulus_Command::Modulus_Command (Stack <int> & stack)
: Binary_Op_Command (stack)
{
  //Nothing here
}

Modulus_Command::~Modulus_Command (void)
{
  // Nothing Allocated
}

int Modulus_Command::evaluate (int num1, int num2) const
{
  return num1%num2;
}

int Modulus_Command::getPrecedence (void) const
{
  return this->precedence;
}