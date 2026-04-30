#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
class LinkedList {
private:
	Node* head;
	Node* tail;
	int length;
public:
	LinkedList(Node* h);
	void append(int value);
	void prepend(int value);
	int removeLast();
	int removeFirst();
	void Display();
};

#endif // !LINKEDLIST_H


