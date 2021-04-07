#include "Number_Command.h"

Number_Command::Number_Command (Stack <int> & stack, int number)
: Expr_Command (stack),
number_ (number)
{
  //Nothing here
}

Number_Command::~Number_Command (void)
{
  // Nothing allocated
}

bool Number_Command::execute (Stack <int> & stack)
{
  stack.push (number_);
  return true;
}

int Number_Command::getPrecedence (void) const
{
  return this->precedence;
}

bool Number_Command::isOpeningParenthesis (void) {
  return false;
}