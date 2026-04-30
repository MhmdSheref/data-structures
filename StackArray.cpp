#include <iostream>
#include "StackArray.h"
using namespace std;

StackArray::StackArray(int size) {
    capacity = size;
    arr = new int[capacity];
    topIndex = -1;
}

StackArray::~StackArray() {
    delete[] arr;
}

void StackArray::push(int value) {
    if (isFull()) {
        throw overflow_error("Stack overflow");
    }
    arr[++topIndex] = value;
}

int StackArray::pop() {
    if (isEmpty()) {
        throw underflow_error("Stack underflow");
    }
    return arr[topIndex--];
}

int StackArray::peek() {
    if (isEmpty()) {
        throw underflow_error("Stack underflow");
    }
    return arr[topIndex];
}

bool StackArray::isEmpty() {
    return topIndex == -1;
}

bool StackArray::isFull() {
    return topIndex >= capacity - 1;
}
