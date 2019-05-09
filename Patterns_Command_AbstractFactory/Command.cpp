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

#include "Command.h"

EvalCommand::EvalCommand(Calculator *calculator) :
        calculator_(calculator) {
    
}

EvalCommand::~EvalCommand() {

}

void EvalCommand::execute() {
    calculator_->evaluate();
}
