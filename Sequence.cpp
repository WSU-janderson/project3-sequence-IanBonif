/*Ian Bonifas
 *
 *
 */


#include "Sequence.h"

#include <iostream>
#include <string>
#include <ostream>

//sequence that makes empty list or list of sz amount of items
Sequence::Sequence(size_t sz) {
    //set the head and tail to null
    head=nullptr;
    tail=nullptr;
    Size=sz;
    for (size_t i = 0; i < sz; i++) {
        //uses the function addNode to add nodes to sequence
        AddNode();

     }
}
void Sequence::AddNode() {
    SequenceNode *newNodePtr;
    newNodePtr = new SequenceNode;

    newNodePtr->next =nullptr;

    if (this->head == nullptr) {
        this->head=newNodePtr;
        this->tail=newNodePtr;
        newNodePtr->prev=nullptr;
    }else {
        SequenceNode *current= head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNodePtr;
        this->tail=newNodePtr;
        newNodePtr->prev=current;
    }
}
void Sequence::AddNode(std::string item) {
    SequenceNode *newNodePtr;
    newNodePtr = new SequenceNode;

    newNodePtr->item = item;
    newNodePtr->next =nullptr;

    if (this->head == nullptr) {
        this->head=newNodePtr;
    }else {
        SequenceNode *current= head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNodePtr;
        this->tail=newNodePtr;
        newNodePtr->prev=current;
    }
}
void Sequence::push_back(std::string item) {
    Size++;
    SequenceNode *newNodePtr;
    newNodePtr = new SequenceNode;
    newNodePtr->item =item;
    newNodePtr->next =nullptr;

    if (this->head == nullptr) {
        this->head=newNodePtr;
    }else {
        SequenceNode *current= head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNodePtr;
        this->tail=newNodePtr;
        newNodePtr->prev=current;
    }
}
std::string Sequence::back() const {
    //walks through the list
    SequenceNode *current= head;
    while (current->next != nullptr) {
        current = current->next;
    }
    //returns the last currents items
    return current->item;
}
void Sequence::insert(size_t position, std::string item) {
    Size++;
    SequenceNode *newNodePtr;
    newNodePtr = new SequenceNode;

    newNodePtr->next =nullptr;
    SequenceNode *current= head;
    for (size_t i = 0; i < position; i++) {
        current = current->next;
    }
    newNodePtr->next =current->next;
    current->next =newNodePtr;
    //current->next = newNodePtr;
    //newNodePtr->next = temp;
    newNodePtr->item = item;
}
std::string Sequence::front()const {
    SequenceNode *current= head;
    return current->item;
}
std::string& Sequence::operator[](size_t position) {
    SequenceNode *current= head;
    for (size_t i = 0; i < position; i++) {
        current = current->next;
    }
    return current->item;
}
void Sequence::clear() {
    Size=0;
    SequenceNode* current= head;
    while (current->next != nullptr) {
        SequenceNode* Destroyed= current->next;
        delete current;
        current = Destroyed;
    }
    head=nullptr;
}
 Sequence::~Sequence() {
    clear();
}
Sequence::Sequence(const Sequence& s) {
    Size=s.Size;
SequenceNode* current= s.head;
    while (current) {
        AddNode(current->item);
        current=current->next;
    }
}
Sequence& Sequence::operator=(const Sequence& s) {
    Size=s.Size;
    SequenceNode* current= s.head;
    while (current) {
        AddNode(current->item);
        current=current->next;
    }
    return *this;
}
bool Sequence::empty() const {
    if (this->head == nullptr) {
        return true;
    }else {
        return false;
    }
}
size_t Sequence::size() const {
   return Size;
}
void Sequence::pop_back() {
    Size=Size-1;
    SequenceNode *current= head;
     for (size_t i = 0; i <Size-1; i++){
        current = current->next;
    }
    this->tail=current;
    current->next=nullptr;
}
void Sequence::erase(size_t position) {
    Size=Size-1;
    size_t previous=position-1;
    size_t newPosition=position+1;
    SequenceNode *current= head;
    SequenceNode *current2=head;
    for (size_t i = 0; i < previous; i++) {
        current = current->next;
    }
    for (size_t i =0; i < newPosition; i++) {
        current2=current2->next;
    }
    current->next=current2;
}
void Sequence::erase(size_t position, size_t count) {
    Size=Size-count;
    size_t previous=position-1;
    size_t newPosition=position+count;
    SequenceNode *current= head;
    SequenceNode *current2=head;
    for (size_t i = 0; i < previous; i++) {
        current = current->next;
    }
    for (size_t i =0; i < newPosition; i++) {
        current2=current2->next;
    }
    current->next=current2;
}
void Sequence::print(std::ostream &os) {
    SequenceNode *current= head;
    os<<"(";
    while (current != nullptr) {
        os << current->item;
        if (current->next != nullptr) {
            os << ", ";
        }
        current = current->next;
    }
    os<< ")";
}