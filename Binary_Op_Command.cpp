#include "Binary_Op_Command.h"

Binary_Op_Command::Binary_Op_Command (Stack <int> & stack) 
: Expr_Command (stack)
{ 
  //Nothing here
} 

bool Binary_Op_Command::execute (void)
{ 
  int n2 = stack_.top ();
  stack_.pop ();
  int n1 = stack_.top ();
  stack_.pop (); 
  int result = this->evaluate (n1, n2); 
  stack_.push (result); 
} 

