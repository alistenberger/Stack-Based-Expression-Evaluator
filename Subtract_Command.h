#ifndef _SUBTRACT_COMMAND_H_
#define _SUBTRACT_COMMAND_H_

#include "Binary_Op_Command.h"

class Subtract_Command : public Binary_Op_Command
{
public:
  Subtract_Command (void);
  ~Subtract_Command (void);
  virtual int evaluate (int num1, int num2) const;
  virtual int getPrecedence (void) const;
  virtual bool isOpeningParenthesis (void);

private:
  int precedence = 1;
};

#endif // !defined _SUBTRACT_COMMAND_H_