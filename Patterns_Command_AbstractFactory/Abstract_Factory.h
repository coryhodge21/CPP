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
 * AbsFactory Pattern
 * Abstract Factory
 *  Interfaces the Create() method
 *  that Concrete Factories extending
 *  this abstract must implement.
 *  Ensures Return type matches
 *  Product Interface
 */

#ifndef CMD_ABSFACTORY_STACKCALC_ABSTRACTFACTORY_H
#define CMD_ABSFACTORY_STACKCALC_ABSTRACTFACTORY_H

#include "Stack.h"

/// Declaring Existance of Abstract Product for Compiler
class Abstract_Product;

/// Abstract Factory
class Abstract_Factory {

public:
    
    /**
     * Pure Virtual Interface for
     * Child Factories of this Abstract Class
     */
    virtual Abstract_Product *CreateNum(char symbol, Stack<float> *ref_to_client_stack) = 0;
    
    virtual Abstract_Product *CreateAdd(char symbol, Stack<float> *ref_to_client_stack) = 0;
    
    virtual Abstract_Product *CreateSub(char symbol, Stack<float> *ref_to_client_stack) = 0;
    
    virtual Abstract_Product *CreateMul(char symbol, Stack<float> *ref_to_client_stack) = 0;
    
    virtual Abstract_Product *CreateDiv(char symbol, Stack<float> *ref_to_client_stack) = 0;
    
    virtual Abstract_Product *CreatePar_L(char symbol, Stack<float> *ref_to_client_stack) = 0;
    
    virtual Abstract_Product *CreatePar_R(char symbol, Stack<float> *ref_to_client_stack) = 0;
};

#endif //CMD_ABSFACTORY_STACKCALC_ABSTRACTFACTORY_H
