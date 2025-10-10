/*Ian Bonifas
 *
 *
 */


#include "Sequence.h"
#include <string>


//sequence that makes empty list or list of sz amount of items
Sequence::Sequence(size_t sz) {
    //set the head and tail to null
    head=nullptr;
    tail=nullptr;
    size=sz;
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
    }else {
        SequenceNode *current= head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNodePtr;
    }
}
void Sequence::push_back(std::string item) {
    size++;
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
    size++;
    SequenceNode *newNodePtr;
    newNodePtr = new SequenceNode;

    newNodePtr->next =nullptr;
    SequenceNode *current= head;
    for (size_t i = 0; i < position; i++) {
        current = current->next;
    }
    current->next = newNodePtr;
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