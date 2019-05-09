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

/** Constructors / Destructor */

/// Default constructor.
template<typename T>
ArrayBase<T>:: ArrayBase() :
        data_(new T[DEFAULT_ARRAY_LENGTH]),
        cur_size_(EMPTY),
        max_size_(DEFAULT_ARRAY_LENGTH) {
}

/**
 * Initializing constructor.
 *
 * @param[in]      length        Initial size
 */
template<typename T>
ArrayBase<T>:: ArrayBase(size_t length) :
        data_(new T[length]),
        cur_size_(EMPTY),
        max_size_(length) {
}

/**
 * Initializing constructor.
 *
 * @param[in]      length        Initial size
 * @param[in]      fill          Initial value for each element
 */
template<typename T>
ArrayBase<T>:: ArrayBase(size_t length, T fill) :
        data_(new T[length]),
        cur_size_(length),
        max_size_(length) {
    
    // Fill the array with passed fill value
    for (int i = 0; i < length; i++) {
        data_[i] = fill;
    }
}

/**
 * Copy constructor * Pointer
 *
 * @param[in]     arr         The source array.
 */
template<typename T>
ArrayBase<T>:: ArrayBase(const ArrayBase *array) :
        data_(new T[array->max_size_]),
        cur_size_(array->cur_size_),
        max_size_(array->max_size_) {
    
    // copy elements from array
    for (int i = 0; i < cur_size_; i++)
        this->data_[i] = array->data_[i];
}

/**
 * Copy constructor & Reference
 *
 * @param[in]     arr         The source array.
 */
template<typename T>
ArrayBase<T>:: ArrayBase(const ArrayBase &array) :
        data_(new T[array.max_size_]),
        cur_size_(array.cur_size_),
        max_size_(array.max_size_) {
    
    // copy elements from array
    for (int i = 0; i < cur_size_; i++)
        this->data_[i] = array.data_[i];
}

/// Destructor.

template<typename T>
ArrayBase<T>:: ~ArrayBase(void) {
    
    if (data_ == nullptr) {
        std::cout << "data_ is NULL\n";
    } else {
        delete[] data_;
        data_ = nullptr;
    }
}

/** Operators */

/**
 * Assignment operation
 *
 * @param[in]       rhs      Right-hand side of equal sign
 * @return          Reference to self
 */

template<typename T>
const ArrayBase<T> & ArrayBase<T>::operator=(const ArrayBase<T> &rhs) {
    
    //check rhs does not point to same address
    if (this != &rhs) {
        
        // not same address, so delete old data
        delete[] this->data_;
        
        // Update ArrayBase members
        this->cur_size_ = rhs.size();
        this->max_size_ = rhs.max_size();
        
        // allocate space for new array
        this->data_ = new T[rhs.max_size()];
        
        //for every element in rhs array, copy value to data
        for (size_t i = 0; i < rhs.max_size_; i++) {
            this->data_[i] = rhs.data_[i];
        }
    }
    
    // return ArrayBase
    return *this;
}

/**
 * Test the array for equality.
 *
 * @param[in]       rhs                  Right hand side of equal to sign
 * @retval          true                 Left side is equal to right side
 * @retval          false                Left side is not equal to right side
 */
template<typename T>
bool ArrayBase<T>::operator==(const ArrayBase &rhs) const {
    
    // check if same address
    if (this == &rhs)
        return true;
    
    return false;
}

/**
 * Test the array for inequality.
 *
 * @param[in]       rhs                  Right-hand size of not equal to sign
 * @retval          true                 Left side is not equal to right side
 * @retval          false                Left size is equal to right side
 */
template<typename T>
bool ArrayBase<T>:: operator!=(const ArrayBase<T> &rhs) const {
    
    // check if same address
    if (this != &rhs)
        return true;
    
    return false;
}


/**
 * Get the character at the specified index. If the index is not
 * within the range of the array, then std::out_of_range exception
 * is thrown.
 *
 * @param[in]       index               Zero-based location
 * @exception       std::out_of_range   Invalid \a index value
 */
template<typename T>
T & ArrayBase<T>::operator[](size_t index) {
    
    // check if inside of bounds
    if (index < cur_size_) {
        // return requested data
        return data_[index];
    }
    
    //else throw error
    std::cerr << "Exception: out_of_range";
    throw std::out_of_range("Exception: out_of_range");
    
}

/**
 * @overload
 *
 * The returned character is not modifiable.
 */
template<typename T>
const T & ArrayBase<T>::operator[](size_t index) const {
    
    // check if inside of bounds
    if (index < cur_size_) {
        // return requested data
        return data_[index];
    }
    
    //else throw error
    std::cerr << "Exception: out_of_range";
    throw std::out_of_range("Exception: out_of_range");
    
}


/** Class Methods */

/**
 * Retrieve the current size of the array.
 *
 * @return          The current size
 */
template<typename T>
size_t ArrayBase<T>:: size(void) const {
    return cur_size_;
}

/**
 * Retrieve the maximum size of the array.
 *
 * @return          The maximum size
 */
template<typename T>
size_t ArrayBase<T>::max_size(void) const {
    return max_size_;
}


/**
 * Get the character at the specified index. If the \a index is not within
 * the range of the array, then std::out_of_range exception is thrown.
 *
 * @param[in]       index                 Zero-based location
 * @return          Character at \index
 * @exception       std::out_of_range     Invalid index value
 */
template<typename T>
T ArrayBase<T>::get(size_t index) const {
    //check index within range
    if (index < this->cur_size_) {
        //return element
        return this->data_[index];
    }
    // else
    std::cerr << "Exception: out_of_range";
    throw std::out_of_range("Exception: out_of_range");
}

/**
 * Set the character at the specified \a index. If the \a index is not
 * within range of the array, then std::out_of_range exception is
 * thrown.
 *
 * @param[in]       index                 Zero-based location
 * @param[in]       value                 New value for character
 * @exception       std::out_of_range     Invalid \a index value
 */
template<typename T>
void ArrayBase<T>:: set(size_t index, T value) {
    
    // if index withing max range
    if (index < max_size_) {
        
        // assign data
        data_[index] = value;
        
        // if index greater than cur_size
        if (index > cur_size_) {
            
            //  increment cur_size to match last element
            cur_size_ = index;
        }
        // if index == curr size
        if (index == cur_size_) {
            //  increment cur_size to match last element
            cur_size_++;
            
        }
        // else: cur_size_ remains unchanged
        
    } else {
        // else index >= max size
        std::cerr << "Exception: out_of_range";
        throw std::out_of_range("Exception: out_of_range");
    }
}



/**
 * Locate the specified character in the array. The index of the first
 * occurrence of the character is returned. If the character is not
 * found in the array, then -1 is returned.
 *
 * @param[in]        ch        Character to search for
 * @return           Index value of the character
 * @retval           -1        Character not found
 */
template<typename T>
T ArrayBase<T>:: find(T element) const {
    
    // re use more advanced find method
    return find(element, 0);
}

/**
 * @overload
 *
 * This version allows you to specify the start index of the search. If
 * the start index is not within the range of the array, then the
 * std::out_of_range exception is thrown.
 *
 * @param[in]       ch                   Character to search for
 * @param[in]       start                Index to begin search
 * @return          Index value of first occurrence
 * @retval          -1                   Character not found
 * @exception       std::out_of_range    Invalid index
 */
template<typename T>
T ArrayBase<T>:: find(T element, size_t start) const {
    
    
    // Keep withing bounds
    //else throw error
    if (start >= cur_size_) {
        std::cerr << "Exception: out_of_range";
        throw std::out_of_range("Exception: out_of_range");
    }
    
    
    
    // cycle through data
    for (std::size_t i = start; i < cur_size_; i++) {
        
        // return key index if found
        if (data_[i] == element)
            // type cast to int per function return
            return (T) i;
    }
    
    
    
    
    
}

/**
* Fill the contents of the array.
*
* @param[in]       ch                   Fill character
*/
template<typename T>
void ArrayBase<T>:: fill(T element) {
    
    for (std::size_t i = 0; i < max_size_; i++)
        data_[i] = element;
}

/**
 *   Helper Method to desplay
 *    contents of <Reference> type array
 */

template<typename T>
void ArrayBase<T>:: ref_displayArray() {
    
    // Display Members
    std::cout << "\nMax Size: " << this->max_size() << "\n";
    std::cout << "Current Size: " << this->size() << "\n";
    
    // Display Data
    std::cout << "ArrayBase->data_[]:\n";
    for (int i = 0; i < this->size(); i++)
        std::cout << "\t[" << i << "]: " << this->data_[i] << "\n";
    
    std:: cout << "\n";
}

/// Helper Method
template<typename T>
void ArrayBase<T>:: ptr_displayArray() {
    
    // Display Members
    std::cout << "\nMax Size: " << this->max_size() << "\n";
    std::cout << "Current Size: " << this->size() << "\n";
    
    // Display Data
    std::cout << "ArrayBase->data_[]:\n";
    for (int i = 0; i < this->size(); i++)
        std::cout << "\t[" << i << "]: " << *this->data_[i] << "\n";
    
    std:: cout << "\n";
}








