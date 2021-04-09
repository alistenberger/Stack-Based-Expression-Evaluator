#include "Add_Command.h"

Add_Command::Add_Command (void)
: Binary_Op_Command ()
{
  // Nothing here
}

Add_Command::~Add_Command (void)
{
  // Nothing allocated
}

int Add_Command::evaluate (int num1, int num2) const
{
  return num1+num2;
}

const int Add_Command::getPrecedence (void) const
{
  return this->precedence;
}

bool Add_Command::isOpeningParenthesis (void) 
{
  return false;
}

std::string Add_Command::getValue (void)
{
  return this->value;
}