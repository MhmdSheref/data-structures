//
// Created by MhmdSheref on 28/04/2026.
//

#ifndef NODE_H
#define NODE_H



class Node {
public:
    Node* next;
    int data;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};



#endif //NODE_H
