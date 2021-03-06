#include "Stack_Expr_Command_Factory.h"

Stack_Expr_Command_Factory::Stack_Expr_Command_Factory (Stack <int> & stack)
: stack_ (stack)
{
  //Nothing here
}

Stack_Expr_Command_Factory::~Stack_Expr_Command_Factory (void)
{
  //Nothing Allocated
}

Number_Command * Stack_Expr_Command_Factory::create_number_command (int number)
{
  Number_Command * n1 = new Number_Command (number);
  return n1;
}

Add_Command * Stack_Expr_Command_Factory::create_add_command (void)
{
  Add_Command * tempAdd = new Add_Command ();
  return tempAdd;
}

Subtract_Command * Stack_Expr_Command_Factory::create_subtract_command (void)
{
  Subtract_Command * tempSub = new Subtract_Command ();
  return tempSub;
}

Multiply_Command * Stack_Expr_Command_Factory::create_multiply_command (void)
{
  Multiply_Command * tempMult = new Multiply_Command ();
  return tempMult;
}

Divide_Command * Stack_Expr_Command_Factory::create_divide_command (void)
{
  Divide_Command * tempDiv = new Divide_Command ();
  return tempDiv;
}

Modulus_Command * Stack_Expr_Command_Factory::create_modulus_command (void)
{
  Modulus_Command * tempMod = new Modulus_Command ();
  return tempMod;
}

Parenthesis_Command * Stack_Expr_Command_Factory::create_parenthesis_command (bool response)
{
  Parenthesis_Command * tempParenthesis = new Parenthesis_Command ();
  tempParenthesis->setOpeningParenthesis (response);
  return tempParenthesis;
}

int Stack_Expr_Command_Factory::getStackTop (void)
{
  return this->stack_.top ();
}