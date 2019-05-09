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

#include "DivCmd.h"


/**
 *      DivCmd : BinaryCmd : Abstract_Prouct
 *
 */

/// Constructor
DivCmd::DivCmd(char symbol, Stack<float> *ref_to_client_stack) :
        BinaryCmd(symbol, ref_to_client_stack) ,
        precedence_(DIVCMD_PRECEDENCE){
}

/// Destructor
DivCmd::~DivCmd() {
}

/// Impliment Interface Command
float DivCmd::evaluate(float f1, float f2) {
    
    // return float value to parent class
    std::cout << "DivCmd->evaluate(): \t" << f2 << " / " << f1 << " =\t" << (f2 / f1) << "\n";
    return (f2 / f1);
}

int DivCmd::precedence() {
    return this->precedence_;
}