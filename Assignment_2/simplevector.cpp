//
//  SimpleVector.cpp
//  Assignment2
//
//  Created by ritchie on 3/24/16.
//  Copyright © 2016 ritchie. All rights reserved.
//

#include "SimpleVector.h"
#include <iostream>

SimpleVector::~SimpleVector()
{
    Node *nodePtr = head;
    while(nodePtr != nullptr){

        Node *nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

void SimpleVector::appendNode(int value)
{
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;

    Node *nodePtr = head;
    if(head == nullptr){
        head = newNode;
    }
    else{

        nodePtr = head;
        while(nodePtr->next){

            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;
    }
}

void SimpleVector::insertNode(int value)
{
    Node *newNode;
    Node *nodePtr;
    Node *previousNode;

    newNode = new Node;
    newNode->value = value;

    // If there are no nodes in the list
    // make newNode the first node.
    if(head == nullptr){
        head = newNode;
        newNode->next = nullptr;
    }
    else{
        // Position nodePtr at the head of list.
        nodePtr = head;

        // Initialize previousNode to nullptr.
        previousNode = nullptr;

        // Skip all nodes whose value is less than value.
        while((nodePtr != nullptr) && (nodePtr->value < value)){
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        // If the new node is to be the 1st in the list
        // insert it before all other nodes.
        if(previousNode == nullptr){
            head = newNode;
            newNode->next = nodePtr;
        }
        // Otherwise insert after the previous node.
        else{
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

void SimpleVector::displayVect()
{
    Node *nodePtr = head;
    while(nodePtr){

        std::cout << nodePtr->value << " ";
        nodePtr = nodePtr->next;
    }
}
