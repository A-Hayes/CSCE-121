#ifndef NODE_H
#define NODE_H
#include <iostream>
struct Node {
    int value;
    Node* next;

    Node(int i) : value(i), next(nullptr) {
        //std::cout << "Node object created" << std::endl;
    }
    Node() : value(0), next(nullptr) {
        //std::cout << "Node object created" << std::endl;
    }
};
#endif