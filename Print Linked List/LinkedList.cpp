#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

LinkedList::LinkedList(string name) : head(nullptr), tail(nullptr), name(name) {}

std::string get_name() const{
	return name;
}

void set_name(std::string name){
	this->name = name;
}

void LinkedList::print(char c, ostream& os) {
    Node* cur = head;
    while (cur != nullptr) {
        os << *cur;
        if (cur != tail)
            os << c;
        if (cur == tail)
            os << endl;
        cur = cur->next;
    }
}



void LinkedList::make_test_list() {
     /* again, not the real way to create a list, but it will give us something to
       use for testing parts until we learn how.
    */
    Node* newNode = new Node(7);
    head = newNode;
    newNode = new Node(3);
    head->next = newNode;
    newNode = new Node(12);
    head->next->next = newNode;
    tail = newNode;
}

