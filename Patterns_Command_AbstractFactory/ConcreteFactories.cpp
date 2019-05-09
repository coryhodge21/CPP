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

#include "ConcreteFactories.h"

/**
 * Commands Factory
 */
 
/// Constructor
CmdFactory::CmdFactory() {
}

/// Destructor
CmdFactory::~CmdFactory() {
}

/// Client Side Method for Returning Concrete Product
Abstract_Product *CmdFactory::Create(char symbol, Stack<float> * ref_to_client_stack) {
    
    switch (symbol) {
        
        case ('+') :
            return CreateAdd(symbol, ref_to_client_stack);
        
        case ('-') :
            return CreateSub(symbol, ref_to_client_stack);
            
        case ('*') :
            return CreateMul(symbol, ref_to_client_stack);
    
        case ('/') :
            return CreateDiv(symbol, ref_to_client_stack);
            
        case('(') :
            return CreatePar_L(symbol, ref_to_client_stack);
    
        case(')') :
            return CreatePar_R(symbol, ref_to_client_stack);
    
        default:
            return CreateNum(symbol, ref_to_client_stack);
    }
    
    
}

/// Num Commands
Abstract_Product *CmdFactory::CreateNum(char symbol, Stack<float> * ref_to_client_stack) {
    return new NumCmd(symbol, ref_to_client_stack);
}

/// Binary Commands
Abstract_Product *CmdFactory::CreateAdd(char symbol, Stack<float> * ref_to_client_stack) {
    return new AddCmd(symbol, ref_to_client_stack);
}

Abstract_Product *CmdFactory::CreateSub(char symbol, Stack<float> * ref_to_client_stack) {
    return new SubCmd(symbol, ref_to_client_stack);
}

Abstract_Product *CmdFactory::CreateMul(char symbol, Stack<float> * ref_to_client_stack) {
    return new MulCmd(symbol, ref_to_client_stack);
}

Abstract_Product *CmdFactory::CreateDiv(char symbol, Stack<float> * ref_to_client_stack) {
    return new DivCmd(symbol, ref_to_client_stack);
}

/// Uranary Commsnds
Abstract_Product *CmdFactory::CreatePar_L(char symbol, Stack<float> * ref_to_client_stack) {
    return new Par_L_Cmd(symbol, ref_to_client_stack);
}

Abstract_Product *CmdFactory::CreatePar_R(char symbol, Stack<float> * ref_to_client_stack) {
    return new Par_R_Cmd(symbol, ref_to_client_stack);
}