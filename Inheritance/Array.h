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

#ifndef TEMPLATE_BASEARRAY_ARRAY_H
#define TEMPLATE_BASEARRAY_ARRAY_H

#include "ArrayBase.h"
#include <stdexcept>

template <typename T>
class Array : public ArrayBase<T> {

public:
    
    /// Default Constructor
    Array() ;
    
    /// Initilizing Constructor
    Array( size_t length) ;
    
    /// Initilizing Constructor
    Array(size_t length, T fill) ;
    
    /// Copy Constructor
    Array(const Array*array) ;
    
    /// Reference Copy Constructor
    Array(const Array & array);
    
    /// Destructor
    virtual ~Array();
    
    /// Methods
    /**
     * Set a new size for the array. If \a new_size is less than the current
     * size, then the array is truncated. If \a new_size if greater then the
     * current size, then the array is made larger and the new elements are
     * not initialized to anything. If \a new_size is the same as the current
     * size, then nothing happens.
     *
     * The array's original contents are preserved regardless of whether the
     * array's size is either increased or decreased.
     *
     * @param[in]       new_size              New size of the array
     */
    void resize(size_t new_size);
};

#include "Array.cpp"

#endif //TEMPLATE_BASEARRAY_ARRAY_H
