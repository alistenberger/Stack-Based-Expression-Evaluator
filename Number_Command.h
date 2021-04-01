#ifndef _NUMBER_COMMAND_H_
#define _NUMBER_COMMAND_H_

#include "Expr_Command.h"
#include "Stack.h"

class Number_Command : Expr_Command
{
public:
  Number_Command (Stack <int> & stack);

  virtual bool execute (void);
  virtual bool execute (int number);

private:
  
  Stack <int> stack_;
};

#endif // !defined _NUMBER_COMMAND_H_