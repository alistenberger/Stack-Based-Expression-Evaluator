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
  Expr_Command * command = nullptr; // created command object 
  Expr_Command * tempCommand = nullptr;
  Stack <Expr_Command *> tempStack = Stack <Expr_Command *> ();
  Array <int> parenthesisTracker = Array <int> (0);
  int parenthesisIterator = 0;
  while (!input.eof ()) { 
    input >> token; 
    //Function evaluates a token and returns the corresponding Expression Command utilizing the parameter factory
    //If a token is an opening parenthesis, an array tracking parenthesis and operators contained within the parenthesis is incremented
    if (token == "(") {
      if (parenthesisTracker.size () == 0) {
        parenthesisTracker.append (0);
      } else {
        parenthesisTracker.append (0);
        parenthesisIterator++;
      }
      //Get the next token in the expression so evaluation can continue and the program isn't accessing a command object that isn't there
      input >> token;
    //Evaluate closing parenthesis and handle the parenthesis array and iterator
    } else if (token == ")") {
    //The while loop addresses the case in which a subsequent operator is a parenthesis
      while (token == ")") {
        int stackPop = parenthesisTracker.get (parenthesisIterator);
        for (stackPop; stackPop > 0; stackPop --) {
          tempCommand = tempStack.top ();
          postfix.append (tempCommand);
          tempStack.pop ();
        }
        parenthesisTracker.resize (parenthesisTracker.size () -1);
        if (parenthesisIterator != 0) {
          parenthesisIterator -= 1;
        }
        input >> token;
      }
    } 
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
    } else {
      if (token[0] == '-' && std::isdigit(token[1]) || std::isdigit(token[0])) {
        int tempInt = std::stoi (token);
        command = factory.create_number_command (tempInt);
      }
    }     
      // COMMENT: Improve the design of your commands to reduce the design
      // complexity of this method. Right now, there are too many if-else
      // statements, and a lot of duplicate code.

      //SOULTION: I removed the parenthesis as an expression command object, removing all if/else
      //statements pertinent to the evaluation of parenthesis objects. I also merged other if/else into && and || in the conditionals
      // to reduce complexity and number of if/else statements
      
    //Evaluate first for number commands as these are placed directly into postfix, without any additional logic
    if (command->getPrecedence () == 0) {
      postfix.append (command);
    //+ - * / and % can be included here as they all follow the same rules for precedence evaluation
    } else if (command->getPrecedence () == 2 || command->getPrecedence () == 1) {
      //If the stack is empty, any command can go on it
      if (tempStack.is_empty () || command->getPrecedence () > tempStack.top ()->getPrecedence ()) {
        tempStack.push (command);
        if (parenthesisTracker.size () != 0) {
          parenthesisTracker.set (parenthesisIterator, parenthesisTracker.get (parenthesisIterator) + 1);
        }
      } else {
      //Until the stack is empty or a command with greater precedence is encountered, pop commands off the stack and append to postfix
        while (!tempStack.is_empty () && command->getPrecedence () <= tempStack.top ()->getPrecedence ()) {
          tempCommand = tempStack.top ();
          postfix.append (tempCommand);
          tempStack.pop ();
        }
        //Push the command to the stack after the while loop executes
        tempStack.push (command);
        if (parenthesisTracker.size () != 0) {
          parenthesisTracker.set (parenthesisIterator, parenthesisTracker.get (parenthesisIterator) + 1);
        }
      }
    }
  }
  input.clear ();
  token = "";
  command = nullptr;
//Finally, if the expression is done reading, if there are any commands left on the stack, move them to postfix
  while (!tempStack.is_empty ()) {
    //postfix.append (tempStack.top ());
    tempCommand = tempStack.top ();
    postfix.append (tempCommand);
    tempStack.pop ();
  }
  tempCommand = nullptr;
  tempStack.clear ();
  return true;
}

bool Calculator::evaluate_postfix (Array <Expr_Command *> & postfix, Stack <int> & stack)
{
  typedef ArrayIterator <Expr_Command *> Expr_Command_Iterator; 
  for (Expr_Command_Iterator iterator (postfix); !iterator.isDone (); iterator.advance ()) {
    (*iterator)->execute (stack);
    std::cout << "Executing iterator: " << ((*iterator)->getValue ()) << std::endl;
    delete *iterator;
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
    Stack <int> result = Stack <int> ();
    Stack <int> factoryStack = Stack <int> ();
    Stack_Expr_Command_Factory factory (factoryStack);
    Array <Expr_Command *> postfix = Array <Expr_Command *> ();
    std::cout << "Passing equation to calculator" << std::endl;
    std::cout << "Converting infix to postfix" << std::endl;
    this->infix_to_postfix (infix, factory, postfix);
    std::cout << "Evaluating postfix expression..." << std::endl;
    this->evaluate_postfix (postfix, result);
    std::cout << "postfix evaluated" << std::endl;
    int answer = result.top ();
    std::cout << "Answer to equation: " << infix << " is: " << answer << std::endl;
  }
  return 0;
}
