#include "Multiply_Command.h"

Multiply_Command::Multiply_Command (void)
: Binary_Op_Command ()
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

const int Multiply_Command::getPrecedence (void) const
{
  return this->precedence;
}

bool Multiply_Command::isOpeningParenthesis (void) {
  return false;
}