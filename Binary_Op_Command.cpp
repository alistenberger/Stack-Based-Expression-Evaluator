#include "Binary_Op_Command.h"

Binary_Op_Command::Binary_Op_Command (Stack <int> & stack) 
: Expr_Command (stack)
{ 
  //Nothing here
} 

bool Binary_Op_Command::execute (Stack <int> & stack)
{ 
  int n2 = stack.top ();
  stack.pop ();
  int n1 = stack.top ();
  stack.pop (); 
  int result = this->evaluate (n1, n2); 
  stack.push (result); 
  return true;
} 

