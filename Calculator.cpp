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
      command = factory.create_parenthesis_command (true);
    } else if (token == ")") {
      command = factory.create_parenthesis_command (false);
    } else {
      if (token[0] == '-' && std::isdigit(token[1]) || std::isdigit(token[0])) {
        int tempInt = std::stoi (token);
        command = factory.create_number_command (tempInt);
      }
    }
    if (command->getPrecedence () == 0) {
      postfix.append (command);
    } else if (command->getPrecedence () == 3 && command->isOpeningParenthesis ()) {
      tempStack.push (command);
    } else if (command->getPrecedence () == 3 && !command->isOpeningParenthesis ()) {
      Expr_Command * tempCommand = tempStack.top ();
      while (!tempCommand->isOpeningParenthesis ()) {
        postfix.append (tempCommand);
        tempStack.pop ();
      }
    } else if (command->getPrecedence () == 2 || command->getPrecedence () == 1) {
      if (tempStack.is_empty () || command->getPrecedence () > tempStack.top ()->getPrecedence ()) {
        tempStack.push (command);
      } else {
        while (command->getPrecedence () <= tempStack.top ()->getPrecedence () || !tempStack.is_empty ()) {
          Expr_Command * tempCommand = tempStack.top ();
          postfix.append (tempCommand);
          tempStack.pop ();
        }
        tempStack.push (command);
      }
    }
  }
}

bool Calculator::evaluate_postfix (Array <Expr_Command *> & postfix)
{
  typedef ArrayIterator <Expr_Command *> Expr_Command_Iterator; 
  for (Expr_Command_Iterator iterator (postfix); !iterator.isDone (); iterator.advance ()) {
    Expr_Command * command = (Expr_Command *)*iterator;
    command->execute ();
  }
  return true;
}

int Calculator::run (void) {
  bool keepGoing = true;
  while (keepGoing) {
    std::cout << "Please enter an expression to be evaluated or type 'QUIT' to exit: " << std::endl;
    std::string infix;
    std::cin >> infix;
    if (infix == "QUIT") {
      break;
    }
    Stack <int> result;
    Stack_Expr_Command_Factory factory (result);
    Array <Expr_Command *> postfix;
    this->infix_to_postfix (infix, factory, postfix);
    this->evaluate_postfix (postfix);
    int answer = result.top ();
    std::cout << answer << std::endl;
    return (0);
}
