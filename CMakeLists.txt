cmake_minimum_required(VERSION 3.29)
project(DataStruct)

set(CMAKE_CXX_STANDARD 20)

add_executable(DataStruct main.cpp
        QueueArray.cpp
        QueueArray.h
        QueueLinkedList.cpp
        QueueLinkedList.h
        Node.cpp
        Node.h)
