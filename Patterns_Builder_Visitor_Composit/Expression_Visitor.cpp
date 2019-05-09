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
#include "Expression_Visitor.h"


// Constructor
Expression_Visitor::Expression_Visitor(void) :
        result_(0.0),
        calcQ_(new Queue<float>) {
    
}

// Destructor
Expression_Visitor::~ Expression_Visitor(void) {
    if (calcQ_)
        delete calcQ_;
}

/**
 * Visitor evaluate expression
 *
 * traverse tree post order
 *  Lptr , Rptr, This
 *
 * @param node : CC reference used to determin operation
 */



/* Impliment all Interface Methods
 * Each Visit Method contains logic for visiting concrete nodes
*/

// Number Nodes
void Expression_Visitor::visit(Num_Node &node) {
    
    calcQ_->enqueue(node.get_value_());
}


// Variable Node
void Expression_Visitor::visit(Var_Node &node) {
    
    //calcQ_->enqueue(node.get_value());
}


// Addition Nodes
void Expression_Visitor::visit(Add_Node &node) {
    
    node.getLptr_()->accept(*this);
    node.getRptr_()->accept(*this);
    
    this->result_ = (calcQ_->dequeue() + calcQ_->dequeue());
    
}

// Subtraction Nodes
void Expression_Visitor::visit(Sub_Node &node) {
    
    node.getLptr_()->accept(*this);
    node.getRptr_()->accept(*this);
    
    this->result_ = (calcQ_->dequeue() - calcQ_->dequeue());
}

// Multiplication Nodes
void Expression_Visitor::visit(Mul_Node &node) {
    
    node.getLptr_()->accept(*this);
    node.getRptr_()->accept(*this);
    
    this->result_ = (calcQ_->dequeue() * calcQ_->dequeue());
}

// Division Nodes
void Expression_Visitor::visit(Div_Node &node) {
    
    node.getLptr_()->accept(*this);
    node.getRptr_()->accept(*this);
    
    this->result_ = (calcQ_->dequeue() / calcQ_->dequeue());
}

// Modulus Nodes
void Expression_Visitor::visit(Mod_Node &node) {
    
    node.getLptr_()->accept(*this);
    node.getRptr_()->accept(*this);
    
    // modulo equation
    float f1 = calcQ_->dequeue();
    float f2 = calcQ_->dequeue();
    this->result_ = (f1 - (f1 / f2 * f2));
}

// Parenthesis Left Nodes
void Expression_Visitor::visit(Par_L_Node &node) {

}

// Parenthesis Right Nodes
void Expression_Visitor::visit(Par_R_Node &node) {

}

/** Special Function Node
  *  begin evaluation of tree
  *
  *  Eval_Node is a special node that points to root of tree,
  *    used for starting recursive evaluate
 */
void Expression_Visitor::visit(Eval_Node &setupNode) {
    
    // call recursive evaluate method
    // assign result of expression to this result
    setupNode.getLptr_()->accept(*this);
    
    
    // display result
    std::cout << "Result =\t" << this->result_ << ";\n" << std::endl;
}
