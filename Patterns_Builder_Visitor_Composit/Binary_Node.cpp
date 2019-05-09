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
#include "Binary_Node.h"

/**
 *  Constructor
 */
Binary_Node::Binary_Node(void) :
        Node() {
}

/**
*  Initializing Constructor
*/
Binary_Node::Binary_Node(char symbol, int precedence) :
        Node(symbol, precedence) {
}

/**
 * Destructor
*/
Binary_Node::~Binary_Node() {

}
