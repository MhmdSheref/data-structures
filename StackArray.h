#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <stdexcept>

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

#endif // STACKARRAY_H