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

#include "AddCmd.h"

/**
 *      AddCommand : BinaryCmd : Abstract_Prouct
 *
 */

/// Constructor
AddCmd::AddCmd(char symbol, Stack<float> *ref_to_client_stack) :
        BinaryCmd(symbol, ref_to_client_stack),
        precedence_(ADDCMD_PRECEDENCE){
}

/// Destructor
AddCmd::~AddCmd() {
}

/// Impliment Interface Command
float AddCmd::evaluate(float f1, float f2) {
    
    // return float value to parent class
    std::cout << "AddCmd->evaluate(): \t" << f1 << " + " << f2 << " =\t" << (f1 + f2) << "\n";
    return (f1 + f2);
}

int AddCmd::precedence() {
    return this->precedence_;
}

