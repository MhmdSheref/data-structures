#include <iostream>
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
using namespace std;

int main() {
    cout << "=== Linked List ===" << endl;
    LinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtHead(5);
    list.display();
    list.deleteValue(20);
    list.display();

    cout << "\n=== Stack (Array) ===" << endl;
    StackArray sa(5);
    sa.push(1);
    sa.push(2);
    sa.push(3);
    cout << "Peek: " << sa.peek() << endl;
    cout << "Pop: " << sa.pop() << endl;
    cout << "Pop: " << sa.pop() << endl;
    cout << "isEmpty: " << sa.isEmpty() << endl;

    cout << "\n=== Stack (Linked List) ===" << endl;
    StackLinkedList sl;
    sl.push(10);
    sl.push(20);
    sl.push(30);
    sl.display();
    cout << "Pop: " << sl.pop() << endl;
    sl.display();

    cout << "\n=== Queue (Circular Array) ===" << endl;
    QueueArray qa(5);
    qa.enqueue(1);
    qa.enqueue(2);
    qa.enqueue(3);
    qa.display();
    cout << "Dequeue: " << qa.dequeue() << endl;
    qa.enqueue(4);
    qa.display();

    cout << "\n=== Queue (Linked List) ===" << endl;
    QueueLinkedList ql;
    ql.enqueue(100);
    ql.enqueue(200);
    ql.enqueue(300);
    ql.display();
    cout << "Dequeue: " << ql.dequeue() << endl;
    ql.display();

    return 0;
}
