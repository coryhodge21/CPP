/*
 * Created by Cory Hodge on 2019-04-04.
 *
 * Expr_Node_Visitor.h
 *
 * Base class for all visitor operations to be
 *  performed on Concrete_Expr_Node elements
 *
 *  !!! Must update this interface to add
 *       any new visiting operations
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

#ifndef CS363_SPRING2019_ASSIGNMENT4_EXPR_NODE_VISITOR_H
#define CS363_SPRING2019_ASSIGNMENT4_EXPR_NODE_VISITOR_H

class Eval_Node;

class Num_Node;

class Add_Node;

class Sub_Node;

class Mul_Node;

class Div_Node;

class Mod_Node;

class Par_L_Node;

class Par_R_Node;

class Var_Node;

class Visitor {

public:
    
    // Pure virtual interface
    virtual ~Visitor() {}
    /* Methods for each Visitor sub class to implement
     * Each Visit Method contains logic for visiting concrete nodes
    */
    
    // Number Nodes
    virtual void visit(Num_Node &node) = 0;
    
    // Addition Nodes
    virtual void visit(Add_Node &node) = 0;
    
    // Subtraction Nodes
    virtual void visit(Sub_Node &node) = 0;
    
    // Multiplication Nodes
    virtual void visit(Mul_Node &node) = 0;
    
    // Division Nodes
    virtual void visit(Div_Node &node) = 0;
    
    // Modulus Nodes
    virtual void visit(Mod_Node &node) = 0;
    
    // Parenthesis Left Nodes
    virtual void visit(Par_L_Node &node) = 0;
    
    // Parenthesis Right Nodes
    virtual void visit(Par_R_Node &node) = 0;
    
    // Variable Node
    virtual void visit(Var_Node &node) = 0;
    
    // Special Function Node
    virtual void visit(Eval_Node &node) = 0;
};

#endif //CS363_SPRING2019_ASSIGNMENT4_EXPR_NODE_VISITOR_H
