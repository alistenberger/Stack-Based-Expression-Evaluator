#ifndef _ADD_COMMAND_H_
#define _ADD_COMMAND_H_

#include "Binary_Op_Command.h"

class Add_Command : Binary_Op_Command
{
public:
  virtual int evaluate (int num1, int num2) const;
};

#endif // !defined _ADD_COMMAND_H_