#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <stdexcept>

class StackArray {
private:
    static const int kCapacity = 100;
    int arr[kCapacity];
    int topIndex;

public:
    StackArray() : topIndex(-1) {}

    bool isEmpty() const {
        return topIndex == -1;
    }

    bool isFull() const {
        return topIndex == kCapacity - 1;
    }

    void push(int value) {
        if (isFull()) {
            throw std::overflow_error("Stack overflow");
        }
        arr[++topIndex] = value;
    }

    int pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack underflow");
        }
        return arr[topIndex--];
    }

    int peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        return arr[topIndex];
    }

    int size() const {
        return topIndex + 1;
    }
};

#endif // STACKARRAY_H