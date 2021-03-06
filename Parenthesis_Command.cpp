#include "Parenthesis_Command.h"

Parenthesis_Command::Parenthesis_Command (void)
: Expr_Command ()
{
  //Nothing here
}

Parenthesis_Command::~Parenthesis_Command (void)
{
  //Nothing here
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

const int Parenthesis_Command::getPrecedence (void) const
{
  return this->precedence;
}

std::string Parenthesis_Command::getValue (void)
{
  return this->value;
}