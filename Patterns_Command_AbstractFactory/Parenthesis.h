//
// Created by Cory Hodge on 2019-03-29.
//
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


#ifndef CMD_ABSFACTORY_STACKCALC_PARENTHESIS_H
#define CMD_ABSFACTORY_STACKCALC_PARENTHESIS_H

#include "ConcreteProducts.h"

#define PAR_L_CMD_PRECEDENCE 1
#define PAR_R_CMD_PRECEDENCE 2

/**
*  Par_L_Cmd Command as
*  Product of Abstract Factory Pattern
 *
 * Par_L_Cmd : UrnaryCmd : Abstract_Product
*/
//////////////////////////////////////
class Par_L_Cmd : public UrnaryCmd {

private:
    
    // precedence
    int precedence_;

public:
    
    /// Including symbol && ref stack in Add Constructor so to
    /// properly extend abstract BinaryCmd evaluate method template
    Par_L_Cmd(char symbol, Stack<float> *ref_to_client_stack);
    
    /// Destructor
    ~Par_L_Cmd();
    
    /** Implimentation Of Binary Command: will return result to execute for client operations */
    float evaluate(float f1);
    
    /// get precedence
    int precedence(void);
    
};


/**
*  Par_R_Cmd Command as
*  Product of Abstract Factory Pattern
 *
 * Par_R_Cmd : UrnaryCmd : Abstract_Product
*/
//////////////////////////////////////
class Par_R_Cmd : public UrnaryCmd {


private:
    
    // precedence
    int precedence_;

public:
    
    /// Including symbol && ref stack in Add Constructor so to
    /// properly extend abstract BinaryCmd evaluate method template
    Par_R_Cmd(char symbol, Stack<float> *ref_to_client_stack);
    
    /// Destructor
    ~Par_R_Cmd();
    
    /** Implimentation Of Binary Command: will return result to execute for client operations */
    float evaluate(float f1);
    
    /// get precedence
    int precedence(void);
    
};













#endif //CMD_ABSFACTORY_STACKCALC_PARENTHESIS_H
