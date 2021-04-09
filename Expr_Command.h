#ifndef _EXPR_COMMAND_H_
#define _EXPR_COMMAND_H_

#include "Stack.h"
#include <string>

class Expr_Command
{
public: 

  Expr_Command (void);

  Expr_Command (int number);

  ~Expr_Command (void);

  virtual bool execute (Stack <int> & stack) = 0; 

  virtual const int getPrecedence (void) const = 0;

  virtual bool isOpeningParenthesis (void) = 0;

  virtual std::string getValue (void) = 0;
};


#endif // !defined _EXPR_COMMAND_H_