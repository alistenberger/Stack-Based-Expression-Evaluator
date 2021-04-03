#ifndef _NUMBER_COMMAND_H_
#define _NUMBER_COMMAND_H_

#include "Expr_Command.h"
#include "Stack.h"

class Number_Command : Expr_Command
{
public:
  Number_Command (Stack <int> & stack, int number);
  ~Number_Command (void);
  virtual bool execute (void);

private:
  
  Stack <int> stack_;
  int number_;
};

#endif // !defined _NUMBER_COMMAND_H_