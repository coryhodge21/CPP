/*
 * Created by Cory Hodge on 2019-04-04.
 *
 * Builder.h
 *
 * Base Class for building expressions
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
#ifndef CS363_SPRING2019_ASSIGNMENT4_EXPR_BUILDER_H
#define CS363_SPRING2019_ASSIGNMENT4_EXPR_BUILDER_H

#include <iostream>
#include <string>
#include <map>

#include "Queue.h"

#include "Node.h"
#include "Num_Node.h"
#include "Add_Node.h"
#include "Sub_Node.h"
#include "Mul_Node.h"
#include "Div_Node.h"
#include "Mod_Node.h"
#include "Parenthesis_Nodes.h"
#include "Var_Node.h"
#include "Special_Fx_Nodes.h"



/**
 *  Precedence Table for Builder
 */

#define VAR_NODE_PRECEDENCE -1

#define NUMBER_NODE_PRECEDENCE 0

#define ADD_NODE_PRECEDENCE 1
#define SUB_NODE_PRECEDENCE 1

#define MUL_NODE_PRECEDENCE 2
#define DIV_NODE_PRECEDENCE 2
#define MOD_NODE_PRECEDENCE 2

#define L_PAR_NODE_PRECEDENCE 3

#define R_PAR_NODE_PRECEDENCE 3

#define SPF_PRECEDENCE 9

class Builder {

private:
    
    // pointer to tree as it get built
    Node *root_;
    
    // Two Queue's for holding newly created
    //  nodes until they are ready for tree
    Queue<Node *> *numQ_;
    
    Queue<Node *> *opQ_;
    
    Queue<Node *> *tree_;
    
    // map for handling variables
    std::map<char, float> map_;

public:
    
    //Constructor
    Builder(void);
    
    //Destructor
    virtual ~ Builder(void);
    
    /**
     * Build expression tree from the user inputted string::expression
     *  and return Node * pointing too root of tree
     *
     * @return Node* : pointer to root of composite tree
     * @param expression : string algebraic expression
     */
    Node *build_expression_tree(std::string expression);
    
    /**
     * cycle input
     * create nodes for each element
     *  storing variables in map
     * append operators and numbers in separate q's
     *  expression remains as standard infix'ed
    */
    void construct_node_Qs(std::string expression);
    
    
    /**
     * get vars from user in alphabetic order
     */
    void get_variable_values(void);
    
    /**
     * Return root_ of tree to caller
     *
     *
     */
    Node *get_root();
    
    /**
     * Assemble Q's into Composite Tree
     *
     * @return Node* : pointer to root of composite tree
     */
    Node *construct_tree();
    
    
    
    /**
     * build each type of Expr_Node
     */
    
    /// Number
    Node *build_number_node(char symbol);
    
    /// Add
    Node *build_add_node(char symbol);
    
    ///Subtract
    Node *build_sub_node(char symbol);
    
    /// Divide
    Node *build_div_node(char symbol);
    
    /// Multiply
    Node *build_mul_node(char symbol);
    
    /// Modulus
    Node *build_mod_node(char symbol);
    
    /// Left parenthesis
    Node *build_L_par_node(char symbol);
    
    /// Right Parenthesis
    Node *build_R_par_node(char symbol);
    
    /// Variable
    Node *build_var_node(char symbol);
    
    /// Special Functions
    Node *build_eval_node(char symbol);
    
};

#endif //CS363_SPRING2019_ASSIGNMENT4_EXPR_BUILDER_H


