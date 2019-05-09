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
 * Calculator Class
 *
 * Command Pattern
 * This Class is a Receiver
 * it defines only the methods that
 * can be performed on receiver type
 * Objects. The Command Object will
 * call on these methods when defining
 * different Invoker Commands
 */

// Begin Reciever(Calculator)
#ifndef CMD_ABSFACTORY_STACKCALC_CALCULATOR_H
#define CMD_ABSFACTORY_STACKCALC_CALCULATOR_H

// Librarys
#include <iostream>
#include <string>

// For creating postfix stack
// used in infix-to_postfix() && evaluate()
#include "Stack.h"

// for defining Stack<> return Type
#include "Abstract_Product.h"

// For creating commands in the
// infix_to_postfix() method
#include "ConcreteFactories.h"



/**
 * AbsProd is a placeholder for
 * returning Concrete Command Products
 */

/// CALCULATOR (RECEIVER)
class Calculator {

private:
    
    /// Private Members for calculations and features
    std::string infix_;
    
    std::string postfix_;
    
    /// Stack to produce result of command execution
    Stack<float> *result_;
    
    /// Stack of Commands to await Invoker->invoke()
    Stack<Abstract_Product *> *cmdStack_;

public:
    
    /// Constructors
    Calculator(std::string INPUT);
    
    /// Destructor
    ~Calculator();
    
    /** convert infix string expression to postfix string,
      * fill Stack<Cmd*> for postfix evaluation    */
    void infix_to_postfix();
    
    /// evaluate postfix expression stack and display result
    void evaluate();
    
    /// methods to assist post-fixing
    bool isNum(char num);
    
    bool isOp(char op);
    
    int precedence(char p);
};

#endif //CMD_ABSFACTORY_STACKCALC_CALCULATOR_H
