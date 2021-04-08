#ifndef _ADD_COMMAND_H_
#define _ADD_COMMAND_H_

#include "Binary_Op_Command.h"

class Add_Command : public Binary_Op_Command
{
public:
  Add_Command (void);
  ~Add_Command (void);
  virtual int evaluate (int num1, int num2) const;
  virtual int getPrecedence (void) const;
  virtual bool isOpeningParenthesis (void);
protected:
  int precedence = 1;
};

#endif // !defined _ADD_COMMAND_H_