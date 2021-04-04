#include "Calculator.h"

Calculator::Calculator (void)
{
  // Nothing here
}

Calculator::~Calculator (void)
{
  // Nothing Allocated
}


bool Calculator::infix_to_postfix (const std::string & infix, Expr_Command_Factory & factory, Array <Expr_Command *> & postfix)
{
  std::istringstream input(infix); // create a input stream parser 
  std::string token; // current token in string/stream 
  Expr_Command * command = 0; // created command object 
  Stack <Expr_Command *> tempStack; 
  while (!input.eof ()) { 
    input >> token; 
    if (token == "+") {
      command = factory.create_add_command ();
    } else if (token == "-") { 
      command = factory.create_subtract_command ();
    } else if (token == "*") {
      command = factory.create_multiply_command ();
    } else if (token == "/") {
      command = factory.create_divide_command ();
    } else if (token == "%") {
      command = factory.create_modulus_command ();
    } else if (token == "(") {

    }
}