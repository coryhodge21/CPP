/*
 * Created by Cory Hodge on 2019-04-05.
 *
 * Expression_Visitor.h
 *
 * Sub Class of Interface Visitor
 *
 * holds all operations for composite tree of algebraic expression nodes
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
#ifndef CS363_SPRING2019_ASSIGNMENT4_EXPRESSION_VISITOR_H
#define CS363_SPRING2019_ASSIGNMENT4_EXPRESSION_VISITOR_H

#include "Queue.h"

#include "Visitor.h"

#include "Num_Node.h"
#include "Sub_Node.h"
#include "Add_Node.h"
#include "Mul_Node.h"
#include "Div_Node.h"
#include "Mod_Node.h"
#include "Parenthesis_Nodes.h"
#include "Var_Node.h"
#include "Special_Fx_Nodes.h"

class Expression_Visitor : public Visitor {

private:
    
    // visitor will accumulate state
    float result_;
    
    // using q bc only two values at a time
    //  no need to add extra Stack Class for this
    Queue<float> *calcQ_;

public:
    
    // Constructor
    Expression_Visitor(void);
    
    // Destructor
    virtual ~ Expression_Visitor(void);
    
    /* Impliment all Interface Methods
     * Each Visit Method contains logic for visiting concrete nodes
    */
    
    
    // Number Nodes
    void visit(Num_Node &node);
    
    // Addition Nodes
    void visit(Add_Node &node);
    
    // Subtraction Nodes
    void visit(Sub_Node &node);
    
    // Multiplication Nodes
    void visit(Mul_Node &node);
    
    // Division Nodes
    void visit(Div_Node &node);
    
    // Modulus Nodes
    void visit(Mod_Node &node);
    
    // Parenthesis Left Nodes
    void visit(Par_L_Node &node);
    
    // Parenthesis Right Nodes
    void visit(Par_R_Node &node);
    
    // Variable Node
    void visit(Var_Node &node);
    
    // Special Function Node
    void visit(Eval_Node &node);
};

#endif //CS363_SPRING2019_ASSIGNMENT4_EXPRESSION_VISITOR_H
