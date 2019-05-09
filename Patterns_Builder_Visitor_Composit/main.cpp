



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


/*
 * Cory W. Hodge
 * 4 / 4 /19
 *
 *  File: main.cpp
 *
 *  Description: Driver for Calculator Application
 *              - Client uses calculator to build algebraic expression
 *              - calculator uses composite and builder patterns to construct expression tree
 *              - client evaluates the expression with visitor pattern
 */

#include <iostream>

#include "Calculator.h"

int main() {
    
    /// Create Calculator
    Calculator *calculator = new Calculator();
    
    
    /// Create Variable to hold input from STDIN
    std::string INPUT = " ";
    
    /// Obtain input from STDIN until 'QUIT' Reached
    while (INPUT != "QUIT") {
        
        /// prompt user for input
        std::cout << "\nEnter Expression: ";
        
        /// get one line from stdin, store into string:: INPUT
        getline(std::cin, INPUT);
        
        /// if Quit Reached, Terminate
        if (INPUT == "QUIT")
            break;
        
        /// Enter Algebraic Expression
        calculator->enter_expression(INPUT);
        
        /// Evaluate the Result
        calculator->calculate_expression();
    }
    
    /// delete the calculator object
    delete calculator;
    
    /// exit
    return 0;
}