//
// Created by Cory Hodge on 2019-04-05.
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

#include "Mod_Node.h"


/**
*  Initializing Constructor
*/
Mod_Node::Mod_Node(char symbol, int precedence) :
        Binary_Node(symbol, precedence) {
}

/**
 * Destructor
*/
Mod_Node::~Mod_Node() {

}


/// Implement accept method
void Mod_Node::accept(Visitor &visitor) {

}
