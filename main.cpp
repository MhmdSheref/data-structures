#include <iostream>
#include "QueueArray.h"
#include "QueueLinkedList.h"

int main() {
    QueueArray queue(5);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.display();
    std::cout << queue.isFull() << std::endl;
    std::cout << queue.isEmpty() << std::endl;
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.display();
    std::cout << queue.isFull() << std::endl;
    std::cout << queue.isEmpty() << std::endl;
    return 0;
}
