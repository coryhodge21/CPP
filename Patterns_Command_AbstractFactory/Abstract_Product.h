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
/**
 * AbsFactory + Command Pattern
 * Abstract Product
 *  Interfaces all the products that
 *  will be created by factories returning
 *  this 'AbstractProduct' type. All methods
 *  of products must be interfaced here, pure
 *  virtual class;
 *
 * Abstract Product represents
 *  Abstract Command to be performed on
 *  Reciever(Calculator) Stack<CMD*>
 */

#ifndef CMD_ABSFACTORY_STACKCALC_ABSTRACT_PRODUCT_H
#define CMD_ABSFACTORY_STACKCALC_ABSTRACT_PRODUCT_H


class Abstract_Product {
protected:
    
    Abstract_Product(void) = default;

public:
    
    /**
     * Pure Virtual Interface for
     * Child Products of this Abstract Class
     * this is required for runtime polymorphism
     */
    
    virtual ~Abstract_Product(void) = default;
    
    virtual void execute() = 0;
    
    virtual int precedence(void) = 0;
    
    virtual char symbol(void) = 0;
};

#endif //CMD_ABSFACTORY_STACKCALC_ABSTRACT_PRODUCT_H
