#include "QueueLinkedList.h"

#include <iostream>
#include <stdexcept>
#include "Node.h"

QueueLinkedList::QueueLinkedList(){
    front=nullptr;
    rear=nullptr;
    length=0;
}

QueueLinkedList::~QueueLinkedList() {
    Node* node = front;
    while (node != nullptr) {
        Node* newNode = node->next;
        delete node;
        node = newNode;
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
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty");
    }

    Node* temp = front;
    int value = temp->data;
    front = front->next;
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
        std::cout << "[ ]" << std::endl;
        return;
    }

    std::cout << "[ ";
    Node* item = front;
    while (true) {
        std::cout << item->data << " ";
        if (item->next == nullptr) break;
        item = item->next;
    }
    std::cout << "]" << std::endl;
}
