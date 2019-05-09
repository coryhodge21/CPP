// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

/// Constructors
// Default
template<typename T>
Queue<T>::Queue(void) :
        data_(ArrayBase<T>()),
        is_empty_(true) {
}

/// Copy Constructor
template<typename T>
Queue<T>::Queue(const Queue &q) :
        data_(ArrayBase<T>(q)),
        is_empty_(q.is_empty()) {
    
}

/// Initilizing Constructor
template<typename T>
Queue<T>::Queue(size_t len) :
        data_(ArrayBase<T>(len)),
        is_empty_(true) {
    
}

// Full Init Constructor
template<typename T>
Queue<T>::Queue(size_t len, T *fill) :
        data_(ArrayBase<T>(len, fill)),
        is_empty_(false) {
    
}

/// Destructor
template<typename T>
Queue<T>::~Queue() {

}

/// Operators
template<typename T>
const Queue<T> &Queue<T>::operator=(const Queue &rhs) {
  // COMMENT You need to implement this method.
  
    // ADDRESSED: forgot to implement this one
    
    // ensure no self assignment
    if ( this != rhs ){
        
        // copy members
        this->data_ = rhs.data_;
        
        this->data_->max_size_ = rhs.max_size();
        this->data_->cur_size_ = rhs.size();
        this->is_empty_ = rhs.is_empty();
        
    }
}

/// Methods

/**
 * add element to end of Array A(+)
 *
 * @param element to append to end of array
 */
template<typename T>
void Queue<T>::enqueue(T element) {

  // COMMENT The queue should grow if it out of space.

  // COMMENT This approach can work, but its design is very expensive. You
  // should find a better design that tries to use as much space as possible
  // while minimizing the amount of copying that must occur.
  
    // ADDRESSED: Queue now grows when max size reached
    // ADDRESSED: Design does not use methods and moves data manually in one shot
    
    // if max size reached, increase size
    if( this->data_->size() == this->data_->max_size())
        this->data_->max_size_++;
    
    
    // shift data to make room for next element
    for(size_t i = this->data_->size() ; i > 0 ; i--) {
        
        this->data_[i] = this->data_[i - 1];
    }
    
    // append new element to back of queue (FIFO)
    this->data_[0] = element;
    
    // inc size to match new length
    this->data_->cur_size_++;
    
    // ensure not empty
    this->is_empty_ = false;
    
}

/**
 * remove element from front of array A(0)
 *
 * @return data from front of array
 */
template<typename T>
T Queue<T>::dequeue(void) {
    
    // ensure Queue not empty
    if ((this->is_empty())) {
        // display error prompt
        std::cout << "\n!!!Queue is EMPTY, cannot dequeue NULL\n";
    }
    
    // make a copy of the top (last) element T
    T temp = this->get(this->size() - 1);
    
    // decrement size
    this->data_->cur_size_--;
    
    // update status
    this->is_empty();
    
    // return the top element value from the array
    return temp;
    
}

/**
 * @return status of queue
 */
template<typename T>
bool Queue<T>::is_empty() {
    
    // default to ture
    is_empty_ = true;
    
    // check array
    if (this->data_->size() > 0) {
        is_empty_ = false;
    }
    
    return is_empty_;
}

/**
 *
 * @return
 */
template<typename T>
size_t Queue<T>::size() {
    return this->data_->cur_size_;
}

/**
 * Clear the array elements (truncate size = 0, assume garbage)
 */
template<typename T>
void Queue<T>::clear() {
    this->data_->cur_size_ = 0;
    this->is_empty_ = true;
}



