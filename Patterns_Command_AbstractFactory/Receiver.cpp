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
#include "Receiver.h"


/**
 * Calculator as Receiver for Command Design Pattern
 */

/**
 * Constructor
 *
 *  takes expression as input
 *  and fills its: infix_ , postfix_ , and Cmd Stack
 *  then waits for decoupled evaluate command to be
 *  executed by client
 *
 * @param   INPUT : expression string from STDIN
 */
Calculator::Calculator(std::string INPUT) :
        infix_(INPUT),
        result_(new Stack<float>()),
        cmdStack_(new Stack<Abstract_Product *>()) {
    
    /// Automatically parse expression upon calculator creation
    infix_to_postfix();
}

/**
 * Destructor
 *
 */
Calculator::~Calculator() {
    delete cmdStack_;
}


/**
 * evaluate
 *
 *  This method is responsible for
 *  producing result_ of calculation
 *  and DISPLAYING TO STDOUT
 */
void Calculator::evaluate() {
    
    // evaluate Expression stack
    while (!(cmdStack_->is_empty())) {
        cmdStack_->top()->execute();
        cmdStack_->pop();
    }
    /**
     * Display RESULT TO STDOUT
     */
    std::cout << "Result:\t" << result_->top() << "\n";
}

/**
 * infix_to_postfix_()
 *
 *  This method parses the infix_ string and assigns
 *  both string postfix_ and Stack<CMD*> cmdStack_;
 *  Uses Factory Design Pattern to Create Commands
 */
void Calculator::infix_to_postfix() {
    
    /// Create Factories for Creating Calculator Command Products
    CmdFactory *cmdFactory = new CmdFactory();
    
    /// Temporary Stack for parsing input tokens
    //Stack<char> operator_stack_;
    Stack<Abstract_Product *> tempCmdStack;
    
    /// Build Command Stack Element by Element
    for (int i = 0; infix_[i]; i++) {
        
        
        /// Skipping Spaces
        if (infix_[i] == ' ')
            continue;
        
        
        // create command no matter what the char is
        Abstract_Product *next_cmd = cmdFactory->Create(infix_[i], result_);
        
        
        // Condition 1: Operand ( Number )
        if (next_cmd->precedence() == 0) {
            cmdStack_->push(next_cmd);
            
            // Append to Postfix_ string
            postfix_ += next_cmd->symbol();
            continue;
        }
            
            
            // Condition 2: op stack empty, keep one operator
            //              in temp stack until final char received
            //              from input
        else if (tempCmdStack.is_empty()) {
            tempCmdStack.push(next_cmd);
            continue;
        }
            
            
            // Condition 3: open parenthesis
        else if (next_cmd->precedence() == PAR_L_CMD_PRECEDENCE) {
            
            // push to temp stack and continue to equate until ) found
            tempCmdStack.push(next_cmd);
            continue;
        }
            
            
            // Condition 4: closing parenthesis
        else if (next_cmd->precedence() == PAR_R_CMD_PRECEDENCE) {
            
            //  pop all cmd's from temp and push to cmdStack_, continue until open par. found
            while (tempCmdStack.top()->precedence() != PAR_L_CMD_PRECEDENCE) {
                
                postfix_ += tempCmdStack.top()->symbol();
                cmdStack_->push(tempCmdStack.pop());
                
            }
            
            // discard open parenthesis
            tempCmdStack.pop();
            
            // discard next cmd and continue to next element of input
            continue;
        }
            
            
            // Condition 4: temp stack not empty,
            //              next cmd is not operator
            //              and is not closing parenthesis
        else {
            
            // move all operators in temp stack with precedence
            // greater than or equal to next cmd, to final cmdStack_
            while (!tempCmdStack.is_empty() && next_cmd->precedence() <= tempCmdStack.top()->precedence()) {
                
                // pop operators from temp and move to final cmdStack_
                postfix_ += tempCmdStack.top()->symbol();
                cmdStack_->push(tempCmdStack.pop());
                
            }
            
            // push next cmd to temporary stack to check against next
            // incoming operators
            tempCmdStack.push(next_cmd);
        }
    }
    
    // empty out any remaining operators into final cmdStack_
    while (!tempCmdStack.is_empty()) {
        postfix_ += tempCmdStack.top()->symbol();
        cmdStack_->push(tempCmdStack.pop());
    }
    
    
    // Display Current Status
    std::cout << "\nPostfix_ :\t" << postfix_ << std::endl;
    
    /// Put stack in postfix order for later evaluation
    
    // temp data array
    ArrayBase<Abstract_Product *> temp;
    
    // copy elements to array
    size_t fillLine = cmdStack_->size();
    
    // fill temp array
    for (size_t i = 0; i < fillLine; i++) {
        temp.set(i, cmdStack_->pop());
    }
    
    // refill stack with proper command order
    for (size_t i = 0; i < fillLine; i++) {
        
        // reverse stack
        cmdStack_->push(temp.get(i));
    }
}

// COMMENT: You should implement the precedence function on
// the command object since it is better place there. Otherwise,
// it is hard to add new commands without having to change the
// underlying algorithm. Also, you are using if-else statements
// as opposed to inheritance and polymorphism, which is a code
// smell.

/**
 * ADDRESSED: precedence now resides in the command object.
 *              new algorithm creates commands for all
 *              characters taken from input, including
 *              parenthesis. this allowed me to remove all extra
 *              methods i had written for calculator class, and
 *              extra methods i had written just to assist in postfixing.
 *
 *              Known Bug: For every use of the calculator, up until the
 *              terminating command 'QUIT' is entered. One calculation
 *              will be incorrect. if you re enter the calculation it will
 *              be correct and the error will not repeat .
 */

