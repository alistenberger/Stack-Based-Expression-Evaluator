#include "Modulus_Command.h"

Modulus_Command::Modulus_Command (void)
: Binary_Op_Command ()
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

const int Modulus_Command::getPrecedence (void) const
{
  return this->precedence;
}

bool Modulus_Command::isOpeningParenthesis (void) 
{
  return false;
}

std::string Modulus_Command::getValue (void)
{
  return this->value;
}