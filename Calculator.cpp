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
    std::cout << token << std::endl;
    std::cout << "TempStack size: " << tempStack.size () << std::endl;
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
    std::cout << "Command Precedence: " << command->getPrecedence () << std::endl;
    if (command->getPrecedence () == 0) {
      postfix.append (command);
      std::cout << "Number command appended to postfix at address: " << std::endl;
      std::cout << "Command of precedence: " << command->getPrecedence () << " applied to postfix. Size is now: " << postfix.size () << std::endl;
      std::cout << command << std::endl;
    } else if (command->getPrecedence () == 3 && command->isOpeningParenthesis ()) {
      tempStack.push (command);
      std::cout << tempStack.top () << std::endl;
    } else if (command->getPrecedence () == 3 && !command->isOpeningParenthesis ()) {
      Expr_Command * tempCommand = tempStack.top ();
      std::cout << tempStack.top () << std::endl;
      while (!tempCommand->isOpeningParenthesis ()) {
        postfix.append (tempCommand);
        std::cout << "Command of precedence: " << tempCommand->getPrecedence () << " applied to postfix. Size is now: " << postfix.size () << std::endl;
        tempStack.pop ();
      }
    } else if (command->getPrecedence () == 2 || command->getPrecedence () == 1) {
      if (tempStack.is_empty ()) {
        tempStack.push (command);
        std::cout << "Command of precedence: " << command->getPrecedence () << " applied to tempStack at address: " << std::endl;
        std::cout << tempStack.top () << std::endl;
      } else if (command->getPrecedence () > tempStack.top ()->getPrecedence ()) {
        tempStack.push (command);
        std::cout << "Command of precedence: " << command->getPrecedence () << " applied to tempStack at address: " << std::endl;
        std::cout << tempStack.top () << std::endl;
      } else {
        while (!tempStack.is_empty () || command->getPrecedence () <= tempStack.top ()->getPrecedence ()) {
          Expr_Command * tempCommand = tempStack.top ();
          std::cout << tempStack.top () << std::endl;
          postfix.append (tempCommand);
          std::cout << "Line 75 Command of precedence: " << tempCommand->getPrecedence () << " removed from stack and applied to postfix at address: " << std::endl;
          std::cout << "Line 75 Command of precedence: " << tempCommand->getPrecedence () << " applied to postfix. Size is now: " << postfix.size () << std::endl;
          tempStack.pop ();
          if (tempStack.is_empty ()) {
            break;
          }
        }
        tempStack.push (command);
        std::cout << tempStack.top () << std::endl;
        std::cout << "Command of precedence: " << command->getPrecedence () << " applied to tempStack at address: " << tempStack.top () << std::endl;
      }
    }
  }
  while (!tempStack.is_empty ()) {
    Expr_Command * tempCommand = tempStack.top ();
    postfix.append (tempCommand);
    std::cout << "Command of precedence: " << tempCommand->getPrecedence () << " popped from Stack and applied to postfix. Size is now: " << postfix.size () << std::endl;
    tempStack.pop ();
  }
  std::cout << "Postfix size: " << postfix.size () << std::endl;
  return true;
}

bool Calculator::evaluate_postfix (Array <Expr_Command *> & postfix, Stack <int> & stack)
{
  typedef ArrayIterator <Expr_Command *> Expr_Command_Iterator; 
  for (Expr_Command_Iterator iterator (postfix); !iterator.isDone (); iterator.advance ()) {
    std::cout << "Executing command of precedence: " << (*iterator)->getPrecedence () << std::endl;
    (*iterator)->execute (stack);
    std::cout << &(*iterator) << std::endl;
  }
  return true;
}

int Calculator::run (void) {
  bool keepGoing = true;
  while (keepGoing) {
    std::cout << "Please enter an expression to be evaluated or type 'QUIT' to exit: " << std::endl;
    std::string infix;
    std::getline(std::cin, infix);
    if (infix == "QUIT") {
      break;
    }
    std::cout << "Processing..." << std::endl;
    Stack <int> result;
    Stack_Expr_Command_Factory factory (result);
    Array <Expr_Command *> postfix;
    std::cout << "Passing equation to calculator" << std::endl;
    this->infix_to_postfix (infix, factory, postfix);
    std::cout << "Converting infix to postfix" << std::endl;
    this->evaluate_postfix (postfix, result);
    std::cout << "postfix evaluated" << std::endl;
    int answer = result.top ();
    std::cout << "Answer to equation: " << infix << " is: " << answer << std::endl;
  }
  return 0;
}
