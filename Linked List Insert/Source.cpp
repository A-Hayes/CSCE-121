#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
    LinkedList ll("Test List 1");

    ll.print_head();ll .print_tail(); ll.print();

	Node* new_node = new Node(10);
	ll.insert_front(new_node);
	ll.print(); ll.print_head(); ll.print_tail(); cout << endl;

	Node* new_node2 = new Node(11);
	ll.insert_front(new_node2);
	ll.print(); ll.print_head(); ll.print_tail(); cout << endl;

	Node* new_node3 = new Node(12);
	ll.insert_front(new_node3);
	ll.print(); ll.print_head(); ll.print_tail(); cout << endl;

	Node* new_node4 = new Node(13);
	ll.insert_back(new_node4);
	ll.print(); ll.print_head(); ll.print_tail(); cout << endl;

	Node* new_node5 = new Node(14);
	ll.insert_back(new_node5);
	ll.print(); ll.print_head(); ll.print_tail(); cout << endl;

	Node* new_node6 = new Node(15);
	ll.insert_back(new_node6);
	ll.print(); ll.print_head(); ll.print_tail(); cout << endl;


    //system("pause");

}