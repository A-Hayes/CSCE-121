#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

LinkedList::LinkedList(string name) : head(nullptr), tail(nullptr), name(name) {}

bool LinkedList::is_empty(){
	if(head == nullptr && tail == nullptr){
		return true;
	}else{
		return false;
	}
	
} 

void LinkedList::insert_front(Node * n) {
    if (is_empty()) {
        head = n; tail = n;
    }
    else {
        n->next = head;
        head = n;
    }
}

	/* 
	The logical statment is necessary to make sure the sequence of the list stays in proper order. 
	For the provided example, node 10 goes in first. Since the list is currently empty, both head and tail are now set to node 10.
	This ensures that the back of the list is set before any other items. 
	After that, the new nodes 2 and 12 are added to the front, replacing the position of node 10 as front for east one. 
	Basically, the location of the first node entered is pointed to as both tail and head, and stays as tail so we know 
	the end of the frontloaded list. After that, node 10 is inserted and head points to that instead of the previous location. 
	This repeats for node 12, having head point to that, leaving node 2 in the middle and node 10 as tail. This ensures that the list always has a start and an end. 
	*/
	
void LinkedList::insert_back(Node * n) {
    if (is_empty()) {
        head = n; 
    }
    else {
        tail->next = n;
    }
	tail = n;
}


void LinkedList::setName(string name) {
    this->name = name;
}

string LinkedList::getName() const {
    return name;
}

void LinkedList::print(char c, ostream& os) {
    Node* cur = head;
    if (head != nullptr) {
        while (cur != nullptr) {
            os << *cur;
            if (cur != tail)
                os << c;
            if (cur == tail)
                os << endl;
            cur = cur->next;
        }
    }
    else {
        os << "<Empty List>" << c;
    }
}

void LinkedList::print_head(char c, ostream& os) {
    if (head != nullptr) {
        os << head->value << c;
    }
    else {
        os << "<Empty List>" << c;
    }
}

void LinkedList::print_tail(char c, ostream& os) {
    if (head != nullptr) {
        os << tail->value << c;
    }
    else {
        os << "<Empty List>" << c;
    }
}

void LinkedList::makeTestList() {
    // not the real way to create a list, but it will give us something to
    //  use for testing parts until we learn how.
    Node* newNode = new Node(7);
    head = newNode;
    newNode = new Node(3);
    head->next = newNode;
    newNode = new Node(12);
    head->next->next = newNode;
    tail = newNode;
}

