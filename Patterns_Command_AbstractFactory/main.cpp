// -*- C++ -*-
// $Id: Array.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
 * @file       Array.h
 *
 * $Id: Array.h 380 2010-02-08 05:10:33Z hillj $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

/**
 *  Cory W. Hodge
 *  Expression Calculator
 *
 *  This program uses the Abstract Factory
 *  && Command Design Patterns to solve
 *  algebraic expressions
 */

#include <iostream>

#include "Receiver.h"
#include "Invoker.h"
#include "Command.h"

int main(int argc, char *argv[]) {
    
    /// Create Variable to hold input from STDIN
    std::string INPUT;
    
    /// Obtain input from STDIN until 'QUIT' Reached
    while (true) {
        
        /// prompt user for input
        std::cout << "\nEnter Expression: ";
        
        /// get one line from stdin, store into string:: INPUT
        getline(std::cin, INPUT);
        
        /// if Quit Reached, Terminate
        if (INPUT == "QUIT")
            break;
            
        /// Create Calculator (Reciever) Object to handle Expression
        Calculator *calculator = new Calculator(INPUT);
        
        /// Create Command for evaluating calculator (Command Pattern)
        EvalCommand *evaluate = new EvalCommand(calculator);
        
        /// Create Invoker to give client decoupled control to execute the 'Calculator-> evaluate()' command
        Invoker *client = new Invoker();
        
        /// Stage the Clients Next command choice
        client->setCommand(evaluate);
        
        /// Evaluate the Expression by using client invoker
        client->invoke();
        
        delete calculator;
        delete evaluate;
        delete client;
        
    }
    
    
    return 0;
}
