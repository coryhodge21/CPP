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

#include "MulCmd.h"


/**
 *      MulCommand : BinaryCmd : Abstract_Product
 *
 */

/// Constructor
MulCmd::MulCmd(char symbol, Stack<float> *ref_to_client_stack) :
        BinaryCmd(symbol, ref_to_client_stack),
        precedence_(MULCMD_PRECEDENCE) {
    
}

/// Destructor
MulCmd::~MulCmd() {

}

/// Impliment Interface Command
float MulCmd::evaluate(float f1, float f2) {
    
    // return float value to parent class
    std::cout << "MulCmd->evaluate(): \t" << f1 << " * " << f2 << " =\t" << (f1 * f2) << "\n";
    return (f1 * f2);
}

int MulCmd::precedence() {
    return this->precedence_;
}