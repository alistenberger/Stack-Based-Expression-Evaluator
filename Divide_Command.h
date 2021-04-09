#ifndef _DIVIDE_COMMAND_H_
#define _DIVIDE_COMMAND_H_

#include "Binary_Op_Command.h"
#include <string>

class Divide_Command : public Binary_Op_Command
{
public:
  Divide_Command (void);
  ~Divide_Command (void);
  virtual int evaluate (int num1, int num2) const;
  virtual const int getPrecedence (void) const;
  virtual bool isOpeningParenthesis (void);
  virtual std::string getValue (void);

private:
  const int precedence = 2;
  std::string value = "/";
};

#endif // !defined _DIVIDE_COMMAND_H_