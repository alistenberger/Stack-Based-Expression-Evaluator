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
  std::cout << "Reached line 16" << std::endl;
  std::istringstream input(infix); // create a input stream parser 
  std::cout << "Reached line 18" << std::endl;
  std::string token; // current token in string/stream 
  std::cout << "Reached line 20" << std::endl;
  Expr_Command * command = 0; // created command object 
  Expr_Command * tempCommand = 0;
  std::cout << "Reached line 22" << std::endl;
  Stack <Expr_Command *> tempStack = Stack <Expr_Command *> ();
  std::cout << "Reached line 24" << std::endl;
  while (!input.eof ()) { 
    input >> token; 
    std::cout << "Reached line 26" << std::endl;
    //Function evaluates a token and returns the corresponding Expression Command utilizing the parameter factory
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
    std::cout << "Token converted to command successfully" << std::endl;
    //Evaluate first for number commands as these are placed directly into postfix, without any additional logic
    if (command->getPrecedence () == 0) {
      postfix.append (command);
      for (int i = 0; i < postfix.size (); i++) {
        std::cout << "Number object appended to postfix. Objects on postfix: " << postfix.get (i)->getPrecedence () << std::endl;
      }
    //Evaluate command to see if it is an opening parenthesis, if so, push it onto the stack
    } else if (command->getPrecedence () == 3) {
      if (command->isOpeningParenthesis ()) {
        tempStack.push (command);
      //Now we evaluate to see if the parenthesis is a closing parenthesis, if so, pop everything off the stack and append to postfix until the opening parenthesis is reached
      } else if (!command->isOpeningParenthesis ()) {
        while (!tempStack.top ()->isOpeningParenthesis ()) {
          std::cout << "Temp command precedence: " << tempCommand->getPrecedence () << "Is this a opening parenthesis? " << tempCommand->isOpeningParenthesis () << std::endl;
          tempCommand = tempStack.top ();
          postfix.append (tempCommand);
          tempStack.pop ();
        }
      //Now pop the opening parenthesis from the stack and delete it
        tempCommand = tempStack.top ();
        std::cout << "Line 69: Temp command precedence: " << tempCommand->getPrecedence () << "Is this a opening parenthesis? " << tempCommand->isOpeningParenthesis () << std::endl;
        tempStack.pop ();
        delete tempCommand;
        //delete the closing parenthesis
      }
    //+ - * / and % can be included here as they all follow the same rules for precedence evaluation
    } else if (command->getPrecedence () == 2 || command->getPrecedence () == 1) {
      //If the stack is empty, any command can go on it
      if (tempStack.is_empty ()) {
        tempStack.push (command);
      //If the command on top of the stack has a smaller Precedence, or if the command on top of the stack is an opening parenthesis, push command onto the stack
      } else if (command->getPrecedence () > tempStack.top ()->getPrecedence () || tempStack.top ()->getPrecedence () == 3) {
        tempStack.push (command);
      } else {
      //Until the stack is empty or a command with greater precedence is encountered, pop commands off the stack and append to postfix
        while (!tempStack.is_empty () || command->getPrecedence () <= tempStack.top ()->getPrecedence ()) {
          tempCommand = tempStack.top ();
          postfix.append (tempCommand);
          tempStack.pop ();
          if (tempStack.is_empty ()) {
            break;
          }
        }
        //Push the command to the stack after the while loop executes
        tempStack.push (command);
        for (int i = 0; i < tempStack.size (); i++) {
          std::cout << "values on tempStack: " << tempStack.get (i)->getValue () << std::endl;
        }
        for (int i = 0; i < postfix.size (); i++) {
          std::cout << "Objects on postfix: " << postfix.get (i)->getValue () << std::endl;
        }
      }
    //If a command reaches here, it is a closing parenthesis and must be deleted here, as it will remain allocated otherwise
    if (command->getPrecedence () == 3) {
      delete command;
    }
    }
  }
//Finally, if the expression is done reading, if there are any commands left on the stack, move them to postfix
  std::cout << "Reached line 100" << std::endl;
  while (tempStack.is_empty () == false) {
    std::cout << "tempStack size: " << tempStack.size () << "tempStack is empty: " << tempStack.is_empty () << std::endl;
    std::cout << "Reached line 102" << std::endl;
    std::cout << "Reached line 104" << std::endl;
    for (int i = 0; i < postfix.size (); i++) {
      std::cout << "Objects on postfix: " << postfix.get (i)->getValue () << std::endl;
    }
    //postfix.append (tempStack.top ());
    tempCommand = tempStack.top ();
    postfix.append (tempCommand);
    tempStack.pop ();
    std::cout << "Reached line 106" << std::endl;
    //tempStack.pop ();
    for (int i = 0; i < tempStack.size (); i++) {
      std::cout << "values on tempStack: " << tempStack.get (i)->getValue () << std::endl;
    }
    for (int i = 0; i < postfix.size (); i++) {
      std::cout << "Objects on postfix: " << postfix.get (i)->getValue () << std::endl;
    }
    std::cout << "tempStack size: " << tempStack.size () << "tempStack is empty: " << tempStack.is_empty () << std::endl;
    std::cout << "Reached line 108" << std::endl;
  }
  std::cout << "returning true" << std::endl;
  return true;
}

bool Calculator::evaluate_postfix (Array <Expr_Command *> & postfix, Stack <int> & stack)
{
  typedef ArrayIterator <Expr_Command *> Expr_Command_Iterator; 
  for (Expr_Command_Iterator iterator (postfix); !iterator.isDone (); iterator.advance ()) {
    std::cout << "Executing command of precedence: " << (*iterator)->getPrecedence () << std::endl;
    (*iterator)->execute (stack);
    std::cout << &(*iterator) << std::endl;
    delete (*iterator);
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
    Stack <int> * result = new Stack <int> ();
    Stack <int> * factoryStack = new Stack <int> ();
    Stack_Expr_Command_Factory factory (*factoryStack);
    Array <Expr_Command *> postfix = Array <Expr_Command *> ();
    std::cout << "Passing equation to calculator" << std::endl;
    this->infix_to_postfix (infix, factory, postfix);
    std::cout << "Converting infix to postfix" << std::endl;
    this->evaluate_postfix (postfix, *result);
    std::cout << "postfix evaluated" << std::endl;
    int answer = result->top ();
    std::cout << "Answer to equation: " << infix << " is: " << answer << std::endl;
    delete result;
    delete factoryStack;
  }
  return 0;
}
