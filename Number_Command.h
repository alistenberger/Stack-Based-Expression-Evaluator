#ifndef _NUMBER_COMMAND_H_
#define _NUMBER_COMMAND_H_

#include "Expr_Command.h"
#include "Stack.h"

class Number_Command : public Expr_Command
{
public:
  Number_Command (Stack <int> & stack, int number);
  ~Number_Command (void);
  virtual bool execute (void);
  virtual int getPrecedence (void) const;

private:
  
  Stack <int> stack_;
  int number_;
  int precedence = 0;
};

#endif // !defined _NUMBER_COMMAND_H_