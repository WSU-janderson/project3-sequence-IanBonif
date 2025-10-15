/*Ian Bonifas
 *Project 3
*CS 3100
 *10/15/25
*/


#include "Sequence.h"

#include <iostream>
#include <string>
#include <ostream>
#include <exception>

//sequence that makes empty list or list of sz amount of items
Sequence::Sequence(size_t sz) {
    //set the head and tail to null
    head = nullptr;
    tail = nullptr;
    Size = sz;
    for (size_t i = 0; i < sz; i++) {
        //uses the function addNode to add nodes to sequence
        AddNode();
    }
}

void Sequence::AddNode() {
    //creates node and node ptr
    SequenceNode *newNodePtr;
    newNodePtr = new SequenceNode;
    //clears node ptr next
    newNodePtr->next = nullptr;
    //makes first node
    if (this->head == nullptr) {
        this->head = newNodePtr;
        this->tail = newNodePtr;
        newNodePtr->prev = nullptr;
    } else {
        //walks down sequence
        SequenceNode *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        //creates new node
        current->next = newNodePtr;
        this->tail = newNodePtr;
        newNodePtr->prev = current;
    }
}

void Sequence::AddNode(std::string item) {
    //creates new node and ptr
    SequenceNode *newNodePtr;
    newNodePtr = new SequenceNode;

    //add item to node and clears its next
    newNodePtr->item = item;
    newNodePtr->next = nullptr;

    if (this->head == nullptr) {
        //creates first node
        this->head = newNodePtr;
    } else {
        //walks down list
        SequenceNode *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        //creates new node
        current->next = newNodePtr;
        this->tail = newNodePtr;
        newNodePtr->prev = current;
    }
}

void Sequence::push_back(std::string item) {
    //adds to Size
    Size++;
    //creates node and ptr
    SequenceNode *newNodePtr;
    newNodePtr = new SequenceNode;
    //adds item to node
    newNodePtr->item = item;
    newNodePtr->next = nullptr;
    //adds to head if null
    if (this->head == nullptr) {
        this->head = newNodePtr;
    } else {
        //walks down linked list
        SequenceNode *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        //sets up new node
        current->next = newNodePtr;
        this->tail = newNodePtr;
        newNodePtr->prev = current;
    }
}

std::string Sequence::back() const {
    //walks through the list
    SequenceNode *current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    //returns the last currents items
    return current->item;
}

void Sequence::insert(size_t position, std::string item) {
    //adds to Size
    Size++;
    //creates new node and ptr
    SequenceNode *newNodePtr;
    newNodePtr = new SequenceNode;
    //clears next in ptr
    newNodePtr->next = nullptr;
    //walks through linked list
    SequenceNode *current = head;
    for (size_t i = 0; i < position; i++) {
        current = current->next;
    }
    //sets up node
    newNodePtr->prev = current;
    newNodePtr->next = current->next;
    current->next = newNodePtr;

    //current->next = newNodePtr;
    //newNodePtr->next = temp;
    newNodePtr->item = item;
}

std::string Sequence::front() const {
    //gets front
    SequenceNode *current = head;
    //returns fronts item
    return current->item;
}

std::string &Sequence::operator[](size_t position) {
    //error handling if out of bounds
    if (position > Size - 1) {
        throw std::exception();
    }
    //walks to position
    SequenceNode *current = head;
    for (size_t i = 0; i < position; i++) {
        current = current->next;
    }
    //returns item and position
    return current->item;
}

void Sequence::clear() {
    //sets size to 0
    Size = 0;
    //walks through linked list and destroys it
    SequenceNode *current = head;
    while (current->next != nullptr) {
        SequenceNode *Destroyed = current->next;
        delete current;
        current = Destroyed;
    }
    head = nullptr;
}

//uses clear function to destroy list
Sequence::~Sequence() {
    clear();
}

Sequence::Sequence(const Sequence &s) {
    //sets s.Size to Size
    Size = s.Size;
    //walks through and copy linked list
    SequenceNode *current = s.head;
    while (current) {
        AddNode(current->item);
        current = current->next;
    }
}

Sequence &Sequence::operator=(const Sequence &s) {
    //s.Size to equal Size
    Size = s.Size;
    //walks through list and copy list
    SequenceNode *current = s.head;
    while (current) {
        AddNode(current->item);
        current = current->next;
    }
    //returns new links ref
    return *this;
}

bool Sequence::empty() const {
    //checks if head is null and returns true
    if (this->head == nullptr) {
        return true;
    } else {
        return false;
    }
}

size_t Sequence::size() const {
    //returns Size
    return Size;
}

void Sequence::pop_back() {
    //takes 1 away from size
    Size = Size - 1;
    //walks to second from end of list
    SequenceNode *current = head;
    for (size_t i = 0; i < Size - 1; i++) {
        current = current->next;
    }
    //deletes last node
    this->tail = current;
    current->next = nullptr;
}

void Sequence::erase(size_t position) {
    //error handling if out of bounds
    if (position > Size - 1) {
        throw std::exception();
    }
    //minus 1 from Size
    Size = Size - 1;
    //used for loops
    size_t previous = position - 1;
    size_t newPosition = position + 1;
    //creates 2 ptrs
    SequenceNode *current = head;
    SequenceNode *current2 = head;
    //walks to one before list
    for (size_t i = 0; i < previous; i++) {
        current = current->next;
    }
    //walks to one after positon
    for (size_t i = 0; i < newPosition; i++) {
        current2 = current2->next;
    }
    //erases the node
    current->next = current2;
}

void Sequence::erase(size_t position, size_t count) {
    //error handling for out of bounds
    if (position > Size - 1 || count + position > Size - 1) {
        throw std::exception();
    }
    //takes away how many node are deleted from Size
    Size = Size - count;
    //used in loops
    size_t previous = position - 1;
    size_t newPosition = position + count;
    SequenceNode *current = head;
    SequenceNode *current2 = head;
    //walks to one before erased ones
    for (size_t i = 0; i < previous; i++) {
        current = current->next;
    }
    //walks to one after
    for (size_t i = 0; i < newPosition; i++) {
        current2 = current2->next;
    }
    //erases the nodes
    current->next = current2;
}

void Sequence::print(std::ostream &os) {
    //walks through and prints all items
    SequenceNode *current = head;
    os << "(";
    while (current != nullptr) {
        os << current->item;
        if (current->next != nullptr) {
            os << ", ";
        }
        current = current->next;
    }
    os << ")";
}
