
// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include "node.h"
#include <cstddef>
#include <iostream>

template <typename T>
class vector
{   
public:
    // constructors
    vector() : head(nullptr) {}
    vector(const size_t sz);
    vector(const vector& rhs);
    ~vector();

    vector<T> &operator =(const vector& rhs);

    // modifiers:
    void push_back(const T value);
    void pop_back();
    void insert(const size_t position, const T value);
    void erase(const size_t position);

    // capacity
    size_t size() const;

    void displayVect();// display vector is for testing only - will be deleted
    
private:
    
    Node<T> *head;
};

// Class implementation

template <typename T>
vector<T>::vector(size_t const sz) : head(nullptr)
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
vector<T>& vector<T>::operator =(const vector& rhs)
{
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
void vector<T>::push_back(T const value)
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
}

template <typename T>
void vector<T>::pop_back()
{
    if (!head) {
        return;
    } else if (!head->next) {
        delete head;
        head = nullptr;
    } else {
        Node<T>* nodePtr = head;
        Node<T>* previousNode = nullptr;
        while(nodePtr->next) {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        previousNode->next = nullptr;
        delete nodePtr;
    }
}

template <typename T>
void vector<T>::insert(const size_t position, const T value)
{
    // Subscript error
    if (position > size()) {
        return;
    }
    Node<T>* newNode = new Node<T>(value);
    Node<T>* nodePtr = head;
    Node<T>* previousNode = nullptr;
    // If there are no nodes in the list than make newNode the first node.
    if (head == nullptr) {
        head = newNode;
    // Insert at beginning of list
    } else if (position == 0) {
        head = newNode;
        newNode->next = nodePtr;
    // Otherwise insert new node at given position
    } else {
        // Traverse list until position is reached
        for (size_t i = 0; i < position; i++) {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        previousNode->next = newNode;
        newNode->next = nodePtr;
    }
}

template <typename T>
void vector<T>::erase(const size_t position)
{
    if (size() < position || head == nullptr) {
        return;
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
}

template <typename T>
size_t vector<T>::size() const
{
    Node<T>* nodePtr = head;
    size_t count = 0;
    while (nodePtr) {
        nodePtr = nodePtr->next;
        ++count;
    }
    return count;
}

template <typename T>
void vector<T>::displayVect()
{
    Node<T>* nodePtr = head;
    while (nodePtr) {
        std::cout << nodePtr->value << " ";
        nodePtr = nodePtr->next;
    }
    std::cout << std::endl;
}

#endif // SIMPLEVECTOR_H
