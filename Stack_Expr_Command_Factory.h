#ifndef _STACK_EXPR_COMMAND_FACTORY_H_
#define _STACK_EXPR_COMMAND_FACTORY_H_

#include "Expr_Command_Factory.h"
#include "Stack.h"

class Stack_Expr_Command_Factory : public Expr_Command_Factory 
{ 
public: 
  Stack_Expr_Command_Factory (Stack <int> & stack); 
  ~Stack_Expr_Command_Factory (void);
  virtual Number_Command * create_number_command (Stack <int> & stack, int num); 
  virtual Add_Command * create_add_command (void); 
  virtual Subtract_Command * create_subtract_command (void); 
  virtual Multiply_Command * create_multiply_command (void);
  virtual Divide_Command * create_divide_command (void);
  virtual Modulus_Command * create_modulus_command (void);
  virtual Parenthesis_Command * create_parenthesis_command (bool response);
private: 
  Stack <int> & stack_; 
}; 

#endif // !defined _STACK_EXPR_COMMAND_H_