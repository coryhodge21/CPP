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
#ifndef _TEMPLATE_QUEUE_H
#define _TEMPLATE_QUEUE_H

#include "ArrayBase.h"


template<typename T>
class Queue : public ArrayBase<T> {
private:
    
    bool is_empty_;

public:
    /// Constructors
    // Default
    Queue(void);
    
    /// Copy Constructor
    Queue(const Queue &q);
    
    /// Initilizing Constructor
    Queue(size_t len);
    
    // Full Init Constructor
    Queue(size_t len, T *fill);
    
    /// Destructor
    ~Queue();
    
    /// Operators
    const Queue &operator=(const Queue &rhs);
    
    /// Methods
    
    /**
     * add element to end of Array A(+)
     *
     * @param element to append to end of array
     */
    void enqueue(T element);
    
    /**
     * remove element from front of array A(0)
     *
     * @return data from front of array
     */
    T dequeue(void);
    
    /**
     * @return status of queue
     */
    bool is_empty();
    
    /**
     *
     * @return
     */
    size_t size();
    
    /**
     * Clear the array elements (truncate size = 0, assume garbage)
     */
    void clear();
    
    /**
     * peek at next element in queue
     */
    T next(void);
};

// Include Source as Queue is template type
#include "Queue.cpp"

#endif //TEMPLATE_QUEUE_H
