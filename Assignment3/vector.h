
// SimpleVector class template
#ifndef VECTOR_H
#define VECTOR_H

#include "node.h"
#include <cstddef>
#include <iostream>

template <typename T>
class vector
{   
public:
    // constructors
    vector() : head(nullptr), sz(0) {}
    vector(const size_t s);
    vector(const vector& rhs);
    ~vector();

    vector<T>& operator=(const vector& rhs);

    // element access:
    T at(const size_t position);
    T operator[](const size_t position);

    // modifiers:
    void push_back(const T value);
    void pop_back();
    void insert(const size_t position, const T value);
    void erase(const size_t position);

    // capacity:
    size_t size() const {return sz;}

private:
    
    void subError(); // Handles memory subscripts out of range

    Node<T> *head;
    size_t sz;
};

// Class implementation

template <typename T>
vector<T>::vector(size_t const s) : head(nullptr), sz(s)
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
vector<T>::vector(const vector& rhs)
{
    vector::operator =(rhs);
}

template <typename T>
vector<T>& vector<T>::operator=(const vector& rhs)
{
    sz = rhs.sz;
    Node<T> d;
    for (Node<T>* r = rhs.head, *n = &d; r; r = r->next) {
        n->next = new Node<T>(r);
        n = n->next;
    }
    this->head = d.next;
    return *this;
}

template <typename T>
vector<T>::~vector()
{
    Node<T>* nodePtr = head;
    while (nodePtr != nullptr) {
        Node<T>* nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

template <typename T>
T vector<T>::at(const size_t position)
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
T vector<T>::operator[](const size_t position) {
    return at(position);
}

template <typename T>
void vector<T>::push_back(const T value)
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
void vector<T>::pop_back()
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
void vector<T>::insert(const size_t position, const T value)
{
    if (position > sz) {
        subError();
    }

    Node<T>* newNode = new Node<T>(value);
    Node<T>* nodePtr = head;
    Node<T>* previousNode = nullptr;

    if (head == nullptr) {
        head = newNode;
    // Insert at beginning of list
    } else if (position == 0) {
        head = newNode;
        newNode->next = nodePtr;
    // Otherwise insert new node at given position
    } else {
        for (size_t i = 0; i < position; i++) {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        previousNode->next = newNode;
        newNode->next = nodePtr;
    }
    ++sz;
}

template <typename T>
void vector<T>::erase(const size_t position)
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
void vector<T>::subError() {
    std::cout << "ERROR: Subscript out of range.\n";
        exit(EXIT_FAILURE);
}

#endif // VECTOR_H
