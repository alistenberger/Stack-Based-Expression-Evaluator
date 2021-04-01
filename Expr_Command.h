#ifndef _EXPR_COMMAND_H_
#define _EXPR_COMMAND_H_

class Expr_Command
{
public: 

  virtual bool execute (void) = 0; 
  virtual bool execute (int number) = 0;
};


#endif // !defined _EXPR_COMMAND_H_