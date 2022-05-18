#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList generateList()
{
    cout << "Creating linked list inside a function..." << endl;

    LinkedList ll("List generated in function");
    int num = 0;
    for (unsigned int i = 0; i < 2; ++i) {
        ll.insertFront(i);
    }
    cout << ll << endl;
    cout << "Returning from function..." << endl;
    return ll;

}

int main()
{
    cout << "Creating linked list in generateList()..." << endl;
    LinkedList ll_one = generateList();
    cout << "Printing contents of ll_one " << endl;
    cout << ll_one << endl;


}

/*
	While both methods deal with constructing and transferring lists, using the move constructor makes managing the nodes and pointers within each list safer. The move constructor creates a new object and deletes the old object, which is much safer than the alternative, where the objects created inside functions are references to the original. That could cause issues with keeping track of the pointers. Fortunatley, both methods point to the same memory addresses, so taht their end result is the same, if implemented properly.
*/