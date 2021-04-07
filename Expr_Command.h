#ifndef _EXPR_COMMAND_H_
#define _EXPR_COMMAND_H_

#include "Stack.h"

class Expr_Command
{
public: 

  Expr_Command (Stack <int> & stack);

  Expr_Command (Stack <int> & stack, int number);

  ~Expr_Command (void);

  virtual bool execute (Stack <int> & stack) = 0; 

  virtual int getPrecedence (void) const = 0;

  virtual bool isOpeningParenthesis (void) = 0;

protected:
  Stack <int> stack_;
};


#endif // !defined _EXPR_COMMAND_H_