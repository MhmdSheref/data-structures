//made by youssef 29/4/2026
#include <iostream>
using namespace std;
class Node {
public:
	int value;
	Node* next;
	Node(int val) {
		value = val;
		next = nullptr;
	}
};
class LinkedList {
private:
	Node* head;
	Node* tail;
	int length;
public:
	LinkedList(Node* h) {
		head = h;
		tail = h;
		length = 1;
	}
	void append(int value) {
		Node* newNode = new Node(value);
		tail->next = newNode;
		newNode->next = nullptr;
		tail = newNode;
		length++;
	}
	void prepend(int value) {
		Node* newNode = new Node(value);
		newNode->next = head;
		length++;
		head = newNode;
	}
	int removeLast() {
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
	int removeFirst() {
		Node* temp = head;
		head = head->next;
		length--;
		int removed = temp->value;
		delete temp;
		return removed;

	}
	void Display() {
		Node* temp = head;
		cout << "[ ";
		for (int i = 0; i < length;i++) {
			cout << temp->value << " ";
			temp = temp->next;
		}
		cout << "]";
	}
};




