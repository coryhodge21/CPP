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
#include "Abstract_Command.h"

#ifndef CMD_ABSFACTORY_STACKCALC_COMMAND_H
#define CMD_ABSFACTORY_STACKCALC_COMMAND_H


class EvalCommand : public Abstract_Command {

private:
    /// Calculator Aggregate Object for Calculator method refrencing
    Calculator *calculator_;

public:
    
    /// Constructor ( * type )
    EvalCommand(Calculator *calculator);
    
    /// Destructor
    ~EvalCommand();
    
    /// method for invoking aggregate class methods
    void execute();
};

#endif //CMD_ABSFACTORY_STACKCALC_COMMAND_H
