/*
 * Created by Cory Hodge on 2019-04-04.
 *
 * Node.h
 *
 *  Base class for all algebraic expression type nodes
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
#ifndef CS363_SPRING2019_ASSIGNMENT4_EXPR_NODE_H
#define CS363_SPRING2019_ASSIGNMENT4_EXPR_NODE_H

#include "Visitor.h"
#include <iostream>

class Node {

protected:
    
    /// symbol representation
    char symbol_;
    
    /// precedence
    int precedence_;
    
    /// value of node
    float value_;
    
    /// Pointers too branches of node
    Node *Lptr_;
    
    Node *Rptr_;

public:
    
    // Default Constructor
    Node(void);
    
    // Initializing Constructor
    Node(char symbol, int precedence);
    
    // Virtual Destructor
    virtual ~Node(void);
    
    // all subclass' must interface accept method so
    //  visitor class' can operate on them
    virtual void accept(Visitor &visitor) = 0;
    
    // optional methods to overload in
    //  subclasses
    virtual char getSymbol_() const;
    
    virtual void setSymbol_(char symbol_);
    
    virtual int getPrecedence_() const;
    
    virtual void setPrecedence_(int precedence_);
    
    virtual void setValue_(float value);
    
    virtual Node *getLptr_() const;
    
    virtual void setLptr_(Node *Lptr_);
    
    virtual Node *getRptr_() const;
    
    virtual void setRptr_(Node *Rptr_);
    
};

#endif //CS363_SPRING2019_ASSIGNMENT4_EXPR_NODE_H
