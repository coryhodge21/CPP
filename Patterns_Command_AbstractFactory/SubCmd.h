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


#ifndef CMD_ABSFACTORY_STACKCALC_SUBCMD_H
#define CMD_ABSFACTORY_STACKCALC_SUBCMD_H

#include "ConcreteProducts.h"

#define SUBCMD_PRECEDENCE 3

/**
*  Sub Command as
*  Product of Abstract Factory Pattern
 *
 * SubCmd : OpCmd : Abstract_Product
*/
class SubCmd : public BinaryCmd {


private:
    
    // precedence
    int precedence_;
    
public:
    
    /// Including symbol && ref stack in Add Constructor so to
    /// properly extend abstract BinaryCmd evaluate method template
    SubCmd(char symbol, Stack<float> *ref_to_client_stack);
    
    /// Destructor
    ~SubCmd();
    
    /** Implimentation Of Binary Command: will return result to execute for client operations */
    float evaluate(float f1, float f2);
    
    /// get precedence
    int precedence(void);
    

    
};

#endif //CMD_ABSFACTORY_STACKCALC_SUBCMD_H
