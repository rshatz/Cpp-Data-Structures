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

vector::vector(vector const& rhs)
{
    vector::operator =(rhs);
}

vector& vector::operator =(vector const& rhs)
{
    Node d;
    for (Node* r = rhs.head, *n = &d; r; r = r->next) {
        n->next = new Node(r);
        n = n->next;
    }
    this->head = d.next;
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
    Node* newNode = new Node(value);
    // If there are no nodes in the list make newNode the first node.
    if (head == nullptr) {
        head = newNode;
    // Otherwise, insert newNode at end.
    } else {
        Node* nodePtr = head;
        // Go to the last node in the list.
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

void vector::insert(const size_t position, const int value)
{
    // Subscript error
    if (position > size()) {
        return;
    }
    Node* newNode = new Node(value);
    Node* nodePtr = head;
    Node* previousNode = nullptr;
    // If there are no nodes in the list than make newNode the first node.
    if (head == nullptr) {
        head = newNode;
    // Insert at beginning of list
    } else if (position == 0) {
        head = newNode;
        newNode->next = nodePtr;
    // Otherwise insert new node at position
    } else {      
        // Traverse list until position is reached
        for (size_t i = 0; i < position; i++) {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        previousNode->next = newNode;
        newNode->next = nodePtr;
//        // If newNode is the first in the list
//        if (previousNode == nullptr) {
//            head = newNode;
//            newNode->next = nodePtr;
//        // Otherwise insert new node at position
//        } else {
//            previousNode->next = newNode;
//            newNode->next = nodePtr;
//        }
    }
}

void vector::erase(const size_t position)
{
    if (size() < position || head == nullptr) {
        return;
    }
    Node* nodePtr = head;
    Node* previous = nullptr;
    for (size_t i = 0; i < position; i++) {
        previous = nodePtr;
        nodePtr = nodePtr->next;
    }
    // Erase first element
    if (previous == nullptr) {
        head = nodePtr->next;
        delete nodePtr;
    // Otherwise erase element at position
    } else {
        Node* temp = nodePtr->next;
        previous->next = temp;
        delete nodePtr;
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
    Node *nodePtr = head;
    while (nodePtr) {
        
        std::cout << nodePtr->value << " ";
        nodePtr = nodePtr->next;
    }
}
