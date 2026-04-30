#include <iostream>
#include "LinkedList.h"
#include "Node.h"
using namespace std;
	LinkedList::LinkedList(Node* h) {
		head = h;
		tail = h;
		length = 1;
	}
	LinkedList::~LinkedList() {
		while (head != nullptr) {
			Node* node = head->next;
			delete node;
			head = node;
		}
		cout << "Destroyed Linked List Successfully!";
	}
	void LinkedList::append(int value) {
		Node* newNode = new Node(value);
		tail->next = newNode;
		newNode->next = nullptr;
		tail = newNode;
		length++;
	}
	void LinkedList::prepend(int value) {
		Node* newNode = new Node(value);
		newNode->next = head;
		length++;
		head = newNode;
	}
	int LinkedList::removeLast() {
		Node* pre = head;
		Node* temp = head;
		while (temp->next) {
			pre = temp;
			temp = temp->next;
		}
		tail = pre;
		tail->next = nullptr;
		length--;
		int removed = temp->value;
		delete temp;
		return removed;
	}
	int LinkedList::removeFirst() {
		Node* temp = head;
		head = head->next;
		length--;
		int removed = temp->value;
		delete temp;
		return removed;

	}
	void LinkedList::Display() {
		Node* temp = head;
		cout << "[ ";
		for (int i = 0; i < length;i++) {
			cout << temp->value << " ";
			temp = temp->next;
		}
		cout << "]";
	}