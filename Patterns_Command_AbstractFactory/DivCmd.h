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

#ifndef CMD_ABSFACTORY_STACKCALC_DIVCMD_H
#define CMD_ABSFACTORY_STACKCALC_DIVCMD_H

#include "ConcreteProducts.h"

#define DIVCMD_PRECEDENCE 4

/**
*  Div Command as
*  Product of Abstract Factory Pattern
 *
 * DivCmd : OpCmd : Abstract_Product
*/
class DivCmd : public BinaryCmd {

private:
    
    // precedence
    int precedence_;

public:
    
    /// Including symbol && ref to Stack<float>Result_  in Add Constructor so to
    /// properly extend abstract BinaryCmd evaluate method template
    DivCmd(char symbol, Stack<float> *ref_to_client_stack);
    
    /// Destructor
    ~DivCmd();
    
    /** Implimentation Of Binary Command: will return result to execute for client operations */
    float evaluate(float f1, float f2);
    
    
    /// get precedence
    int precedence(void);
    
};

#endif //CMD_ABSFACTORY_STACKCALC_DIVCMD_H
