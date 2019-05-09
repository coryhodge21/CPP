// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

/**
 * Default Constructor
 *
 *  This constructor extends Default Array Constructor
 */
template<typename T, size_t N>
Fixed_Array<T, N>::
Fixed_Array(void) : ArrayBase<T>() {
    
}

/**
 * Copy constructor.
 *
 * This constructor extends Array Copy Constructor
 *
 * @param[in]      arr        Source array
 */
template<typename T, size_t N>
Fixed_Array<T, N>::Fixed_Array(const Fixed_Array<T, N> &arr) :
        ArrayBase<T>(&arr) {
    
}

/**
 * Overload Copy constructor.
 *
 * This constructor extends Array Copy Constructor
 *
 * The source array can be of any size
 * as long as they are of the same type.
 *
 * @param[in]      arr        Source array
 */
template<typename T, size_t N>
template<T, size_t M>
Fixed_Array<T, N>::Fixed_Array(const Fixed_Array<T, M> &arr) :
        ArrayBase<T>(&arr) {
    
}

/**
 * Initializing constructor. Fills the contents of the
 * array with the specified \a fill value.
 *
 * @param[in]      fill       The file value.
 */
template<typename T, size_t N>
Fixed_Array<T, N>::
Fixed_Array(T fill) :
        ArrayBase<T>(fill) {
    
}

/// Destructor.
template<typename T, size_t N>
Fixed_Array<T, N>::
~Fixed_Array(void) {
    
}




