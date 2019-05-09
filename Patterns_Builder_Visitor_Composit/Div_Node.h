//
// Created by Cory Hodge on 2019-04-05.
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
#ifndef CS363_SPRING2019_ASSIGNMENT4_DIV_NODE_H
#define CS363_SPRING2019_ASSIGNMENT4_DIV_NODE_H


#include "Binary_Node.h"

class Div_Node : public Binary_Node {

private:
    
    // restrict constructor too initilizing only
    Div_Node();

public:
    
    /// Constructor
    Div_Node(char symbol, int precedence);
    
    /// Destructor
    ~Div_Node();
    
    /// Implement accept method
    void accept(Visitor &visitor);
};

#endif //CS363_SPRING2019_ASSIGNMENT4_DIV_NODE_H
