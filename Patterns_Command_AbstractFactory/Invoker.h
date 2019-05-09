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
 * Command Pattern
 * Invoker
 */

#ifndef CMD_ABSFACTORY_STACKCALC_INVOKER_H
#define CMD_ABSFACTORY_STACKCALC_INVOKER_H

#include "Abstract_Command.h"


class Invoker {

private:
    
    /// Aggregate Command Object (Concrete Command in implementation code)
    Abstract_Command *stagedCommand;
    
public:
    
    /// Constructors / Destructor
    Invoker();
    
    ~Invoker();
    
    /// Invoker Methods
    // assign a command object to the invoker staging member
    void setCommand(Abstract_Command *abstract_command);
    
    /**
     * INVOKE
     * This method is called by the Clients Invoker Object to
     * request an action to be performed
     *
     * @return
     */
    void invoke();
    
};

#endif //CMD_ABSFACTORY_STACKCALC_INVOKER_H
