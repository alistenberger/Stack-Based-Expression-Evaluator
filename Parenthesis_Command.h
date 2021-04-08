#ifndef _PARENTHESIS_COMMAND_H_
#define _PARENTHESIS_COMMAND_H_

#include "Expr_Command.h"
#include "Stack.h"

class Parenthesis_Command : public Expr_Command
{
public:
  Parenthesis_Command (void);
  ~Parenthesis_Command (void);
  virtual bool execute (Stack <int> & stack);
  bool isOpeningParenthesis (void);
  void setOpeningParenthesis (bool response);
  virtual const int getPrecedence (void) const;

private:
  bool openingParenthesis;
  const int precedence = 3;
};

#endif // !defined _PARENTHESIS_COMMAND_H_