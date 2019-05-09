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
 * Concrete Factories
 *  Implements Parent Interface Create()
 *  method called by client code to return
 *  Concrete Product
 */
 
#ifndef CMD_ABSFACTORY_STACKCALC_CONCRETEFACTORIES_H
#define CMD_ABSFACTORY_STACKCALC_CONCRETEFACTORIES_H

#include "Abstract_Factory.h"

// To declare template return of command to
#include "Abstract_Product.h"

// To define concrete returned products
#include "ConcreteProducts.h"
#include "AddCmd.h"
#include "SubCmd.h"
#include "MulCmd.h"
#include "DivCmd.h"
#include "Parenthesis.h"

/**
 * Commands Concrete Factory
 */

class CmdFactory : public Abstract_Factory {

public:
    CmdFactory();
    
    ~CmdFactory();
    
    /// Create Called by Client, Internal Logic Chooses Specific Command
    Abstract_Product *Create(char symbol, Stack<float> *ref_to_client_stack);
    
    /// Specific Commands
    Abstract_Product *CreateNum(char symbol, Stack<float> *ref_to_client_stack);
    
    Abstract_Product *CreateAdd(char symbol, Stack<float> *ref_to_client_stack);
    
    Abstract_Product *CreateSub(char symbol, Stack<float> *ref_to_client_stack);
    
    Abstract_Product *CreateMul(char symbol, Stack<float> *ref_to_client_stack);
    
    Abstract_Product *CreateDiv(char symbol, Stack<float> *ref_to_client_stack);
    
    Abstract_Product *CreatePar_L(char symbol, Stack<float> *ref_to_client_stack);
    
    Abstract_Product *CreatePar_R(char symbol, Stack<float> *ref_to_client_stack);
};


#endif //CMD_ABSFACTORY_STACKCALC_CONCRETEFACTORIES_H
