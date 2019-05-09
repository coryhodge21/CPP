
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.


/// Default constructor.
template<typename T>
Stack<T>::Stack(void) :
        data_(ArrayBase<T>()),
        top_(-1),
        is_empty_(true) {
    
}

/// Copy constructor.
template<typename T>
Stack<T>::Stack(const Stack &stack) :
        data_(ArrayBase<T>(&stack)),
        top_(stack.top_),
        is_empty_(stack.is_empty_) {
    
}

/// Destructor.
template<typename T>
Stack<T>::~Stack(void) {

    if(this->data_ != NULL)
        delete data_;
}

/**
 * Assignment operator
 *
 * @param[in]      rhs           Right-hand side of operator
 * @return         Reference to self
 */
template<typename T>
const Stack<T> & Stack<T>::operator=(const Stack<T> &rhs) {
    
    // ensure no self assignment
    if ( this != rhs ) {
    
        // copy members
        this->data_ = rhs.data_;
    
        this->data_->max_size_ = rhs.max_size();
        this->data_->cur_size_ = rhs.size();
    
        this->is_empty_ = rhs.is_empty_;
        this->top_ = rhs.top_;
    }
    
    return this;
    
}

/**
 * Push a new \a element onto the stack. The element is inserted
 * before all the other elements in the list.
 *
 * @param[in]      element       Element to add to the list
 */
template<typename T>
void Stack<T>::push(T element) {
    
    // check that current size < max size alloted
    if ((this->top_ + 1) < this->max_size_) {
        
        // add element to top of stack
        this->data_[top_ + 1] = element;
        
        // Update Class Members
        top_++;
        is_empty_ = false;
        data_->cur_size_++;
    }
}

/**
 * Remove the top-most element from the stack.
 *
 * @exception      empty_exception    The stack is empty.
 */
template<typename T>
T &Stack<T>::
pop(void) {
    
    //check if stack is empty
    if (this->is_empty()) {
        throw empty_exception("Stack.pop()=STACK EMPTY");
    }
    
    //decrement cur_size_, top_
    this->data_->cur_size_--;
    this->top_--;
    
    //return the value popped from stack
    return this->data_[(this->top_ + 1)];
}








