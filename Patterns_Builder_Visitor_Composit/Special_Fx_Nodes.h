//
// Created by Cory Hodge on 2019-04-06.
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
 *
 * Include all special function nodes here until file size grows
 *  to un-maintainable state
 *
 * Special function nodes are those with commands difficult or
 *  outside the scope of normal algebraic expressions.
 *
 * Or, nodes designed to facilitate the insertion of special
 *  method calls during visitor evaluation
 */

#ifndef CS363_SPRING2019_ASSIGNMENT4_SPECIAL_FX_NODES_H
#define CS363_SPRING2019_ASSIGNMENT4_SPECIAL_FX_NODES_H

#include "Node.h"

class Special_Fx_Nodes : public Node {


public:
    
    // Default Constructor
    Special_Fx_Nodes(void);
    
    
    //Init Constructor
    Special_Fx_Nodes(char symbol, int precedence);
    
    // virtual destructor
    virtual ~Special_Fx_Nodes(void);
    
    // all subclass' must interface accept method so
    //  visitor class' can operate on them
    virtual void accept(Visitor &visitor) = 0;
};


/**
 * Evaluate_Node
 *
 * special node appended to top of composite tree to
 *  facilitate the evaluation process
 */
class Eval_Node : public Special_Fx_Nodes {

public:
    
    /// Constructor
    Eval_Node();
    
    /// Init Constructor
    Eval_Node(char symbol, int precedence);
    
    /// Destructor
    ~Eval_Node();
    
    /// Implement accept method
    void accept(Visitor &visitor);
    
};


#endif //CS363_SPRING2019_ASSIGNMENT4_SPECIAL_FX_NODES_H
