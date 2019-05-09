// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

/**
 * Get the top-most element on the stack. If there are no element
 * on the stack, then the stack_is_empty exception is thrown.
 *
 * @return         Element on top of the stack.
 * @exception      empty_exception    The stack is empty
 *
 * ! removed const
 */

template <typename T>
inline
T Stack<T>::top(void) {
    
    //check if stack is empty
    if (this->is_empty()) {
        std::cout << "\n!!! Stack<T>->data_[] EMPTY, cannot .pop()\n";
        throw empty_exception("Stack.pop()=STACK EMPTY");
    }
    
    //return element
    return this->data_[top_];
}

/**
 * Test if the stack is empty
 *
 * @retval         true          The stack is empty
 * @retval         false         The stack is not empty
 *
 * ! removed const: allows dynamic checking
 */

template <typename T>
inline
bool Stack<T>::is_empty(void) {
    // default
    is_empty_ = true;
    
    // update is_empty
    if (top_ > -1)
        is_empty_ = false;
    
    return is_empty_;
}


/**
 * Number of element on the stack.
 *
 * @return         Size of the stack.
 */

template <typename T>
inline
size_t Stack<T>::size(void) const {
    // + 1 for 0 based indexing
    return top_ + 1;
}


/// Remove all elements from the stack.
template <typename T>
inline
void Stack<T>::clear(void) {
    
    // empty stack
    while (this->top_ > STACK_EMPTY)
        this->pop();
}
