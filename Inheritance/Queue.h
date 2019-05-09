// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

#ifndef _TEMPLATE_QUEUE_H
#define _TEMPLATE_QUEUE_H

#include "ArrayBase.h"

// COMMENT You should use aggregation instead of inheritance since logically
// a queue is not an array.

// ADDRESSED: Queue now owns an array as opposed to being a child of one

template<typename T>
class Queue {

private:
    
    ArrayBase<T> * data_;
    
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
};

// Include Source as Queue is template type
#include "Queue.cpp"

#endif //TEMPLATE_QUEUE_H
