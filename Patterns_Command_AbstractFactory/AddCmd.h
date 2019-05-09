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

#ifndef CMD_ABSFACTORY_STACKCALC_ADDCMD_H
#define CMD_ABSFACTORY_STACKCALC_ADDCMD_H

#include "ConcreteProducts.h"

#define ADDCMD_PRECEDENCE 3

/**
*  Add Command as
*  Product of Abstract Factory Pattern
 *
 * AddCmd : OpCmd : Abstract_Product
*/
//////////////////////////////////////
class AddCmd : public BinaryCmd {

private:
    
    // precedence
    int precedence_;

public:
    
    /// Including symbol && ref stack in Add Constructor so to
    /// properly extend abstract BinaryCmd evaluate method template
    AddCmd(char symbol, Stack<float> *ref_to_client_stack);
    
    /// Destructor
    ~AddCmd();
    
    /** Implimentation Of Binary Command: will return result to execute for client operations */
    float evaluate(float f1, float f2);
    
    /// get precedence
    int precedence(void);
    
};

#endif //CMD_ABSFACTORY_STACKCALC_ADDCMD_H
