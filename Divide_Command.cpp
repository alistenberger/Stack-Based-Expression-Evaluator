#include "Divide_Command.h"

Divide_Command::Divide_Command (void)
: Binary_Op_Command ()
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

const int Divide_Command::getPrecedence (void) const
{
  return this->precedence;
}

bool Divide_Command::isOpeningParenthesis (void) {
  return false;
}

std::string Divide_Command::getValue (void)
{
  return this->value;
}