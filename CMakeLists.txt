cmake_minimum_required(VERSION 3.29)
project(DataStruct)

set(CMAKE_CXX_STANDARD 20)

add_executable(DataStruct main.cpp
        Node.h
        LinkedList.h
        LinkedList.cpp
        Queue.cpp
        Queue.h
        Stack.cpp
        Stack.h)
