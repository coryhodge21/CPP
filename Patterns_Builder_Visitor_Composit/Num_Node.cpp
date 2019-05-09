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
#include "Num_Node.h"


/**
*  Initializing Constructor
*/
Num_Node::Num_Node(char symbol, int precedence) :
        Node(symbol, precedence) {
    
    // get float value of this character
    this->set_value(std::atof(&symbol));
}

/**
 * Destructor
*/
Num_Node::~ Num_Node(void) {

}

// all subclass' must interface accept method so
//  visitor class' can operate on them
void Num_Node::accept(Visitor &visitor) {
    
    visitor.visit(*this);
}

// Number Node Methods
void Num_Node::set_value(float value) {
    this->value_ = value;
}

float Num_Node::get_value_(void) {
    return this->value_;
}

