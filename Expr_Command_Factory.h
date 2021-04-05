#ifndef _EXPR_COMMAND_FACTORY_H_
#define _EXPR_COMMAND_FACTORY_H_

#include "Number_Command.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Modulus_Command.h"
#include "Parenthesis_Command.h"
#include "Binary_Op_Command.h"

class Expr_Command_Factory 
{ 
public: 
  Expr_Command_Factory (void);
  virtual ~Expr_Command_Factory (void) = 0; 
  virtual Number_Command * create_number_command (int num) = 0; 
  virtual Add_Command * create_add_command (void) = 0; 
  virtual Subtract_Command * create_subtract_command (void) = 0; 
  virtual Multiply_Command * create_multiply_command (void) = 0;
  virtual Divide_Command * create_divide_command (void) = 0;
  virtual Modulus_Command * create_modulus_command (void) = 0;
  virtual Parenthesis_Command * create_parenthesis_command (bool response) = 0;
private: 
  //Disallow usage of the following
  Expr_Command_Factory (const Expr_Command_Factory &); 
  const Expr_Command_Factory & operator = (const Expr_Command_Factory &); 
  Stack <int> stack_;
}; 

#endif // !defined_EXPR_COMMAND_FACTORY_H_
