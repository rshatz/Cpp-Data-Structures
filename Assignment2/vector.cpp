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

vector::vector(vector const& rhs){

    vector::operator =(rhs);
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
    while(nodePtr != nullptr){

        Node *nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

void vector::push_back(int const value)
{  
    Node *newNode = new Node(nullptr, value);
    // If there are no nodes in the list make newNode the first node.
    if(head == nullptr){

        head = newNode;
    }
    else{// Otherwise, insert newNode at end.       
        Node *nodePtr = head;
        // Find the last node in the list.
        while(nodePtr->next){    
            nodePtr = nodePtr->next;
        }
        // Insert newNode as the last node.
        nodePtr->next = newNode;
    }
}

void vector::pop_back()
{
    if(!head){
        return;
    }
    else{
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

void vector::insertNode(int const value)
{ 
//    Node *newNode = new Node(value);
//    // If there are no nodes in the list
//    // make newNode the first node.
//    if(head == nullptr){

//        head = newNode;
//    }
//    else{

//        // To traverse the list. Position nodePtr at the head of list.
//        Node *nodePtr = head;
//        // To point to previous node in list.
//        Node *previousNode = nullptr;
        
//        // Skip all nodes whose value is less than the parameter value.
//        while((nodePtr != nullptr) && (nodePtr->value < value)){
//            previousNode = nodePtr;
//            nodePtr = nodePtr->next;
//        }
//        // If the new node is to be the 1st in the list
//        // insert it before all other nodes.
//        if(previousNode == nullptr){
//            newNode->next = nodePtr;
//            head = newNode;
//        }
//        // Otherwise insert after the previous node.
//        else{
//            previousNode->next = newNode;
//            newNode->next = nodePtr;
//        }
//    }
}

void vector::displayVect()
{
    // To traverse the list.
    Node *nodePtr = head;
    while(nodePtr){
        
        std::cout << nodePtr->value << " ";
        nodePtr = nodePtr->next;
    }
}
