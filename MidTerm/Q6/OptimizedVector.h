#ifndef LINKEDVECTOR_H
#define LINKEDVECTOR_H

#include <cstddef>
#include <iostream>

#include "Analyzer.h"

template <typename T>
class OptimizedVector
{
public:
    // constructors
    OptimizedVector()
        : head(nullptr)
        , sz(0) {}
    OptimizedVector(const size_t s);
    OptimizedVector(const OptimizedVector& rhs);
    ~OptimizedVector();

    OptimizedVector<T>& operator=(const OptimizedVector& rhs);

    // element access:
    const T& at(const size_t position) const;
    const T& operator[](const size_t position) const;

    // modifiers:
    void push_back(const T& value);
    void pop_back();
    void insert(const T& value);
    void erase(const size_t position);

    // capacity:
    size_t size() const {return sz;}

    unsigned getOp() {return opp;}

private:

    template <typename U>
    struct Node
    {
        Node()
           : next(nullptr)
           , value(0) {}

        Node(const U val)
            : next(nullptr)
            , value(val) {}

        Node(const Node<U>* node)
            : next(node->next)
            , value(node->value) {}

        Node(const Node<U>* lnk, U& val) // continue working on this
            : next(lnk)
            , value(val) {}

        Node<U> *next;
        U value;
    };

    void subError() const; // Handles memory subscripts out of range
    void swap(OptimizedVector<T>& other);

    Node<T>* head;
    size_t sz;
    unsigned opp;
};

// Class implementation

template <typename T>
void OptimizedVector<T>::insert(const T& value)
{
    opp = 0;
    Node<T> *newNode; // A new node
    Node<T> *nodePtr; // To traverse the list
    Node<T> *previousNode = nullptr; // The previous node
    // Allocate a new node and store num there.
    newNode = new Node<T>(value);

    // If there are no nodes in the list
    // make newNode the first node

    if (!head) {
        head = newNode;
        newNode->next = nullptr;
        opp++; opp++; opp++;
    }
    else // Otherwise, insert newNode
    {
        // Position nodePtr at the head of list.
        nodePtr = head;
        opp++;
        // Initialize previousNode to nullptr.
        previousNode = nullptr;
        opp++;

        // Skip all nodes whose value is less than num.
        while (nodePtr != nullptr && nodePtr->value < value)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
            opp++; opp++; opp++; opp++;
        }

        // If the new node is to be the 1st in the list,
        // insert it before all other nodes.
        if (previousNode == nullptr)
        {
            head = newNode;
            newNode->next = nodePtr;
            opp++; opp++; opp++;
        }
        else // Otherwise insert after the previous node.
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
            opp++; opp++;
        }
    }

}

template <typename T>
OptimizedVector<T>::OptimizedVector(const size_t s)
    : head(nullptr)
    , sz(s)
{
    Node<T> d;
    Node<T>* nodePtr = &d;
    for (size_t i = 0; i < sz; i++) {
        nodePtr->next = new Node<T>;
        nodePtr = nodePtr->next;
    }
    this->head = d.next;
}

template <typename T>
OptimizedVector<T>::OptimizedVector(const OptimizedVector& rhs)
    : head(nullptr)
    , sz(0)
{
    Node<T>** current = &head;

    for(Node<T>* loop = rhs.head; loop; loop = loop->next) {
        (*current) = new Node<T>(loop->value);
        current    = &(*current)->next;
        ++sz;
    }
}

template <typename T>
OptimizedVector<T>& OptimizedVector<T>::operator=(const OptimizedVector& rhs)
{
    OptimizedVector<T>  tmp(rhs);  // Copy
    tmp.swap(*this);    // Swap
    return *this;       // return
}

template <typename T>
void OptimizedVector<T>::swap(OptimizedVector<T>& other)
{
    using std::swap;
    swap(head, other.head);
    swap(sz, other.sz);
}
template <typename T>
OptimizedVector<T>::~OptimizedVector()
{
    Node<T>* nodePtr = head;
    while (nodePtr != nullptr) {
        Node<T>* nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

template <typename T>
const T& OptimizedVector<T>::at(const size_t position) const
{
    Node<T>* nodePtr = head;
    if (position < 0 || position >= this->size()) {
        subError();
    } else {

        for (size_t i = 0; i < position; i++) {
            nodePtr = nodePtr->next;
        }
    }
    return nodePtr->value;
}

template <typename T>
const T& OptimizedVector<T>::operator[](const size_t position) const{
    return at(position);
}

template <typename T>
void OptimizedVector<T>::push_back(const T& value)
{
    Node<T>* newNode = new Node<T>(value);
    // If there are no nodes in the list make newNode the first node.
    if (head == nullptr) {
        head = newNode;
    // Otherwise, insert newNode at end.
    } else {
        Node<T>* nodePtr = head;
        // Go to the last node in the list.
        while (nodePtr->next) {
            nodePtr = nodePtr->next;
        }
        // Insert newNode as the last node.
        nodePtr->next = newNode;
    }
    ++sz;
}

template <typename T>
void OptimizedVector<T>::pop_back()
{
    if (!head) {
        return;
    } else if (!head->next) {
        delete head;
        head = nullptr;
        sz = 0;
    } else {

        Node<T>* nodePtr = head;
        Node<T>* previousNode = nullptr;

        while (nodePtr->next) {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        previousNode->next = nullptr;
        delete nodePtr;
        --sz;
    }
}

template <typename T>
void OptimizedVector<T>::erase(const size_t position)
{
    if (sz <= position || head == nullptr) {
        subError();
    }
    Node<T>* nodePtr = head;
    Node<T>* previousNode = nullptr;
    // Erase first element
    if (position == 0) {
        head = nodePtr->next;
        delete nodePtr;
    // Otherwise erase element at position
    } else {
        for (size_t i = 0; i < position; i++) {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        previousNode->next = nodePtr->next;
        delete nodePtr;
    }
    --sz;
}

template <typename T>
void OptimizedVector<T>::subError() const {
    std::cout << "ERROR: Subscript out of range.\n";
        exit(EXIT_FAILURE);
}
#endif // LINKEDVECTOR_H
