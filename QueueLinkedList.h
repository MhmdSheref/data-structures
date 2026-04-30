#ifndef QUEUELINKEDLIST_H
#define QUEUELINKEDLIST_H

#include "Node.h"

class QueueLinkedList{
    Node* front;
    Node* rear;
    int length;

public:
    QueueLinkedList();

    ~QueueLinkedList();

    QueueLinkedList(const QueueLinkedList&) = delete;
    QueueLinkedList& operator=(const QueueLinkedList&) = delete;

    void enqueue(int value);

    int dequeue();

    bool isEmpty();

    bool isFull();

    void display();
};


#endif //QUEUELINKEDLIST_H
