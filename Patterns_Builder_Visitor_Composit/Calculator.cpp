
/*
 * Created by Cory Hodge on 2019-04-05.
 *
 *  Calculator.cpp
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
#include "Calculator.h"


/**
 * Constructor
 *
 */
Calculator::Calculator() :
        root_(nullptr),
        builder_(nullptr),
        visitor_(nullptr) {
    
}

/**
 * Destructor
 */
Calculator::~Calculator() {
    
    if (root_)
        delete root_;
    if (builder_)
        delete builder_;
    if (visitor_)
        delete visitor_;
}

/**
 * enter_expression
 *
 *  use builder to construct composite tree from passed algebraic expression
 *
 *  assign calculators Node * to the root of this tree
 *
 * @param expression : expecting algebraic expression
 */
void Calculator::enter_expression(std::string expression) {
    
    builder_ = new Builder();
    
    root_ = builder_->build_expression_tree(expression);
}


/**
 * calculate_expression
 *
 *  use evaluation visitor to traverse infix algebraic expression
 *
 *      accumulating state in result_;
 *
 *      display result via evaluation visitor
 *
 *  in postorder ( i.e. Lptr, Rptr, This )
 */
void Calculator::calculate_expression(void) {
    
    visitor_ = new Expression_Visitor();
    
    root_->accept(*visitor_);
}

