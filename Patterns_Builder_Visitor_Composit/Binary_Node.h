/*
 * Created by Cory Hodge on 2019-04-04.
 *
 * Binary_Node.h
 *
 * Base Node for representing binary operators
 *  of algebraic expression
 *
 * Inherits interface method '  int eval() ' that is expected
 *  to evaluate the composite expression tree relative to
 *  the calling nodes position.
 *
 */
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
#ifndef CS363_SPRING2019_ASSIGNMENT4_BINARY_EXPR_NODE_H
#define CS363_SPRING2019_ASSIGNMENT4_BINARY_EXPR_NODE_H


#include "Node.h"

class Binary_Node : public Node {


public:
    
    // Default Constructor
    Binary_Node(void);
    
    // Initializing Constructor
    Binary_Node(char symbol, int precedence);
    
    // virtual destructor
    virtual ~Binary_Node(void);
    
    // all subclass' must interface accept method so
    //  visitor class' can operate on them
    virtual void accept(Visitor &visitor) = 0;
    
    
};


#endif //CS363_SPRING2019_ASSIGNMENT4_BINARY_EXPR_NODE_H
