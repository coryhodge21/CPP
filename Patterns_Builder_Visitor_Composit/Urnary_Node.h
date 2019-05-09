/*
 * Created by Cory Hodge on 2019-04-04.
 *
 * Urnary_Expr_Node.h
 *
 * Base Class for Uranry operators of algebraic expressions
 *
 * Inherits interface method '  int eval() ' that is expected
 *  to evaluate the composite expression tree relative to
 *  the calling nodes position.
 *
 */// -*- C++ -*-
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

#ifndef CS363_SPRING2019_ASSIGNMENT4_URNARY_EXPR_NODE_H
#define CS363_SPRING2019_ASSIGNMENT4_URNARY_EXPR_NODE_H

#include "Node.h"

class Urnary_Expr_Node : public Node {

protected:
    
    // pointer to only child of urnary operations
    Node *ptr_;

public:
    
    // Constructor
    Urnary_Expr_Node(void);
    
    // Virtual Destructor
    virtual ~Urnary_Expr_Node(void);
    
    // all subclass' must interface accept method so
    //  visitor class' can operate on them
    virtual void accept(Visitor &visitor) = 0;
    
};


#endif //CS363_SPRING2019_ASSIGNMENT4_URNARY_EXPR_NODE_H
