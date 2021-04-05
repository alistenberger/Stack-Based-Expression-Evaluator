#ifndef _DIVIDE_COMMAND_H_
#define _DIVIDE_COMMAND_H_

#include "Binary_Op_Command.h"

class Divide_Command : public Binary_Op_Command
{
public:
  Divide_Command (Stack <int> & stack);
  ~Divide_Command (void);
  virtual int evaluate (int num1, int num2) const;
  virtual int getPrecedence (void) const;

private:
  int precedence = 2;
};

#endif // !defined _DIVIDE_COMMAND_H_