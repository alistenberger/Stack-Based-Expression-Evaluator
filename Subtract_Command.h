#ifndef _SUBTRACT_COMMAND_H_
#define _SUBTRACT_COMMAND_H_

#include "Binary_Op_Command.h"

class Subtract_Command : Binary_Op_Command
{
public:
  virtual int evaluate (int num1, int num2) const;
};

#endif // !defined _SUBTRACT_COMMAND_H_