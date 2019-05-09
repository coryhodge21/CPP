cmake_minimum_required(VERSION 3.12)
project(Cmd_AbsFactory_StackCalc)

set(CMAKE_CXX_STANDARD 11)

add_executable(
        Cmd_AbsFactory_StackCalc main.cpp
        ArrayBase.h Stack.h
        Receiver.cpp Receiver.h
        Invoker.cpp Invoker.h
        Abstract_Command.h Command.cpp Command.h
        Abstract_Factory.h ConcreteFactories.cpp ConcreteFactories.h
        Abstract_Product.h ConcreteProducts.cpp ConcreteProducts.h
        AddCmd.cpp AddCmd.h
        SubCmd.cpp SubCmd.h
        MulCmd.cpp MulCmd.h
        DivCmd.cpp DivCmd.h
        Parenthesis.cpp Parenthesis.h
)

