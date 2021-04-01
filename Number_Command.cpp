#include "Number_Command.h"

Number_Command::Number_Command (Stack <int> & stack)
: stack_ (stack)
{
  //Nothing here
}

bool Number_Command::execute (int number)
{
  stack_.push (number);
  return true;
}