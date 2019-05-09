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
#ifndef CS363_SPRING2019_ASSIGNMENT4_VAR_NODE_H
#define CS363_SPRING2019_ASSIGNMENT4_VAR_NODE_H


#include "Node.h"


class Var_Node : public Node {

private:
    
    // value of number
    float value_;
    
    // Constructor
    Var_Node(void);

public:
    
    // initializing constructor
    Var_Node(char symbol, int precedence);
    
    // Destructor
    ~ Var_Node(void);
    
    // all subclass' must interface accept method so
    //  visitor class' can operate on them
    void accept(Visitor &visitor);
    
    // setters/getters
    void set_value_(float value);
    
    float get_value(void);
    
};

#endif //CS363_SPRING2019_ASSIGNMENT4_VAR_NODE_H
