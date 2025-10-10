
#ifndef SEQUENCE_H
#define SEQUENCE_H

//need to include string
#include <string>

//this was taken from the project pdf
class SequenceNode {
public: // to make it easier, we can make the data members public so we don't need
    // getters and setters
    SequenceNode* next; // pointer to next Node. If node is the tail, next is
    // nullptr
    SequenceNode* prev; // pointer to previous Node. If node is the head, prev is
    // nullptr
    std::string item; // the element being stored in the node
    //default constructor, ensure next and prev are nullptr
    SequenceNode() : next(nullptr), prev(nullptr)
    {}
    /// parameterized constructor, next and prev are set to nullptr and the
    /// node's element is set to the given value
    SequenceNode(std::string item) : next(nullptr), prev(nullptr), item(item)
    {}

};

//creates class Sequence
class Sequence {
public:
    //head for the double linked list
    SequenceNode* head;
    //tail for the double linked list
    SequenceNode* tail;
    //amount of items
    size_t size;

    Sequence() : head(nullptr), tail(nullptr), size(0) {}
    //builds the linked list of size sz
    Sequence(size_t sz);
    void AddNode();
    void push_back(std::string item) ;
    std::string back() const;
    void insert(size_t position, std::string item);
    std::string front() const;
    std::string& operator[](size_t position);
};



#endif