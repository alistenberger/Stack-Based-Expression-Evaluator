#include "Number_Command.h"

Number_Command::Number_Command (Stack <int> & stack, int number)
: Expr_Command (stack, number)
{
  //Nothing here
}

Number_Command::~Number_Command (void)
{
  // Nothing allocated
}

bool Number_Command::execute (void)
{
  stack_.push (number_);
  return true;
}

int Number_Command::getPrecedence (void) const
{
  return this->precedence;
}