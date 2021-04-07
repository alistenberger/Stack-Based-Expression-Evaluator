#include "Add_Command.h"

Add_Command::Add_Command (Stack <int> & stack)
: Binary_Op_Command (stack)
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

int Add_Command::getPrecedence (void) const
{
  return this->precedence;
}

bool Add_Command::isOpeningParenthesis (void) {
  return false;
}