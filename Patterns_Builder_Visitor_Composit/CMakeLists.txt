cmake_minimum_required(VERSION 3.13)
project(cs363_spring2019_assignment4)

set(CMAKE_CXX_STANDARD 11)

add_executable(cs363_spring2019_assignment4
        main.cpp
        ArrayBase.h
        Queue.h
        Calculator.cpp Calculator.h
        Node.cpp Node.h
        Num_Node.cpp Num_Node.h
        Binary_Node.cpp Binary_Node.h
        Add_Node.cpp Add_Node.h
        Sub_Node.cpp Sub_Node.h
        Mul_Node.cpp Mul_Node.h
        Div_Node.cpp Div_Node.h
        Mod_Node.cpp Mod_Node.h
        Parenthesis_Nodes.cpp Parenthesis_Nodes.h
        Var_Node.cpp Var_Node.h
        Special_Fx_Nodes.cpp Special_Fx_Nodes.h
        Builder.cpp Builder.h
        Visitor.h
        Expression_Visitor.cpp Expression_Visitor.h
        )