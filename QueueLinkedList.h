//
// Created by Ammar on 28/04/2026.
//

#ifndef QUEUELINKEDLIST_H
#define QUEUELINKEDLIST_H

#include <iostream>
#include <stdexcept>
#include "Node.h"

class QueueLinkedList{
    Node* front;
    Node* rear;
    int length;

public:
    QueueLinkedList();

    void enqueue(int value);

    int dequeue();

    bool isEmpty();

    bool isFull();

    void display();
};


#endif //QUEUELINKEDLIST_H
