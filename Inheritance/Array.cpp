// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

/// Default Constructor
template <typename T>
Array<T>:: Array() :
        ArrayBase<T>(){
    
}

/// Initilizing Constructor
template <typename T>
Array<T>::Array( size_t length) :
        ArrayBase<T>(length){

}

/// Initilizing Constructor
template <typename T>
Array<T>::Array(size_t length, T fill) :
        ArrayBase<T>(length, fill){

}

/// Copy Constructor
template <typename T>
Array<T>::Array(const Array*array) :
        ArrayBase<T>(array){
    
}

/// Reference Copy Constructor
template <typename T>
Array<T>::Array(const Array & array) :
        ArrayBase<T>(array){
    
}

/// Destructor
template <typename T>
Array<T>::~Array(){

}

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
 template <typename T>
void Array<T>::resize(size_t new_size) {

    // if new size != current allocation, rebuild array
    if (new_size != this->max_size()) {

        // make copy of existing data on stack
        T temp[new_size];
        for (std::size_t i = 0; i < this->size(); i++) {
        temp[i] = this->data_[i];
    }

    // re allocate memory
    delete[] this->data_;
    this->data_ = new T[new_size];

    // re assign elements: new size < cur_zie, append and truncate up to new size
    if (new_size < this->size()) {
        for (std::size_t i = 0; i < new_size; i++) {
            this->data_[i] = temp[i];
        }

        // update cur size member
        this->cur_size_ = new_size;
    
    } else { // new size >= current size

        // re assign elements: cur size remains same, fill with garbage
        for (std::size_t i = 0; i < this->size(); i++) {
            this->data_[i] = temp[i];
        }

        // update max size data member, fills with garbage
        this->max_size_ = new_size;
    }
    
    }// else new size == max size_, do nothing
}