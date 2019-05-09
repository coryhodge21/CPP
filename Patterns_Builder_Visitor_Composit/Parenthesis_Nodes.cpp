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
#include "Parenthesis_Nodes.h"


/**
 *      Left Open Parenthesis (
 */


/**
*  Initializing Constructor
*/
Par_L_Node::Par_L_Node(char symbol, int precedence) :
        Node(symbol, precedence) {
    
}

/**
 * Destructor
*/
Par_L_Node::~ Par_L_Node(void) {

}

// all subclass' must interface accept method so
//  visitor class' can operate on them
void Par_L_Node::accept(Visitor &visitor) {
    
    visitor.visit(*this);
}


/**
 *      Right Close Parenthesis )
 */


/**
*  Initializing Constructor
*/
Par_R_Node::Par_R_Node(char symbol, int precedence) :
        Node(symbol, precedence) {
    
}

/**
 * Destructor
 */
Par_R_Node::~ Par_R_Node(void) {

}

// all subclass' must interface accept method so
//  visitor class' can operate on them
void Par_R_Node::accept(Visitor &visitor) {
    
    visitor.visit(*this);
}
