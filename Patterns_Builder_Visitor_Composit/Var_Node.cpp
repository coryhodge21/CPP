//
// Created by Cory Hodge on 2019-04-06.
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
#include "Var_Node.h"


/**
*  Initializing Constructor
*/
Var_Node::Var_Node(char symbol, int precedence) :
        Node(symbol, precedence),
        value_(0.0) {
}

/**
 * Destructor
*/
Var_Node::~ Var_Node(void) {

}

// all subclass' must interface accept method so
//  visitor class' can operate on them
void Var_Node::accept(Visitor &visitor) {
    
    visitor.visit(*this);
}

// setters/getters
void Var_Node::set_value_(float value) {
    this->value_ = value;
}

float Var_Node::get_value(void) {
    return this->value_;
}

