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

Number_Command * Stack_Expr_Command_Factory::create_number_command (Stack <int> & stack, int number)
{
  Number_Command * n1;
  return n1;
}

Add_Command * Stack_Expr_Command_Factory::create_add_command (void)
{
  Add_Command * tempAdd;
  return tempAdd;
}

Subtract_Command * Stack_Expr_Command_Factory::create_subtract_command (void)
{
  Subtract_Command * tempSub;
  return tempSub;
}

Multiply_Command * Stack_Expr_Command_Factory::create_multiply_command (void)
{
  Multiply_Command * tempMult;
  return tempMult;
}

Divide_Command * Stack_Expr_Command_Factory::create_divide_command (void)
{
  Divide_Command * tempDiv;
  return tempDiv;
}

Modulus_Command * Stack_Expr_Command_Factory::create_modulus_command (void)
{
  Modulus_Command * tempMod;
  return tempMod;
}