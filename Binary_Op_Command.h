#ifndef _BINARY_OP_COMMAND_H_
#define _BINARY_OP_COMMAND_H_

#include "Expr_Command.h"
#include "Stack.h"

class Binary_Op_Command : public Expr_Command 
{ 
public:

  Binary_Op_Command (Stack <int> & stack);

  bool execute (void);

  virtual int evaluate (int num1, int num2) const = 0; 

}; 

#endif // !defined _BINARY_OP_COMMAND_H_