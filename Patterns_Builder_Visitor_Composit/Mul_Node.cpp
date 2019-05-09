//
// Created by Cory Hodge on 2019-04-05.
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
#include "Mul_Node.h"

/**
*  Initializing Constructor
*/
Mul_Node::Mul_Node(char symbol, int precedence) :
        Binary_Node(symbol, precedence) {
}

/**
 * Destructor
*/
Mul_Node::~Mul_Node() {

}


/// Implement accept method
void Mul_Node::accept(Visitor &visitor) {
    
    visitor.visit(*this);
}
