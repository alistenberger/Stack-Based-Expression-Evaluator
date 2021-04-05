#ifndef _PARENTHESIS_COMMAND_H_
#define _PARENTHESIS_COMMAND_H_

#include "Expr_Command.h"
#include "Stack.h"

class Parenthesis_Command : public Expr_Command
{
public:
  Parenthesis_Command (Stack <int> & stack);
  ~Parenthesis_Command (void);
  virtual bool execute (void);
  bool isOpeningParenthesis (void);
  void setOpeningParenthesis (bool response);
  virtual int getPrecedence (void) const;

private:
  
  Stack <int> stack_;
  bool openingParenthesis;
  int precedence = 3;
};

#endif // !defined _PARENTHESIS_COMMAND_H_