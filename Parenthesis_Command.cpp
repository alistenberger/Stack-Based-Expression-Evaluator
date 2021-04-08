#include "Parenthesis_Command.h"

Parenthesis_Command::Parenthesis_Command (void)
: Expr_Command ()
{
  //Nothing here
}

Parenthesis_Command::~Parenthesis_Command (void)
{
  // Nothing allocated
}

bool Parenthesis_Command::execute (Stack <int> & stack)
{
  return true;
}

bool Parenthesis_Command::isOpeningParenthesis (void)
{
  if (this->openingParenthesis == true) {
    return true;
  } else {
    return false;
  }
}

void Parenthesis_Command::setOpeningParenthesis (bool response)
{
  this->openingParenthesis = response;
}

int Parenthesis_Command::getPrecedence (void) const
{
  return this->precedence;
}