#ifndef _BINARY_OP_COMMAND_H_
#define _BINARY_OP_COMMAND_H_

#include "Expr_Command.h"
#include "Stack.h"

class Binary_Op_Command : public Expr_Command 
{ 
public:

  Binary_Op_Command (void);

  bool execute (Stack <int> & stack);

  virtual int evaluate (int num1, int num2) const = 0; 

  virtual const int getPrecedence (void) const = 0;

  virtual bool isOpeningParenthesis (void) = 0;
}; 

#endif // !defined _BINARY_OP_COMMAND_H_