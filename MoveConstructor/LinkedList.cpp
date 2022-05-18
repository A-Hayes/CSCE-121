#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() :
    head(nullptr), tail(nullptr), name(""), size_(0) {
        cout << "LinkedList() constructor was called" << endl;
    }

LinkedList::LinkedList(string name) :
    head(nullptr), tail(nullptr), name(name), size_(0) {
         cout << "LinkedList(string) constructor was called" << endl;
    }

LinkedList::LinkedList(const LinkedList& source) {
    this->head = nullptr;
    this->tail = nullptr;
    Node* current = source.head;
    while (current != nullptr) {
        this->insertBack(current->value);
        current = current->next;
    }
    this->name = source.name;
    this->size_ = source.size_;
    cout << "LinkedList copy constructor was called" << endl;
}

// FIXME:
// Uncomment and complete the implementation of a move constructor for LinkedList

LinkedList::LinkedList(LinkedList&& source) {
    // STEP 1: Steal/pilfer dynamic pointers from source
		this->head  = source.head;
		this->tail  = source.tail;
		this->name  = source.name;

    // (also copy values of non-dynamic data members)
		this->name = source.name;
		this->size_ = source.size_;

    // STEP 2: Set source's dynamic pointers to nullptr
		source.head = nullptr;
		source.tail = nullptr;


    cout << "LinkedList move constructor was called" << endl;

}

/*
	
*/


LinkedList::~LinkedList() {
    this->clear();
    cout << "LinkedList destructor called." << endl;
}

void LinkedList::setName(string name) {
    this->name = name;
}

string LinkedList::getName() const {
    return name;
}

int LinkedList::size() const {
    return this->size_;
}

bool LinkedList::empty() const {
    return (this->size_ == 0);
}

void LinkedList::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* deleteNode = current;
        current = current->next;
        delete deleteNode;
    }
    head = nullptr;
    tail = nullptr;
    size_ = 0;
}

void LinkedList::remove(Node* removeNode) {
    Node* current = this->head;
    // traverse list and stop at the node before the one we
    //   need to delete. If we stop at the node we need to remove
    //   we can't access the previous node to connect it to the
    //   node after the one we remove
    while (current != nullptr && current->next != removeNode)
        current = current->next;
    // current points to the node before the one to remove
    if (current != nullptr) {
        --size_;
        current->next = removeNode->next;
    }
    delete removeNode;
}

void LinkedList::remove(int value) {
    Node* removeNode = find(value);
    remove(removeNode);
}

void LinkedList::insertFront(int value) {
    Node* newNode = new Node(value);
    newNode->next = head; // attach to list
    head = newNode;
    if (tail == nullptr) { // empty list
        tail = newNode; // only node is both head and tail
    }
    ++size_;
}

void LinkedList::insertBack(int value) {
    Node* newNode = new Node(value);
    if (tail != nullptr)
        tail->next = newNode; // attach to list
    tail = newNode;
    if (head == nullptr) { // empty list
        head = newNode; // only node is both head and tail
    }
    ++size_;
}

void LinkedList::insertAfter(int index, int value) {
    Node* indexNode = this->at(index);
    if (indexNode != nullptr) {
        Node* newNode = new Node(value);
        newNode->next = indexNode->next;
        indexNode->next = newNode;
        ++size_;
        if (indexNode == this->tail) {
            this->tail = newNode;
        }
    }
    else {
        insertBack(value);
    }
}

Node* LinkedList::at(int index) {
    Node* current = this->head;
    int i = 0;
    while (current != nullptr && i < index) {
        current = current->next;
        ++i;
    }
    return current;
}

// finds and returns first occurence of value in the list
Node* LinkedList::find(int value) {
    Node* current = this->head;
    while (current != nullptr) {
        if (current->value == value)
            return current;
        current = current->next;
    }
    return nullptr;
    // we could also throw an exception but returning
    //  nullptr is a standard way to indicate the
    //  element with the desired pointer was not found
}


void LinkedList::print() const {
    print(cout);
}

void LinkedList::print(ostream& os) const {
    os << this;
}

void LinkedList::printReverse() const {
    printReverse(cout);
}

void LinkedList::printReverse(ostream& os) const {
    os << this->name << " (size " << this->size() << "): {";
    Node* current = this->head;
    recursePrint(current, os);
    os << "}" << endl << endl;
}

void LinkedList::recursePrint(Node* node, ostream& os) const {
    if (node != nullptr) {
        recursePrint(node->next, os);
        os << node->value << " ";
    }
}

string center (const string &str, const int col_width)
{
    // quick and easy (but error-prone) implementation
    int padl = (col_width - str.length()) / 2;
    int padr = (col_width - str.length()) - padl;
    string strf = string(padl, ' ') + str + string(padr, ' ');
    return strf;
}
std::ostream& operator<<(std::ostream& os, const LinkedList & ll)
{
    Node* curr = (&ll)->head;
    int field_size = 5;

    os << '.' << std::setw(field_size) << std::setfill('-') << '.' << std::setfill(' ') << std::endl;
    os << '|' << center("Head", field_size - 1) << '|' << std::endl;
    if (curr == nullptr)
        os << ' ' << std::setw(field_size) << center("--", field_size - 1) << ' ' << std::setfill(' ') << std::endl;

    while (curr != nullptr) {
        os << ' ' << std::setw(field_size) << curr << ' ' << std::setfill(' ') << std::endl;
        os << '.' << std::setw(field_size) << std::setfill('-') << '.' << std::setfill(' ') << std::endl;
        os << '|' << center(std::to_string(curr->value), field_size - 1) << '|' << std::endl;
        os << '\'' << std::setw(field_size) << std::setfill('-') << '\'' << std::setfill(' ') << std::endl;
        curr = curr->next;
        if (curr != nullptr)
            os << ' ' << std::setw(field_size) << center("|", field_size - 1) << ' ' << std::setfill(' ') << std::endl;
    }

    os << '|' << center("Tail", field_size - 1) << '|' << std::endl;
    os << '\'' << std::setw(field_size) << std::setfill('-') << '\'' << std::setfill(' ') << std::endl;
    return os;
}
