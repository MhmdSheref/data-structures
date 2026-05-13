#include "Queue.h"
#include <iostream>
#include <stdexcept>
using namespace std;

// QueueArray (Circular)

QueueArray::QueueArray(int cap) {
    if (cap <= 0) throw invalid_argument("Capacity must be > 0");
    capacity = cap;
    arr = new int[capacity];
    head = -1;
    tail = -1;
}

QueueArray::~QueueArray() {
    delete[] arr;
}

void QueueArray::enqueue(int item) {
    if (isFull())
        throw overflow_error("Queue is full");
    if (isEmpty())
        head = 0;
    // Wrap tail around to reuse freed slots at the front
    tail = (tail + 1) % capacity;
    arr[tail] = item;
}

int QueueArray::dequeue() {
    if (isEmpty())
        throw underflow_error("Queue is empty");
    int temp = arr[head];
    if (head == tail) {
        // Last element removed. -1 values mean empty queue
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
    // Next tail position wraps around. if it equals head the array is full
    return (tail + 1) % capacity == head;
}

void QueueArray::display() {
    if (isEmpty()) {
        cout << "[ ]" << endl;
        return;
    }
    cout << "[ ";
    int i = head;
    while (true) {
        cout << arr[i] << " ";
        if (i == tail) break;
        i = (i + 1) % capacity;
    }
    cout << "]" << endl;
}

// QueueLinkedList

QueueLinkedList::QueueLinkedList() : front(nullptr), rear(nullptr), length(0) {}

QueueLinkedList::~QueueLinkedList() {
    Node* node = front;
    while (node != nullptr) {
        Node* next = node->next;
        delete node;
        node = next;
    }
}

void QueueLinkedList::enqueue(int value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    length++;
}

int QueueLinkedList::dequeue() {
    if (isEmpty())
        throw underflow_error("Queue is empty");
    Node* temp = front;
    int value = temp->data;
    front = front->next;
    if (front == nullptr)
        rear = nullptr; // List is now empty. clear rear pointer
    delete temp;
    length--;
    return value;
}

bool QueueLinkedList::isEmpty() {
    return front == nullptr;
}

bool QueueLinkedList::isFull() {
    return false;
}

void QueueLinkedList::display() {
    if (isEmpty()) {
        cout << "[ ]" << endl;
        return;
    }
    cout << "[ ";
    Node* item = front;
    while (item != nullptr) {
        cout << item->data << " ";
        item = item->next;
    }
    cout << "]" << endl;
}
