#ifndef _PARENTHESIS_COMMAND_H_
#define _PARENTHESIS_COMMAND_H_

#include "Expr_Command.h"
#include "Stack.h"
#include <string>

// COMMENT: Create a design that does not require having parenthesis as
// as command object since parenthesis are not executed.

class Parenthesis_Command : public Expr_Command
{
public:
  Parenthesis_Command (void);
  ~Parenthesis_Command (void);
  virtual bool execute (Stack <int> & stack);
  bool isOpeningParenthesis (void);
  void setOpeningParenthesis (bool response);
  virtual const int getPrecedence (void) const;
  virtual std::string getValue (void);

private:
  bool openingParenthesis;
  const int precedence = 3;
  std::string value = "Parenthesis";
};

#endif // !defined _PARENTHESIS_COMMAND_H_
