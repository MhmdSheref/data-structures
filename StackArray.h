#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <stdexcept>

class StackArray {
private:
    static const int size = 100;
    int arr[size];
    int topIndex=-1;
public:
    void push(int value);
    int pop();
    int peek();
    bool isEmpty();
};

#endif // STACKARRAY_H