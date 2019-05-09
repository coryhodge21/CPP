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
#ifndef CS363_SPRING2019_ASSIGNMENT4_CALCULATOR_H
#define CS363_SPRING2019_ASSIGNMENT4_CALCULATOR_H

#include <iostream>
#include <string>   // for std:: string as input
#include "Node.h"
#include "Builder.h"
#include "Expression_Visitor.h"

class Calculator {

private:
    
    /// pointer to root of composite tree
    Node *root_;
    
    /// builder for constructing composite tree and its nodes
    Builder *builder_;
    
    /// visitor for evaluating the composite tree
    Visitor *visitor_;


public:
    
    // Constructor
    Calculator(void);
    
    // Destuctor
    ~Calculator(void);
    
    /*
     * Take Algebraic expression from stdin
     *  create composite tree of nodes
     *  assign root of tree to this->root_
     */
    void enter_expression(std::string expression);
    
    /*
     * Use Visitor pattern to traverse composite
     *  tree post order (L,R,this)
     *  display result_ of traversal to stdout
     */
    void calculate_expression(void);
    
};


#endif //CS363_SPRING2019_ASSIGNMENT4_CALCULATOR_H
