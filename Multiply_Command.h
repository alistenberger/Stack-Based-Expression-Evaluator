#ifndef _MULTIPLY_COMMAND_H_
#define _MULTIPLY_COMMAND_H_

#include "Binary_Op_Command.h"

class Multiply_Command : Binary_Op_Command
{
public:
  Multiply_Command (Stack <int> & stack);
  ~Multiply_Command (void);
  virtual int evaluate (int num1, int num2) const;
};

#endif // !defined _MULTIPLY_COMMAND_H_