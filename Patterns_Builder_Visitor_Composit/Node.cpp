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
#include "Node.h"

/**
 *  Constructor
 */
Node::Node(void) :
        symbol_(' '),
        precedence_(0),
        value_(0.0),
        Lptr_(nullptr),
        Rptr_(nullptr) {
}

/**
*  Initializing Constructor
*/
Node::Node(char symbol, int precedence) :
        symbol_(symbol),
        precedence_(precedence),
        value_(0.0),
        Lptr_(nullptr),
        Rptr_(nullptr) {
}

/**
 * Destructor
*/
Node::~Node(void) {
}


/**
* Setters and getters
*/

char Node::getSymbol_() const {
    return symbol_;
}


void Node::setSymbol_(char symbol_) {
    Node::symbol_ = symbol_;
}


int Node::getPrecedence_() const {
    return precedence_;
}


void Node::setPrecedence_(int precedence_) {
    Node::precedence_ = precedence_;
}

Node *Node::getLptr_() const {
    return Lptr_;
}

void Node::setLptr_(Node *Lptr_) {
    Node::Lptr_ = Lptr_;
}

Node *Node::getRptr_() const {
    return Rptr_;
}

void Node::setRptr_(Node *Rptr_) {
    Node::Rptr_ = Rptr_;
}

void Node::setValue_(float value) {
    Node::value_ = value;
}




