//
// Created by Cory Hodge on 2019-04-06.
//// -*- C++ -*-
//// $Id: Array.h 380 2010-02-08 05:10:33Z hillj $
//
////==============================================================================
///**
// * @file       Array.h
// *
// * $Id: Array.h 380 2010-02-08 05:10:33Z hillj $
// *
// * Honor Pledge:
// *
// * I pledge that I have neither given nor received any help
// * on this assignment.
// */
////==============================================================================

#include "Special_Fx_Nodes.h"

/**
 *
 *      Special Functions
 *
 */


/**
*  Constructor
*/
Special_Fx_Nodes::Special_Fx_Nodes() :
        Node() {
}

/**
 * Init Constructor
 */
Special_Fx_Nodes::Special_Fx_Nodes(char symbol, int precedence) :
        Node(symbol, precedence) {
}

/**
 * Destructor
 */
Special_Fx_Nodes::~Special_Fx_Nodes() {
    delete this;
}

/**
 *  Eval Node for Eval Visitor
 */


/**
*  Constructor
*/
Eval_Node::Eval_Node(char symbol, int precedence) :
        Special_Fx_Nodes(symbol, precedence) {
    
    this->setSymbol_(symbol);
    this->setPrecedence_(9);
}

/**
 * Destructor
*/
Eval_Node::~Eval_Node() {
    if (Lptr_)
        delete Lptr_;
}

/// Implement accept method
void Eval_Node::accept(Visitor &visitor) {
    
    visitor.visit(*this);
}





