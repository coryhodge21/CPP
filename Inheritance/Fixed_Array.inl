// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

/**
 * Assignment operator
 *
 * @param[in]      rhs        Right-hand side of operator.
 */
template<typename T, size_t N>
const Fixed_Array<T, N> &Fixed_Array<T, N>::
operator=(const Fixed_Array<T, N> &rhs) {
    
    // check self assignment
    if (this != &rhs) {
        
        // need to match fixed max_size_
        if (this->max_size() != rhs.max_size()) {
            
            std::cout << "Error, cannot assign Fixed array of diffent max_size_ \n";
            throw "Error, cannot assign Fixed array of diffent max_size_ \n";
        }
        
        // max_size_ matches, must preserve data_
        for (std::size_t i = 0; i < rhs.size(); i++) {
            *this->data_++ = rhs.get(i);
        }
        
        // set members
        this->cur_size_ = rhs.cur_size_;
        
    }
    
    return this;
    
}

/**
 * Assignment operator
 *
 * @param[in]      rhs        Right-hand side of operator.
 */
template<typename T, size_t N>
template<T, size_t M>
const Fixed_Array<T, N> &Fixed_Array<T, N>::
operator=(const Fixed_Array<T, M> &rhs) {
    
    // check self assignment
    if (this != &rhs) {
        
        // if M != N, re allocate
        if (M != N) {
            
            // destroy old Fixed Array
            delete this->data_;
            
            // re allocate memory for new Fixed Array
            this->data_ = new T[M];
            this->max_size_ = M;
        }
        
        // max_size_ matches, must preserve data_
        for (std::size_t i = 0; i < rhs.size(); i++) {
            *this->data_++ = rhs.get(i);
        }
        
        // set members
        this->cur_size_ = rhs.cur_size_;
        
    }
    
    return this;
}