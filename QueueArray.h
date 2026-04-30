#ifndef QUEUE_H
#define QUEUE_H

class QueueArray {
    int *arr;
    int tail;
    int head;
    int capacity;

public:
    QueueArray(int cap);

    ~QueueArray();

    QueueArray(const QueueArray&) = delete;
    QueueArray& operator=(const QueueArray&) = delete;

    void  enqueue(int item);

    int dequeue();

    bool isEmpty();

    bool isFull();

    void display();
};

#endif //QUEUE_H
