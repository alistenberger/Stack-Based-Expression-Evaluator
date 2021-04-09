#ifndef _SUBTRACT_COMMAND_H_
#define _SUBTRACT_COMMAND_H_

#include "Binary_Op_Command.h"
#include <string>

class Subtract_Command : public Binary_Op_Command
{
public:
  Subtract_Command (void);
  ~Subtract_Command (void);
  virtual int evaluate (int num1, int num2) const;
  virtual const int getPrecedence (void) const;
  virtual bool isOpeningParenthesis (void);
  virtual std::string getValue (void);

private:
  const int precedence = 1;
  std::string value = "-";
};

#endif // !defined _SUBTRACT_COMMAND_H_