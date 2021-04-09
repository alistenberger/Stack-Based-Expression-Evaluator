#ifndef _NUMBER_COMMAND_H_
#define _NUMBER_COMMAND_H_

#include "Expr_Command.h"
#include "Stack.h"
#include <string>

class Number_Command : public Expr_Command
{
public:
  Number_Command (int number);
  ~Number_Command (void);
  virtual bool execute (Stack <int> & stack);
  virtual const int getPrecedence (void) const;
  virtual bool isOpeningParenthesis (void);
  virtual std::string getValue (void);

private:
  int number_;
  const int precedence = 0;
  std::string value = "number";
};

#endif // !defined _NUMBER_COMMAND_H_