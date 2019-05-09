//
// Created by Cory Hodge on 2019-05-22.
//

#include "my_shared_lib.h"

#include <iostream>

void print_message (const std::string & msg) {
    std::cout << msg << std::endl;
}

Greeting::Greeting (void) {
}

Greeting::~Greeting (void) {
}

void Greeting::say_message (const std::string & msg) {
    
    std::cerr << msg << std::endl;
}