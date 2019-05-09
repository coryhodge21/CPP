//
// Created by Cory Hodge on 2019-05-22.
// my_shared_lib.h

#ifndef SHARED_LIB_MY_SHARED_LIB_H
#define SHARED_LIB_MY_SHARED_LIB_H

#include <string>

#include "my_shared_lib_export.h"      // include export header

MY_SHARED_LIB_Export

void print_message (const std::string & msg);

class MY_SHARED_LIB_Export Greeting {

    public:
        Greeting (void);
        ~Greeting (void);
        
        void say_message (const std::string & msg);
};



#endif //SHARED_LIB_MY_SHARED_LIB_H
