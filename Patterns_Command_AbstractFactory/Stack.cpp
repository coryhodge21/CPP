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

/// Default constructor.
template<typename T>
Stack<T>:: Stack(void) :
    ArrayBase<T>(),
    top_(-1),
    is_empty_(true) {
}

/// Copy constructor.
template<typename T>
Stack<T>:: Stack(const Stack &stack) :
        ArrayBase<T>(&stack),
        top_(stack.top_),
        is_empty_(stack.is_empty_) {
}

/// Destructor
template<typename T>
Stack<T>:: ~Stack() {
}


///Assignment operator
template<typename T>
const Stack<T> & Stack<T>::operator=(const Stack &rhs) {
    
    // virtual ArrayBase operator =
    this->is_empty_ = rhs.is_empty_;
    this->top_ = rhs.top_;
}

/// Push
template<typename T>
void Stack<T>::push(T element) {
    
    // check that current size < max size alloted
    if ((this->top_ + 1) < this->max_size_) {
        
        // add element to top of stack
        this->data_[top_ + 1] = element;
        
        // Update Class Members
        top_++;
        is_empty_ = false;
        // inherited
        this->cur_size_++;
    }
}

/// Pop
template<typename T>
T & Stack<T>::pop(void) {
    
    //check if stack is empty
    if (this->is_empty()) {
        throw empty_exception("Stack.pop()=STACK EMPTY");
    }
    
    //decrement cur_size_, top_
    this->cur_size_--;
    this->top_--;
    
    //return the value popped from stack
    return this->data_[(this->top_ + 1)];
}

/// Top
template<typename T>

T Stack<T>:: top(void) {
    
    //check if stack is empty
    if (this->is_empty()) {
        std::cout << "\n!!! Stack<T>->data_[] EMPTY, cannot .pop()\n";
        throw empty_exception("Stack.pop()=STACK EMPTY");
    }
    
    //return element
    return this->data_[top_];
}

/// is_empty
template<typename T>

bool Stack<T>:: is_empty(void) {
    // default
    is_empty_ = true;
    
    // update is_empty
    if (top_ > -1)
        is_empty_ = false;
    
    return is_empty_;
}

