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

vector::vector(vector const& rhs) : head(nullptr){//, node(new Node(head)){

//    Node** tailPtr = &this->head;

//    for(Node* list = rhs.head; list != nullptr; list = list->next){
//        (*tailPtr) = new Node(*list);
//        tailPtr = &((*tailPtr)->next);
//    }

    this->node = head;

    for(Node* list = rhs.head; list != nullptr; list = list->next){

        node = new Node(*list);
        std::cout << node << std::endl;
        node = node->next;
        //std::cout << list->value << " " ;
        //std::cout << node << " " << list << "\n";
    }
    node = head;


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

void vector::appendNode(int const value)
{  
    Node *newNode = new Node(value, nullptr);
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

void vector::insertNode(int const value)
{ 
    Node *newNode = new Node(value, nullptr);
    // If there are no nodes in the list
    // make newNode the first node.
    if(head == nullptr){

        head = newNode;
    }
    else{

        // To traverse the list. Position nodePtr at the head of list.
        Node *nodePtr = head;
        // To point to previous node in list.
        Node *previousNode = nullptr;
        
        // Skip all nodes whose value is less than the parameter value.
        while((nodePtr != nullptr) && (nodePtr->value < value)){
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        // If the new node is to be the 1st in the list
        // insert it before all other nodes.
        if(previousNode == nullptr){
            newNode->next = nodePtr;
            head = newNode;
        }
        // Otherwise insert after the previous node.
        else{
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
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
