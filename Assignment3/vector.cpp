//
//  SimpleVector.cpp
//  Assignment2
//
//  Created by ritchie on 3/24/16.
//  Copyright © 2016 ritchie. All rights reserved.
//

#include "vector.h"
#include "node.h"
#include <iostream>

vector::vector(vector const& rhs)
{
    vector::operator =(rhs);
}

vector::vector(size_t const sz) : head(nullptr)
{
    Node d;
    Node* nodePtr = &d;
    for (size_t i = 0; i < sz; i++) {
        nodePtr->next = new Node;
        nodePtr = nodePtr->next;
    }
    this->head = d.next;
}

vector& vector::operator =(vector const& rhs)
{
    Node dummy;
    for (Node* r = rhs.head, *n = &dummy; r; r = r->next) {
        n->next = new Node(r);
        n = n->next;
    }
    this->head = dummy.next;
    return *this;
}

vector::~vector()
{
    Node *nodePtr = head;
    while (nodePtr != nullptr) {
        Node *nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

void vector::push_back(int const value)
{
    Node* newNode = new Node(nullptr, value);
    // If there are no nodes in the list make newNode the first node.
    if (head == nullptr) {
        head = newNode;
    } else { // Otherwise, insert newNode at end.
        Node* nodePtr = head;
        // Find the last node in the list.
        while (nodePtr->next) {
            nodePtr = nodePtr->next;
        }
        // Insert newNode as the last node.
        nodePtr->next = newNode;
    }
}

void vector::pop_back() const
{
    if (!head) {
        return;
    } else {
        Node* nodePtr = head;
        Node* previousNode = nullptr;
        while(nodePtr->next){
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        previousNode->next = nullptr;
        delete nodePtr;
    }
}

void vector::insert(const size_t pos, const int value)
{
    if (size() < pos) {
        return;
    }
    Node* newNode = new Node(value);
    // If there are no nodes in the list
    // make newNode the first node.
    if (head == nullptr) {
        head = newNode;
    } else {
        // Position nodePtr at the head of list.
        Node *nodePtr = head;
        // To point to previous node in list.
        Node *previousNode = nullptr;
        // Traverse list until position (pos) is reached
        for (size_t i = 0; i < pos; i++) {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        // Now insert new node at position (pos) with parameter value
        previousNode->next = newNode;
        newNode->next = nodePtr;
    }
}

size_t vector::size() const
{
    Node* nodePtr = head;
    size_t count = 0;
    while (nodePtr) {
        nodePtr = nodePtr->next;
        ++count;
    }
    return count;
}

void vector::displayVect()
{
    // To traverse the list.
    Node *nodePtr = head;
    while (nodePtr) {
        
        std::cout << nodePtr->value << " ";
        nodePtr = nodePtr->next;
    }
}
