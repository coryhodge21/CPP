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
#include "Div_Node.h"


/**
*  Initializing Constructor
*/
Div_Node::Div_Node(char symbol, int precedence) :
        Binary_Node(symbol, precedence) {
}

/**
 * Destructor
*/
Div_Node::~Div_Node() {

}


/// Implement accept method
void Div_Node::accept(Visitor &visitor) {
    visitor.visit(*this);
}

