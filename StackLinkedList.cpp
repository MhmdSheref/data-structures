// StackLinkedList.cpp - Implementation of Linked List-Based Stack
#include "StackLinkedList.h"
#include <iostream>
using namespace std;

// Constructor: initialize top to nullptr (empty stack)
StackLinkedList::StackLinkedList() : top(nullptr) {}

// Destructor: free all nodes to prevent memory leaks
StackLinkedList::~StackLinkedList() {
    while (top != nullptr) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

// Push value onto the stack - O(1)
// Creates a new node and makes it the new top
void StackLinkedList::push(int value) {
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
}

// Pop and return the top value - O(1)
// Handles Stack Underflow if stack is empty
int StackLinkedList::pop() {
    if (isEmpty()) {
        cout << "Stack Underflow! Cannot pop from empty stack." << endl;
        return -1;
    }
    Node* temp = top;
    int value = temp->data;
    top = top->next;
    delete temp;
    return value;
}

// Peek at the top value without removing it - O(1)
int StackLinkedList::peek() const {
    if (isEmpty()) {
        cout << "Stack is empty. Nothing to peek." << endl;
        return -1;
    }
    return top->data;
}

// Check if stack is empty - O(1)
bool StackLinkedList::isEmpty() const {
    return (top == nullptr);
}

// Display all elements from top to bottom
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
