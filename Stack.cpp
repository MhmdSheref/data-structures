#include "Stack.h"
#include <iostream>
#include <stdexcept>
using namespace std;

// StackArray

StackArray::StackArray(int size) : capacity(size), topIndex(-1) {
    arr = new int[capacity];
}

StackArray::~StackArray() {
    delete[] arr;
}

void StackArray::push(int value) {
    if (isFull())
        throw overflow_error("Stack overflow");
    arr[++topIndex] = value;
}

int StackArray::pop() {
    if (isEmpty())
        throw underflow_error("Stack underflow");
    return arr[topIndex--];
}

int StackArray::peek() {
    if (isEmpty())
        throw underflow_error("Stack underflow");
    return arr[topIndex];
}

bool StackArray::isEmpty() {
    return topIndex == -1;
}

bool StackArray::isFull() {
    return topIndex >= capacity - 1;
}

// StackLinkedList

StackLinkedList::StackLinkedList() : top(nullptr) {}

StackLinkedList::~StackLinkedList() {
    while (top != nullptr) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

void StackLinkedList::push(int value) {
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
}

int StackLinkedList::pop() {
    if (isEmpty()) {
        cout << "Stack Underflow!" << endl;
        return -1;
    }
    Node* temp = top;
    int value = temp->data;
    top = top->next;
    delete temp;
    return value;
}

int StackLinkedList::peek() const {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return -1;
    }
    return top->data;
}

bool StackLinkedList::isEmpty() const {
    return top == nullptr;
}

void StackLinkedList::display() const {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack (top -> bottom): ";
    Node* current = top;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
