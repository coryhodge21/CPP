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
 * Created by Cory Hodge
 * ConcreteProducts.cpp
 * Definitions of Procducts (Commands)
 */

#include "ConcreteProducts.h"


/**
 *      NumCommand : Abstract_Product
 *
 */

/// Constructor
NumCmd::NumCmd(char symbol, Stack<float> *ref_to_client_stack) :
        symbol_(symbol),
        value_(0.0),
        precedence_(NUMCMD_PRECEDENCE),
        isOp_(false),
        ref_to_client_stack_(new Stack<float>()) {
    
    /// assign reference stack to Clients stack
    ref_to_client_stack_ = ref_to_client_stack;
    
    /// Store float value_
    value_ = atof(&symbol);
}

/// Destructor
NumCmd::~NumCmd() {
}

/// Impliment Interface Command
void NumCmd::execute() {
    
    /// Push Value of Num Command to Client Stack
    ref_to_client_stack_->push(value_);
}

/// Precedence
int NumCmd::precedence() {
    return this->precedence_;
}

/// character symbol
char NumCmd::symbol(){
    return this->symbol_;
}



/**
 *      OpCommand : Abstract_Product
 *
 *      Operators have no value of their own, they perform work
 *      on clients members
 */

/// Constructor
BinaryCmd::BinaryCmd(char symbol, Stack<float> *ref_to_client_stack) :
        symbol_(symbol),
        value_(0.0),
        isOp_(true),
        ref_to_client_stack_(new Stack<float>()) {
    
    /// assign reference stack to Clients stack
    ref_to_client_stack_ = ref_to_client_stack;
}

/// Destructor
BinaryCmd::~BinaryCmd() {

}

/// Impliment Interface Command
void BinaryCmd::execute() {
    
    /// Binary Operators take two arguments, in postfix they are always first
    float f1 = ref_to_client_stack_->top();
    ref_to_client_stack_->pop();
    float f2 = ref_to_client_stack_->top();
    ref_to_client_stack_->pop();
    
    /// Store Result
    value_ = this->evaluate(f1, f2);
    
    /// Push result of thisCmds execution to client stack
    ref_to_client_stack_->push(value_);
}

/// character symbol
char BinaryCmd::symbol(){
    return this->symbol_;
}


/**
 *      UrnaryCmd : Abstract_Product
 *
 */

/// Constructor
UrnaryCmd::UrnaryCmd(char symbol, Stack<float> *ref_to_client_stack) :
        symbol_(symbol),
        value_(0.0),
        isOp_(true),
        ref_to_client_stack_(new Stack<float>()) {
    
    /// assign reference stack to Clients stack
    ref_to_client_stack_ = ref_to_client_stack;
}

/// Destructor
UrnaryCmd::~UrnaryCmd() {
}

/// Impliment Interface Command
void UrnaryCmd::execute() {
    
    /// Binary Operators take two arguments, in postfix they are always first
    float f1 = ref_to_client_stack_->top();
    ref_to_client_stack_->pop();

    
    /// Store Result
    value_ = this->evaluate(f1);
    
    /// Push result of thisCmds execution to client stack
    ref_to_client_stack_->push(value_);
}

/// character symbol
char UrnaryCmd::symbol(){
    return this->symbol_;
}