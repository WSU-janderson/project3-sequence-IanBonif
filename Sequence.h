/*Ian Bonifas
 *Project 3
 *CS 3100
 *10/15/25
 */
#ifndef SEQUENCE_H
#define SEQUENCE_H

//need to include string
#include <string>

//this was taken from the project pdf
class SequenceNode {
public: // to make it easier, we can make the data members public so we don't need
    // getters and setters
    SequenceNode *next; // pointer to next Node. If node is the tail, next is
    // nullptr
    SequenceNode *prev; // pointer to previous Node. If node is the head, prev is
    // nullptr
    std::string item; // the element being stored in the node
    //default constructor, ensure next and prev are nullptr
    SequenceNode() : next(nullptr), prev(nullptr) {
    }

    /// parameterized constructor, next and prev are set to nullptr and the
    /// node's element is set to the given value
    SequenceNode(std::string item) : next(nullptr), prev(nullptr), item(item) {
    }
};

//creates class Sequence
class Sequence {
public:
    //head for the double linked list
    SequenceNode *head;
    //tail for the double linked list
    SequenceNode *tail;
    //amount of items
    size_t Size;

    Sequence() : head(nullptr), tail(nullptr), Size(0) {
    }

    //builds the linked list of size sz
    //returns size
    Sequence(size_t sz);

    Sequence(const Sequence &s);

    //adds node
    void AddNode();

    //adds node with item
    void AddNode(std::string item);

    //changes last item
    void push_back(std::string item);

    //gets last item
    std::string back() const;

    //inserts at position
    void insert(size_t position, std::string item);

    //gets first item
    std::string front() const;

    //overloads to be able to use it like an array
    std::string &operator[](size_t position);

    //clears list
    void clear();

    //makes copy
    Sequence &operator=(const Sequence &s);

    //clears list
    ~Sequence();

    //checks if empty
    bool empty() const;

    //returns Size
    size_t size() const;

    //deletes last item
    void pop_back();

    //erases position
    void erase(size_t position);

    //erases position to count
    void erase(size_t position, size_t count);

    //printer for ostream
    void print(std::ostream &os);

    //printer for ostream
    friend std::ostream &operator<<(std::ostream &os, Sequence &s) {
        s.print(os);
        return os;
    }
};


#endif
