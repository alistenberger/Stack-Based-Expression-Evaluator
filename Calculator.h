#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include "Expr_Command_Factory.h"
#include "Expr_Command.h"
#include "Stack_Expr_Command_Factory.h"
#include "Binary_Op_Command.h"
#include "Number_Command.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Modulus_Command.h"
#include "Stack.h"
#include "Queue.h"
#include "Array.h"
#include "Base_Array.h"
#include "Fixed_Array.h"
#include <iostream>
#include <sstream>
#include <string>
#include "ArrayIterator.h"

/**
 * @class Calculator
 *
 * A calculator which utilizes a Stack-Based Evaluator to calculate a given expression
 */

class Calculator
{
public: 
  /// Constructor
  Calculator (void);
  
  /// Destructor
  ~Calculator (void);

  /**
   * Parses an infix expression to postfix format
   * 
   * @param[in]     infix     the infix format delineated by spaces (or QUIT)
   * @param[in]     factory   the expression command factory responsible for generation of expression commands
   * @param[in]     postfix   the array which will store the postfix expression
   * 
   * @retval        returns true on successful completion
   */
  bool infix_to_postfix (const std::string & infix, Expr_Command_Factory & factory, Array <Expr_Command *> & postfix);
  
  /**
   * Evaluates a postfix expression utilizing a stack
   * 
   * @param[in]     postfix   an array class object containing the postfix expression
   * 
   * @retval        returns true on successful completion
   */
  bool evaluate_postfix (Array <Expr_Command *> & postfix, Stack <int> & stack);

  int run (void);
};

#endif // !defined _CALCULATOR_H_