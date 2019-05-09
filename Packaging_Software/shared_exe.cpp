//
// Created by Cory Hodge on 2019-04-22.
//

#include "shared_exe.h"

#include "my_shared_lib.h"

shared_exe:: shared_exe(){

}

shared_exe:: ~shared_exe(){
}

void shared_exe:: use_shared_lib() {
    
    print_message ("Hello, World!");
    
    Greeting g;
    g.say_message ("Hello, World!");
    
}