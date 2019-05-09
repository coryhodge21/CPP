// $Id: Array.cpp 820 2011-01-17 15:30:41Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"


/**
 * Constructor / Destructor
 */

/// Default Constructor
//  current size = 0
Array::Array() :
        data_(new char[DEFAULT_ARRAY_LENGTH]),
        cur_size_(0),
        max_size_(DEFAULT_ARRAY_LENGTH) {
}

/// Size Constructor
//  current size = 0
Array::Array(std::size_t length) :
        data_(new char[length]),
        cur_size_(0),
        max_size_(length) {
}

/// Fill Constructor
//  current size = length
Array::Array(std::size_t length, char fill) :
        data_(new char[length]),
        cur_size_(length),
        max_size_(length) {
    
    // Fill the array with passed fill value
    for (int i = 0; i < length; i++) {
        data_[i] = fill;
    }
}

/// Copy Constructor
Array::Array(const Array *array) :
        data_(new char[array->max_size()]),
        cur_size_(array->size()),
        max_size_(array->max_size()) {
    
    // copy elements from array
    for (int i = 0; i < cur_size_; i++)
        this->data_[i] = array->data_[i];
}

Array::~Array(void) {
    
    // COMMENT Printing a statement here adds no value to the code.
    /*
     * Addressed: removed cout"" and simplified code
    */
    
    // COMMENT There is no need to reset the data_ variable since this object is no
    // longer useable after the desturctor returns.
    /*
     * Addressed: Removed pointing data to nullptr
     */
    
    if (data_ != nullptr)
        delete[] data_;
}

/**
 * Operators
 */


/// Assignment Operator
const Array &Array::operator=(const Array &rhs) {
    
    //check rhs does not point to same address
    if (this != &rhs) {
        
        // not same address, so delete old data
        delete[] this->data_;
        
        // Update Array members
        this->cur_size_ = rhs.size();
        this->max_size_ = rhs.max_size();
        
        // allocate space for new array
        this->data_ = new char[rhs.max_size()];
        
        //for every element in rhs array, copy value to data
        for (size_t i = 0; i < rhs.max_size_; i++) {
            this->data_[i] = rhs.data_[i];
        }
    }
    
    // return Array
    return *this;
}

/// Equality Operator
bool Array::operator==(const Array &rhs) const {
    
    // check if same address
    if (this == &rhs)
        return true;
    
    // COMMENT Two arrays are equal if there content is the same. Just
    // comparing the address of the arrays will not suffice.
    /*
     * Addressed: added steps to check contents of arrays
     *
     */
    
    // arrays cannot match if different number of elements
    if (this->cur_size_ != rhs.cur_size_) {
        return false;
    }
    
    // arrays are same size, continue to check contents
    for (int i = 0; i < this->cur_size_; i++) {
        
        // comapare every value
        if (this->get(i) != rhs.get(i)) {
            
            //if any do not match return false
            return false;
        }
    }
    
    // All values of array elements match
    return true;
}

/// Not Equality Operator
bool Array::operator!=(const Array &rhs) const {
    
    // COMMENT You can define operator != in terms of operator ==.
    /*
     * Addressed: defined method in terms of other method
     */
    
    // if arrays are equal too each other
    if (this == &rhs) {
        
        // they are not not equal
        return false;
    }
    
    // Else : Arrays are not equal to each other
    return true;
}

/// Subscript Operator
char &Array::operator[](size_t index) {
    
    // COMMENT Printing a statement here adds no value to the code.
    /*
     * Addressed: moved throw error statement
     */
    
    // check if inside of bounds
    if (index > cur_size_ || index < 0) {
        std::cout << "Out of index range. Array.slice([]) \n";
        throw std::out_of_range("Exception: out_of_range");
    }
    
    // return requested data
    return data_[index];
    
}

/// Overloaded Subscript Operator
const char &Array::operator[](size_t index) const {
    
    // COMMENT Printing a statement here adds no value to the code.
    /*
     * Addressed: moved throw error statement
     */
    
    // check if inside of bounds
    if (index > cur_size_ || index < 0) {
        std::cout << "Out of index range. Array.slice([]) \n";
        throw std::out_of_range("Exception: out_of_range");
    }
    
    // return requested data
    return data_[index];
}


/**
 * Setters / Getters
 */

///@return Character at index
char Array::get(size_t index) const {
    
    
    // COMMENT Printing a statement here adds no value to the code.
    /*
     * Addressed: moved throw error statement
     */
    
    // check if inside of bounds
    if (index > cur_size_ || index < 0) {
        std::cout << "Out of index range. Array.slice([]) \n";
        throw std::out_of_range("Exception: out_of_range");
    }
    
    // return requested data
    return data_[index];
    
}

/// Set the character at the specified \a index.
bool Array::set(size_t index, char value) {
    
    
    // COMMENT Printing a statement here adds no value to the code.
    /*
     * Addressed: moved throw error statement
     */
    
    // check if inside of bounds
    if (index > max_size_ || index < 0) {
        std::cout << "Out of index range. Array.slice([]) \n";
        throw std::out_of_range("Exception: out_of_range");
    }
    
    // assign data
    data_[index] = value;
    
    // if index within cur_size range
    if (index < cur_size_) {
        
        //  cur_size remains same, exit
        return true;
    }
    
    // else, increment cur_size to match last element, exit
    cur_size_ = index;
    return true;
    
}


/**
 * Class Methods
 */

/// resize the data_ array, re allocates, truncates, and/or fills with garbage
void Array::resize(size_t new_size) {
    
    // COMMENT The resize method should only increase the size of the allocation if
    // the new size is larger than the current memory allocation for the array. If resized,
    // you need to preserve the old data. Otherwise, you can just update cur_size_ to
    // reflect the new size.
    /*
     * Addressed:  Re designed resize method. Only reallocation occurs when
     *                  new_size > max_size. Simplified code
   */
    
    
    // new_size < 1
    if (new_size < 1) {
        std::cout << "resize index request must be larger than 0: error";
        throw std::out_of_range("Exception: out_of_range");
    }
        
        // only re-allocate if requested new size is > current max size
    else if (new_size > this->max_size()) {
        
        // copy data to stack
        Array temp = Array(this);
        
        // De allocate old memory
        delete[] this->data_;
        
        // Allocate new memory
        this->data_ = new char[new_size];
        
        // copy contents into this data[]
        for (size_t i = 0; i < temp.cur_size_; i++)
            this->set(i, temp.get(i));
        
        // update data members
        this->max_size_ = new_size;
        // curr size remains the same;
    }
        
        // Else truncate and update members
    else {
        
        // new_size within bounds (1, max_ )
        this->max_size_ = new_size;
        
        // if cur size larger than cutoff
        if (new_size < this->cur_size_)
            this->cur_size_ = new_size;
        
        
    }
    
}

/// @return     index to matching key in data_ ( begin: 0 )
int Array::find(char ch) const {
    
    // COMMENT Using find with index id good, but it will throw an exception is certain cases.
    // The find with no index should not throw an exception.
    /*
     * Addressed:   re wrote method. now does not throw
     *              code and searches array from 0 to end
     *
     *
     */
    // Keep withing bounds
    for (size_t i = 0; i < this->size(); i++) {
        
        // return key index if found
        if (data_[i] == ch)
            // type cast to int per function return
            return (int) i;
    }
    // else, return -1 for no match
    return -1;
}

/// @return     index to matching key in data_ ( begin: start )
int Array::find(char ch, size_t start) const {
    
    // COMMENT You are to throw an exception if the index is invalid.
    /*
     * Addressed: added index checker with throw exception
   */
    
    // Keep withing bounds
    if (start >= cur_size_ || start < 0) {
        //else throw error
        std::cerr << "Exception: out_of_range";
        throw std::out_of_range("Exception: out_of_range");
    }
    
    // cycle through data
    for (size_t i = start; i < cur_size_; i++) {
        
        // return key index if found
        if (data_[i] == ch)
            // type cast to int per function return
            return (int) i;
    }
    
    // else, return -1 for no match
    return -1;
    
}

/// fill array with passed element value
void Array::fill(char ch) {
    
    for (std::size_t i = 0; i < max_size_; i++)
        data_[i] = ch;
    
}

/// shrink excess spaces from array
void Array::shrink(void) {
    // COMMENT Purpose of the shrink method is to recover an unused
    // memory allocation. For example, if the array has allocated 10, and
    // the current size is 5, then 5 spaces us wasted. The shrink method
    // we reclaim the 5 unused spaces so the array only has an allocation
    // large enough to fits is current size (i.e., 5 in this example).
    
    /*
     * Addressed: Thank you for the explanation, Method Defined
     */
    
    // if there is wasted space
    if (this->size() < this->max_size()) {
        
        // make a copy of the object on the stack
        Array temp = Array(this);
        
        // De allocate old memory
        delete[] this->data_;
        
        // Allocate new smaller data_[] memory
        this->data_ = new char[temp.size()];
        
        // copy array values into allocated elements
        for (size_t i = 0; i < temp.size(); i++) {
            this->set(i, temp.get(i));
        }
    }
}

void Array::reverse(void) {
    // COMMENT There is no need to create a copy of the array to reverse its contents
    /*
     * Addressed: redefined method like bubble sorting, no copys made
     */
    
    // check that there is data to reverse
    if (this->size() > 1) {
        
        // rounds to floor
        size_t half = (this->size() / 2);
        
        // bubble sort
        size_t i = 0;
        while (i < half) {
            
            // head starts at index 0 and incriments
            char head = this->data_[i];
            
            // tail starts at last element and decrements
            char tail = this->data_[this->cur_size_ - (i + 1)];
            
            // temporary holder to swap elements
            char bubble = head;
            
            head = tail;
            
            tail = bubble;
            
            // re assign values
            this->data_[i] = head;
            this->data_[this->cur_size_ - (i + 1)] = tail;
            
            // continue to work inward
            // odd indexed arrays most
            // center element is never
            // touched
        }
        
    }
    
}

/**
 * The slice() method returns a shallow copy of a portion of an array into
 * a new array object selected from begin to end (end not included). The original
 * array will not be modified.
 *
 * @param[in]       begin           The starting index
 * @return          A new Array object
 */
Array Array::slice(size_t begin) const {
    
    return this->slice(begin, cur_size_);
    
}

/**
 * @overload
 *
 * @param[in]       begin           The starting index
 * @param[in]       end             The ending index
 * @return          A new Array object
 */
Array Array::slice(size_t begin, size_t end) const {
    
    // ensure within bounds
    if ((end <= max_size_) && (begin <= end)) {
        
        // Shallow Copy
        Array shallow;
        
        // cycle through array and copy contents: begin -> end into shallow
        std::size_t x = 0;
        // end + 1, due to 0 based index
        for (std::size_t i = begin; i < (end + 1); i++) {
            shallow.data_[x] = this->data_[i];
            x++;
        }
        // set constraints
        shallow.max_size_ = this->max_size_;
        shallow.cur_size_ = x;
        
        return shallow;
    }
    
    // else index >= max size
    std::cerr << "Exception: out_of_range";
    throw std::out_of_range("Exception: out_of_range");
    
}

/**
 * HELPER METHODS
 */

/// cycle through array and display elements values
void Array::displayArray() {
    
    // Display Members
    std::cout << "\nMax Size: " << this->max_size() << "\n";
    std::cout << "Current Size: " << this->size() << "\n";
    
    // Display Data
    std::cout << "Array->data_[]:\n";
    for (int i = 0; i < this->size(); i++)
        std::cout << "\t[" << i << "]: " << this->get(i) << "\n";
}
