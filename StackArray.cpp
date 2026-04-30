#include <iostream>
#include "StackArray.h"
using namespace std;
int StackArray::push(int value) {
    if (topIndex >= size - 1) {
        throw overflow_error("Stack overflow");
    }
    arr[++topIndex] = value;
    return value;
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
