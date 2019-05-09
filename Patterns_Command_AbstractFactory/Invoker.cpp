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

#include "Invoker.h"


/**
 * Invoker for Command Design Pattern
 */
/// Constructors / Destructor
Invoker::Invoker() {

}

Invoker::~Invoker() {

}

/// Invoker Methods
// assign a command object to the invoker staging memeber
void Invoker::setCommand(Abstract_Command *abstract_command) {
    
    stagedCommand = abstract_command;
}

/**
 * INVOKE
 * This method is called by the Clients Invoker Object to
 * request an action to be performed
 *
 * @return
 */
void Invoker::invoke() {
    
    // each command object interfaces an execute method
    stagedCommand->execute();
}