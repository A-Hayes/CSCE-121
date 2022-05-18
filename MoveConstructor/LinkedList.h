#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <ostream>
#include <iostream>
#include <iomanip>
#include <string>
#include "Node.h"

class LinkedList {
    Node* head;
    Node* tail;
    std::string name;
    int size_;

    void recursePrint(Node*, std::ostream&) const;
    void remove(Node* node);
    Node* find(int);

public:
    LinkedList();
    LinkedList(std::string);
    LinkedList(const LinkedList& source);
    ~LinkedList();
    // FIXME: add move constructor declaration
	 LinkedList(LinkedList&& source);

    void setName(std::string);
    std::string getName() const;

    int size() const;
    bool empty() const;

    void remove(int value);
    void clear();

    void insertFront(int);
    void insertBack(int);
    void insertAfter(int, int);

    Node* at(int index);

    void print() const;
    void print(std::ostream&) const;
    void printReverse() const;
    void printReverse(std::ostream&) const;

    friend std::ostream& operator<<(std::ostream&, const LinkedList&);
};
std::string center (const std::string &str, const int col_width);
#endif