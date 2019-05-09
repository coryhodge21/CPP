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
/**
 * File for both parenthesis
 */

#ifndef CS363_SPRING2019_ASSIGNMENT4_PARENTHESIS_NODES_H
#define CS363_SPRING2019_ASSIGNMENT4_PARENTHESIS_NODES_H


#include "Node.h"

/**
 *      Left Open Parenthesis (
 */
class Par_L_Node : public Node {

private:
    
    // Constructor
    Par_L_Node(void);

public:
    
    // initializing constructor
    Par_L_Node(char symbol, int precedence);
    
    // Destructor
    ~ Par_L_Node(void);
    
    // all subclass' must interface accept method so
    //  visitor class' can operate on them
    void accept(Visitor &visitor);
};

/**
 *      Right Close Parenthesis )
 */
class Par_R_Node : public Node {

private:
    
    // Constructor
    Par_R_Node(void);

public:
    
    // initializing constructor
    Par_R_Node(char symbol, int precedence);
    
    // Destructor
    ~ Par_R_Node(void);
    
    // all subclass' must interface accept method so
    //  visitor class' can operate on them
    void accept(Visitor &visitor);
};

#endif //CS363_SPRING2019_ASSIGNMENT4_PARENTHESIS_NODES_H
