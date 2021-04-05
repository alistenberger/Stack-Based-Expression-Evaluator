#ifndef _MULTIPLY_COMMAND_H_
#define _MULTIPLY_COMMAND_H_

#include "Binary_Op_Command.h"

class Multiply_Command : public Binary_Op_Command
{
public:
  Multiply_Command (Stack <int> & stack);
  ~Multiply_Command (void);
  virtual int evaluate (int num1, int num2) const;
  virtual int getPrecedence (void) const;

private:
  int precedence = 2;
};

#endif // !defined _MULTIPLY_COMMAND_H_