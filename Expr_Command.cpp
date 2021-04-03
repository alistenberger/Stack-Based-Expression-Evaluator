#include "Expr_Command.h"

//
// Initializing Constructor
//
Expr_Command::Expr_Command (Stack <int> & stack)
: stack_ (stack),
number_ (NULL)
{
  // Nothing here
}

//
// Initializing constructor
//
Expr_Command::Expr_Command (Stack <int> & stack, int number)
: stack_ (stack),
number_ (number)
{
  // Nothing here
}

//
// Destructor
//
Expr_Command::~Expr_Command (void)
{
  // Nothing allocated
}
