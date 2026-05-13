#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

class QueueArray {
private:
    int* arr;
    int head;
    int tail;
    int capacity;
public:
    QueueArray(int cap);
    ~QueueArray();
    QueueArray(const QueueArray&) = delete;
    QueueArray& operator=(const QueueArray&) = delete;
    void enqueue(int item);
    int dequeue();
    bool isEmpty();
    bool isFull();
    void display();
};

class QueueLinkedList {
private:
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

#endif // QUEUE_H
