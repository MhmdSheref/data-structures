#ifndef STACK_H
#define STACK_H

#include "Node.h"

class StackArray {
private:
    int* arr;
    int capacity;
    int topIndex;
public:
    StackArray(int size = 100);
    ~StackArray();
    void push(int value);
    int pop();
    int peek();
    bool isEmpty();
    bool isFull();
};

class StackLinkedList {
private:
    Node* top;
public:
    StackLinkedList();
    ~StackLinkedList();
    void push(int value);
    int pop();
    int peek() const;
    bool isEmpty() const;
    void display() const;
};

#endif // STACK_H
