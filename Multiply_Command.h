#ifndef _MULTIPLY_COMMAND_H_
#define _MULTIPLY_COMMAND_H_

#include "Binary_Op_Command.h"

class Multiply_Command : public Binary_Op_Command
{
public:
  Multiply_Command (void);
  ~Multiply_Command (void);
  virtual int evaluate (int num1, int num2) const;
  virtual const int getPrecedence (void) const;
  virtual bool isOpeningParenthesis (void);

private:
  const int precedence = 2;
};

#endif // !defined _MULTIPLY_COMMAND_H_