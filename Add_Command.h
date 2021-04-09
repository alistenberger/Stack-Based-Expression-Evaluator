#ifndef _ADD_COMMAND_H_
#define _ADD_COMMAND_H_

#include "Binary_Op_Command.h"
#include <string>

class Add_Command : public Binary_Op_Command
{
public:
  Add_Command (void);
  ~Add_Command (void);
  virtual int evaluate (int num1, int num2) const;
  virtual const int getPrecedence (void) const;
  virtual bool isOpeningParenthesis (void);
  virtual std::string getValue (void);
protected:
  const int precedence = 1;
  std::string value = "+";
};

#endif // !defined _ADD_COMMAND_H_