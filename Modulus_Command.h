#ifndef _MODULUS_COMMAND_H_
#define _MODULUS_COMMAND_H_

#include "Binary_Op_Command.h"

class Modulus_Command : public Binary_Op_Command
{
public:
  Modulus_Command (void);
  ~Modulus_Command (void);
  virtual int evaluate (int num1, int num2) const;
  virtual int getPrecedence (void) const;
  virtual bool isOpeningParenthesis (void);

private:
  int precedence = 2;
};

#endif // !defined _MODULUS_COMMAND_H_