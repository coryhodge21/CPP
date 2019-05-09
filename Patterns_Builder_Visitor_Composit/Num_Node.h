//
// Created by Cory Hodge on 2019-04-04.
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
#ifndef CS363_SPRING2019_ASSIGNMENT4_NUM_EXPR_NODE_H
#define CS363_SPRING2019_ASSIGNMENT4_NUM_EXPR_NODE_H


#include "Node.h"


class Num_Node : public Node {

private:
    
    // value of number
    float value_;
    
    // Constructor
    Num_Node(void);

public:
    
    // initializing constructor
    Num_Node(char symbol, int precedence);
    
    // Destructor
    ~ Num_Node(void);
    
    // all subclass' must interface accept method so
    //  visitor class' can operate on them
    void accept(Visitor &visitor);
    
    // 
    void set_value(float value);
    
    float get_value_(void);
    
};


#endif //CS363_SPRING2019_ASSIGNMENT4_NUM_EXPR_NODE_H
