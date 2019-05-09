//
// Created by Cory Hodge on 2019-03-29.
//



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


#include "Parenthesis.h"

/**
 *      Par_L_Cmd : BinaryCmd : Abstract_Prouct
 *
 */

/// Constructor
Par_L_Cmd::Par_L_Cmd(char symbol, Stack<float> *ref_to_client_stack) :
        UrnaryCmd(symbol, ref_to_client_stack),
        precedence_(PAR_L_CMD_PRECEDENCE) {
}

/// Destructor
Par_L_Cmd::~Par_L_Cmd() {
}

/// Impliment Interface Command
float Par_L_Cmd::evaluate(float f1) {
    
    // return float value to parent class
    std::cout << "Par_L_Cmd->evaluate(): \t" << f1  << "\n";
    return (f1);
}
int Par_L_Cmd::precedence(void) {
    return this->precedence_;
}




/**
 *      Par_R_Cmd : BinaryCmd : Abstract_Prouct
 *
 */

/// Constructor
Par_R_Cmd::Par_R_Cmd(char symbol, Stack<float> *ref_to_client_stack) :
        UrnaryCmd(symbol, ref_to_client_stack),
        precedence_(PAR_R_CMD_PRECEDENCE) {
}

/// Destructor
Par_R_Cmd::~Par_R_Cmd() {
}

/// Impliment Interface Command
float Par_R_Cmd::evaluate(float f1) {
    
    // return float value to parent class
    std::cout << "Par_R_Cmd->evaluate(): \t" << f1  << "\n";
    return (f1);
}

int Par_R_Cmd::precedence() {
    return this->precedence_;
}