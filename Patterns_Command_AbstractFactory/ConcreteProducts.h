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
 * AbsFactory + Command Pattern
 * Concrete Products
 * Products of an AbstractProduct type can only implement
 * the virtual interface defined in Abstract Product
 * cannot create additional methods to call as
 * Client Side code uses AbstractProduct* placeholder
 */

#ifndef CMD_ABSFACTORY_STACKCALC_CONCRETEPRODUCTS_H
#define CMD_ABSFACTORY_STACKCALC_CONCRETEPRODUCTS_H

#include <iostream>             // for atof
#include "Abstract_Product.h"
#include "Stack.h"

#define NUMCMD_PRECEDENCE 0

/**
 *  Num Command as
 *  Product of Factory Pattern &&
 *  Command class of Command Pattern
 *
 *  NumCmd : Abstract_Product
 */
////////////////////////////////////////
class NumCmd : public Abstract_Product {

private:
    // character representation
    char symbol_;
    
    // numerical representation
    float value_;
    
    // precedence
    int precedence_;
    
    // ID
    bool isOp_;
    
    // Command representation
    Stack<float> *ref_to_client_stack_;

public:
    
    /// Constructor
    NumCmd(char symbol, Stack<float> *ref_to_client_stack);
    
    /// Destructor
    ~NumCmd();
    
    /// Implement Interface for Products of this Abstract Type
    void execute();
    
    /// Get Precedence
    int precedence(void);
    
    /// get symbol
    char symbol(void);
};


/**
*  Op Command as
*  Product of Abstract Factory Pattern
*
*  OpCmd : Abstract_Product
*/
//////////////////////////////////////
class BinaryCmd : public Abstract_Product {

private:
    // character representation
    char symbol_;
    
    // numerical representation
    float value_;
    
    // ID
    bool isOp_;
    
    // Command representation
    Stack<float> *ref_to_client_stack_;

public:
    
    /// Constructor
    BinaryCmd(char symbol, Stack<float> *ref_to_client_stack);
    
    ///  Virtual Destructor
    virtual ~BinaryCmd();
    
    /** All Commands will have reference to client Stack<float> result_
      * and perform its operations internally
     */
    void execute();
    
    /** Interface For all Binary Commands: will return result to execute for client operations */
    virtual float evaluate(float f1, float f2) = 0;
    
    /// Get Precedence
    virtual int precedence(void) = 0;
    
    /// get symbol
    char symbol(void);
};


/**
 *  Urnary Command as
 *  Product of Factory Pattern &&
 *  Command class of Command Pattern
 *
 *  Urnary : Abstract_Product
 */
////////////////////////////////////////
class UrnaryCmd : public Abstract_Product {

private:
    // character representation
    char symbol_;
    
    // numerical representation
    float value_;
    
    // ID
    bool isOp_;
    
    // Command representation
    Stack<float> *ref_to_client_stack_;

public:
    
    /// Constructor
    UrnaryCmd(char symbol, Stack<float> *ref_to_client_stack);
    
    /// Destructor
    ~UrnaryCmd();
    
    /// Implement Interface for Products of this Abstract Type
    void execute();
    
    /** Interface For all Urnary Commands: will return result to execute for client operations */
    virtual float evaluate(float f1) = 0;
    
    /// Get Precedence
    virtual int precedence(void) = 0;
    
    /// get symbol
    char symbol(void);
};

#endif //CMD_ABSFACTORY_STACKCALC_CONCRETEPRODUCTS_H
