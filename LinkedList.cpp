#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(nullptr), length(0) {}

LinkedList::~LinkedList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::insertAtHead(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    if (tail == nullptr)
        tail = newNode;
    length++;
}

void LinkedList::insertAtEnd(int value) {
    Node* newNode = new Node(value);
    if (tail == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    length++;
}

void LinkedList::deleteValue(int value) {
    if (head == nullptr) return;

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        if (head == nullptr)
            tail = nullptr;
        delete temp;
        length--;
        return;
    }

    Node* prev = head;
    Node* curr = head->next;
    while (curr != nullptr) {
        if (curr->data == value) {
            prev->next = curr->next;
            if (curr == tail)
                tail = prev;
            delete curr;
            length--;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void LinkedList::display() {
    Node* temp = head;
    cout << "[ ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "]" << endl;
}