#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <string>
#include "Node.h"

class LinkedList {
	Node* head;
	Node* tail;
	std::string name;

public:
	LinkedList();
	LinkedList(std::string);
	
	std::string get_name() const; 
	void set_name(std::string);
	void print(char, std::ostream& os = std::cout);.


    /* not the real way to create a list, but it will give us something to
       use for testing parts until we learn how.
    */
	void make_test_list();

};

#endif