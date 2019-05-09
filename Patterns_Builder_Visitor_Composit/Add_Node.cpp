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
#include "Add_Node.h"


/**
*  Initializing Constructor
*/
Add_Node::Add_Node(char symbol, int precedence) :
        Binary_Node(symbol, precedence) {
}

/**
 * Destructor
*/
Add_Node::~Add_Node() {

}


/// Implement accept method
void Add_Node::accept(Visitor &visitor) {
    
    visitor.visit(*this);
}
