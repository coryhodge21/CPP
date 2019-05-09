// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $
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
// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

#ifndef _ARRAY_Base_
#define _ARRAY_Base_

#include <iostream>
#include <cstring>          // for size_t definition
#include <stdexcept>

#define DEFAULT_ARRAY_LENGTH 100
#define EMPTY 0

/**
 * @class Array
 *
 * Basic implementation of a standard array class for chars.
 */
template<typename T>
class ArrayBase {

/** Class Members */
protected:
    /// Pointer to the actual data.
    T *data_;
    
    /// Current size of the array.
    size_t cur_size_;
    
    /// Maximum size of the array.
    size_t max_size_;


public:
    /// Type definition of the element type.
    typedef T type;

/** Constructors / Destructor */
    
    /// Default constructor.
    ArrayBase(void);
    
    /**
     * Initializing constructor.
     *
     * @param[in]      length        Initial size
     */
    ArrayBase(size_t length);
    
    /**
     * Initializing constructor.
     *
     * @param[in]      length        Initial size
     * @param[in]      fill          Initial value for each element
     */
    ArrayBase(size_t length, T fill);
    
    /**
     * Copy constructor * Pointer
     *
     * @param[in]     arr         The source array.
     */
    ArrayBase(const ArrayBase *array);
    
    /**
     * Copy constructor & Reference
     *
     * @param[in]     arr         The source array.
     */
    ArrayBase(const ArrayBase &array);
    
    /// Destructor.
    virtual ~ArrayBase(void);

/** Operators */
    
    /**
     * Assignment operation
     *
     * @param[in]       rhs      Right-hand side of equal sign
     * @return          Reference to self
     */
    virtual const ArrayBase<T> &operator=(const ArrayBase<T> &rhs);
    
    /**
     * Test the array for equality.
     *
     * @param[in]       rhs                  Right hand side of equal to sign
     * @retval          true                 Left side is equal to right side
     * @retval          false                Left side is not equal to right side
     */
    virtual bool operator==(const ArrayBase &rhs) const;
    
    /**
     * Test the array for inequality.
     *
     * @param[in]       rhs                  Right-hand size of not equal to sign
     * @retval          true                 Left side is not equal to right side
     * @retval          false                Left size is equal to right side
     */
    virtual bool operator!=(const ArrayBase<T> &rhs) const;
    
    
    /**
     * Get the character at the specified index. If the index is not
     * within the range of the array, then std::out_of_range exception
     * is thrown.
     *
     * @param[in]       index               Zero-based location
     * @exception       std::out_of_range   Invalid \a index value
     */
    virtual T &operator[](size_t index);
    
    /**
     * @overload
     *
     * The returned character is not modifiable.
     */
    virtual const T &operator[](size_t index) const;


/** Class Methods */
    
    /**
     * Retrieve the current size of the array.
     *
     * @return          The current size
     */
    virtual size_t size(void) const;
    
    /**
     * Retrieve the maximum size of the array.
     *
     * @return          The maximum size
     */
    virtual size_t max_size(void) const;
    
    
    /**
     * Get the character at the specified index. If the \a index is not within
     * the range of the array, then std::out_of_range exception is thrown.
     *
     * @param[in]       index                 Zero-based location
     * @return          Character at \index
     * @exception       std::out_of_range     Invalid index value
     */
    virtual T get(size_t index) const;
    
    /**
     * Set the character at the specified \a index. If the \a index is not
     * within range of the array, then std::out_of_range exception is
     * thrown.
     *
     * @param[in]       index                 Zero-based location
     * @param[in]       value                 New value for character
     * @exception       std::out_of_range     Invalid \a index value
     */
    virtual void set(size_t index, T value);
    
    
    /**
     * Locate the specified character in the array. The index of the first
     * occurrence of the character is returned. If the character is not
     * found in the array, then -1 is returned.
     *
     * @param[in]        ch        Character to search for
     * @return           Index value of the character
     * @retval           -1        Character not found
     */
    virtual T find(T element) const;
    
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
    virtual T find(T element, size_t start) const;
    
    /**
   * Fill the contents of the array.
   *
   * @param[in]       ch                   Fill character
   */
    virtual void fill(T element);
    
    /**
     *   Helper Method to desplay
     *    contents of <Reference> type array
     */
    
    void ref_displayArray();
    
    /// Helper Method
    void ptr_displayArray();
};


#include "ArrayBase.cpp"


#endif   // !defined _ARRAY_Base_
