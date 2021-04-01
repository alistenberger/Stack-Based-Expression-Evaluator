#include "Stack_Expr_Command_Factory.h"

Stack_Expr_Command_Factory::Stack_Expr_Command_Factory (Stack <int> & stack)
: stack_ (stack)
{
  //Nothing here
}

Number_Command * Stack_Expr_Command_Factory::create_number_command (int number)
{
  Number_Command n1 = Number_Command (stack_);
  return * Number_Command (stack_);
}

Add_Command * Stack_Expr_Command_Factory::create_add_command (void)
{

}

Subtract_Command * Stack_Expr_Command_Factory::create_subtract_command (void)
{
  return Subtract_Command ();
}

Multiply_Command * Stack_Expr_Command_Factory::create_multiply_command (void)
{
  return Multiply_Command ();
}

Divide_Command * Stack_Expr_Command_Factory::create_divide_command (void)
{
  return Divide_Command ();
}

Modulus_Command * Stack_Expr_Command_Factory::create_modulus_command (void)
{
  return Modulus_Command ();
}