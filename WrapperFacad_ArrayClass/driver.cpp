#include <iostream>

#include "Array.h"


void test_1();

void test_2();

void test_3();

void test_4();

void test_5();

void test_6();

void test_7();

void test_8();

void test_9();

int main(int argc, char *argv[]) {
    
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
    test_6();
    test_7();
    test_8();
    test_9();
    
    return 0;
}

void test_1() {
    
    std::cout << "Test 1: Start \n ";
    
    /// Create character array with default constructor
    Array *Array0 = new Array();
    
    // fill array
    Array0->set(0, 'c');
    Array0->set(1, 'o');
    Array0->set(2, 'r');
    Array0->set(3, 'y');
    // display
    Array0->displayArray();
    
    /// check indexing condition
    // set element > current size && < max size
    Array0->set(10, 'z');
    
    //display that z is appended to array
    Array0->displayArray();
    
    /// delete and safe array pointer
    delete Array0;
    Array0 = nullptr;
    
    std::cout << "Test 1: End \n ";
    
    
}

void test_2() {
    
    std::cout << "Test 2: Start \n ";
    
    /// Create character array with default constructor
    Array *Array1 = new Array(10);
    
    // fill array up to length
    for (int i = 0; i < Array1->max_size(); i++) {
        Array1->set(i, 'x');
    }
    
    // display contents
    Array1->displayArray();
    
    /// delete and safe array pointer
    delete Array1;
    Array1 = nullptr;
    
    std::cout << "Test 2: End \n ";
}

void test_3() {
    
    std::cout << "Test 3: Start \n ";
    /// Testing Fill Constructor
    Array *StarArray = new Array(5, '*');
    StarArray->displayArray();
    
    Array *xArray = new Array(3, 'x');
    xArray->displayArray();
    
    /// test Not Equality operator
    if (StarArray != xArray) {
        std::cout << "StarArray != xArray\n";
    }
    
    /// test assignment operator
    StarArray = xArray;
    
    /// test Equality operator
    if (StarArray == xArray) {
        std::cout << "StarArray == xArray\n";
    }
    
    delete StarArray;
    //delete xArray;
    StarArray = nullptr;
    xArray = nullptr;
    
    std::cout << "Test 3: End \n ";
}

void test_4() {
    
    std::cout << "Test 4: Start \n ";
    
    // init blank array
    Array *indexArray = new Array(5, ' ');
    
    // insert data
    indexArray->set(1, 'x');
    
    // test [] operator
    //indexArray[1];
    
    // free memory
    delete indexArray;
    indexArray = nullptr;
    
    std::cout << "Test 4: End \n ";
}

void test_5(){
    std::cout << "Test 5: Start \n ";
    // Test Copy Constructor
    Array * original = new Array(5, 'x');
    
    Array * copy = new Array(original);

    std:: cout << " \nDisplay Copy of array: \t";
    copy->displayArray();
    
    delete original;
    
    std:: cout << " \nDisplay Copy of array after original deleted: \t";
    copy->displayArray();
    
    delete copy;
    std::cout << "Test 5: End \n ";
}

void test_6(){
    std::cout << "Test 6: Start \n ";
    Array * xArray = new Array(10, 'x');
    
    // test resize method
    std:: cout << "Test: resize method: \n";
    xArray->displayArray();
    
    xArray->resize(15);
    xArray->displayArray();
    
    xArray->resize(5);
    xArray->displayArray();

    xArray->resize(10);
    xArray->displayArray();

    delete xArray;
    std::cout << "Test 6: End \n ";
}

void test_7(){
    
    std::cout << "Test 7: Start \n ";
    Array * starArray = new Array(5, '*');
    starArray->displayArray();
    
    // fill
    std:: cout << "Test: fill method: \n";
    starArray->fill('$');
    starArray->displayArray();
    
    // test resize method
    std:: cout << "Test: find method: \n";
    starArray->set(3, 'x');
    starArray->displayArray();
    
    int index = starArray->find('x');
    std:: cout << "find(): assert 3: " << index << "\n";
    
    std:: cout << "Test: reverse method: \n";
    starArray->set(0, '0');
    starArray->set(1, '1');
    starArray->set(2, '2');
    starArray->set(3, '3');
    starArray->set(4, '4');
    
    starArray->displayArray();
    
    starArray->reverse();
    
    starArray->displayArray();
    
    delete starArray;
    std::cout << "Test 7: End \n ";
}

void test_8(){
    
    std::cout << "Test 8: Start \n ";
    
    std::cout << "Test Slice( begin ) \n ";
    
    // prep
    Array * xArray = new Array(5, 'x');
    Array sliced = xArray->slice(0);
    
    sliced.displayArray();

    delete xArray;
    
    std::cout << "Test 8: End \n ";
}

void test_9(){
    
    std::cout << "Test 9: Start \n ";
    
    std::cout << "Test Slice( begin , end ) \n ";
    
    // Shallow var
    Array sliced;
    
    //prep
    Array * starArray = new Array( 5 , '*');
    
    starArray ->displayArray();
    starArray -> set ( 2, 'x');
    starArray -> set ( 3, 'x');
    starArray -> set ( 4, 'x');
    
    sliced = starArray->slice(0, 3);
    
    sliced.displayArray();
    
    std::cout << "Test 9: End \n ";
    
    delete starArray;
}