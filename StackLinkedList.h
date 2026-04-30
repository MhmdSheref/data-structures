// StackLinkedList.h - Interface for Linked List-Based Stack
#ifndef STACKLINKEDLIST_H
#define STACKLINKEDLIST_H

#include "Node.h"

class StackLinkedList {
private:
    Node* top;

public:
    StackLinkedList();
    ~StackLinkedList();          // free all nodes

    void push(int value);
    int pop();
    int peek() const;
    bool isEmpty() const;
    void display() const;
};

#endif
