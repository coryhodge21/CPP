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

/// size
template<typename T>
size_t Stack<T>:: size(void) const {
    // + 1 for 0 based indexing
    return top_ + 1;
}


/// Clear
template<typename T>
void Stack<T>:: clear(void) {
    
    // empty stack
    while (this->top_ > STACK_EMPTY)
        this->pop();
}
