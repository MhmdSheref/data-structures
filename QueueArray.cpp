#include "QueueArray.h"

#include <iostream>
#include <stdexcept>

    QueueArray::QueueArray(int cap) {
        if (cap <= 0) throw std::invalid_argument("Capacity must be > 0");
        capacity = cap;
        arr = new int[capacity];
        tail = -1;
        head = -1;
    }

    QueueArray::~QueueArray() {
        delete[] arr;
    }

    void QueueArray:: enqueue(int item) {
        // Check if full
        if (isFull()) {
            throw std::overflow_error("Queue is full");
        }

        // If empty, initialize head
        if (isEmpty()) {
            head = 0;
        }

        tail = (tail + 1) % capacity;
        arr[tail] = item;
    }

    int QueueArray::dequeue() {
        // Check if empty
        if (head == -1) {
            throw std::underflow_error("Queue is empty");
        }

        int temp = arr[head];

        // If this was the last element, reset to empty state
        if (head == tail) {
            head = -1;
            tail = -1;
        } else {
            head = (head + 1) % capacity;
        }

        return temp;
    }

    bool QueueArray::isEmpty() {
        return head == -1;
    }

    bool QueueArray::isFull() {
        return (tail + 1) % capacity == head;
    }

    void QueueArray::display() {

        if (isEmpty()) {
            std::cout << "[ ]" << std::endl;
            return;
        }

        std::cout << "[ ";
        int i = head;
        while (true) {
            std::cout << arr[i] << " ";
            if (i == tail) break;
            i = (i + 1) % capacity;
        }
        std::cout << "]" << std::endl;
    }
