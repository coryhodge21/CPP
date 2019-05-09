#include <iostream>

#include "ArrayBase.h"
#include "Array.h"
#include "Stack.h"
#include "Queue.h"
#include "Fixed_Array.h"

void testArray();

void testStack();

void testQueue();

void testFixed_Array();

int main() {
    
    //testArray();
    //testStack();
    //testQueue();
    //testFixed_Array();
    
    return 0;
}
//
///**
// * Test Array
// */
//void testArray() {
//
//    std::cout << "\nTEST: ARRAY \n";
//    /**
//     * Array < References >
//     */
//    /// Create a Pointer too an Array Class <T>emplate Object
//    Array<int> *intArr = new Array<int>();
//
//    /// Use Raw Values in Reference Array
//    intArr->set(1, 1);
//
//    /// Misc. Logic, obtain T type pointer to store in Array<T>.data_[]
//    int Int = 5;
//    int *myInt = &Int;
//
//    /// Store Type T pointer in Array<T>
//    intArr->set(5, Int);
//
//    /// Display Successfully Stored
//    intArr->ref_displayArray();
//
//    /// Show memory allocated for Array<T> Object
//    std::cout << "Memory Allocated: " << &intArr << "\n";
//
//    /// Free Memory
//    delete intArr;
//
//    /**
//     * Array of < Pointers >
//     *
//     * Pointer type array is Ptr -> [ Ptr1, Ptr2, ... ]
//     */
//
//    /// Instantiate <Ptr *> type array
//    Array<int *> *ptrArray = new Array<int *>();
//
//    /// Cannot Use Raw Values in Ptr Type Array<*>
//    //intArr->set(0, 0);
//
//    /// Must assign pointers to elements of array
//    int zero = 0;
//    int one = 1;
//    int two = 2;
//
//    int *ZERO = &zero;
//    int *ONE = &one;
//    int *TWO = &two;
//
//    ptrArray->set(0, ZERO);
//    ptrArray->set(1, ONE);
//    ptrArray->set(2, TWO);
//
//    /// To display pointer type array, diffrent method must be used
//    ptrArray->ptr_displayArray();
//
//    /// Reference value stored in ptr type array
//    std::cout << "Refrence ptrArray ptr's value with *arr->get(index): " << *ptrArray->get(0) << "\n\n";
//
//    /// Show memory allocated for Array<T> Object
//    std::cout << "Memory Allocated: " << &ptrArray << "\n\n";
//
//    /// data_ is a memeber of Array and allocated memory will be freed with object
//    delete ptrArray;
//}
//
///**
// * Test Stack
// */
//void testStack() {
//
//    std::cout << "\nTEST STACK \n";
//    /**
//     * Test Stack < Reference >
//     */
//    Stack<int> *iStack = new Stack<int>();
//
//    /// perform some operations
//    iStack->push(0);
//    iStack->push(1);
//    iStack->push(2);
//
//    /// Using Reference type array Specific Display Function
//    iStack->ref_displayArray();
//
//    while (!(iStack->is_empty())) {
//        std::cout << "iStack.pop(): " << iStack->top() << "\n";
//        iStack->pop();
//    }
//
//    std::cout << "\nsize after pop: " << iStack->size();
//    std::cout << "\nMax_size: " << iStack->max_size();
//
//
//    /// Free MEmory
//    delete iStack;
//
//    /**
//     * Test Stack < Pointers * >
//     */
//    Stack<int *> *ptrStack = new Stack<int *>();
//
//    /// perform some operations
//
//    int one = 1;
//    int two = 2;
//    int three = 3;
//
//    int *ONE = &one;
//    int *TWO = &two;
//    int *THREE = &three;
//
//    ptrStack->push(ONE);
//    ptrStack->push(TWO);
//    ptrStack->push(THREE);
//
//    /// Using Ptr Type Array Specific Display Function
//    ptrStack->ptr_displayArray();
//
//    while (!(ptrStack->is_empty())) {
//        std::cout << "Stack.top(): " << *ptrStack->top() << "\n";
//        ptrStack->pop();
//    }
//
//    delete ptrStack;
//
//}
//
//
///**
// * Test Queue
// */
//void testQueue() {
//
//    std::cout << "\nTEST QUEUE\n";
//
///// Test Queue < Pointer * >
//    Queue<char *> *chRefQ = new Queue<char *>();
//
//    /// Test En-queue
//    // enqueue expects *
//    char *chPtr;
//    std::string qstring = "Queue";
//    for (size_t i = 0; i < 5; i++) {
//        chPtr = &qstring[i];
//        std::cout << "\nEnqueue(): " << qstring[i] << "\n";
//        chRefQ->enqueue(chPtr);
//        chRefQ->ptr_displayArray();
//    }
//
//    /// Test De-queue
//    chRefQ->ptr_displayArray();
//    while (!(chRefQ->is_empty())) {
//
//        std::cout << "\nQueue->deque(): " << *chRefQ->dequeue() << "\n";
//        chRefQ->ptr_displayArray();
//    }
//    chRefQ->ptr_displayArray();
//
//    delete chRefQ;
//}
//
///**
// * Test Fixed_Array
// */
//void testFixed_Array() {
//
//    std::cout << "\nTEST FIXED ARRAY \n";
//
//    /// Construct Fixed Array of int* with size_t 10
//    Fixed_Array<int *, 10> *fixed_array = new Fixed_Array<int *, 10>();
//
//    int one = 1;
//    int *ONE = &one;
//    // test methods
//    fixed_array->set(10, ONE);
//    fixed_array->fill(ONE);
//
//
//    fixed_array->ref_displayArray();
//    fixed_array->ptr_displayArray();
//
//    delete fixed_array;
//
//}