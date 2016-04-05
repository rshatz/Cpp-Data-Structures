
// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include "node.h"

class vector
{
    
public:
    
    vector() : head(nullptr){}

    vector(vector const& rhs);
    ~vector();
    
    vector& operator=(vector const& rhs);
    // modifiers:
    void push_back(int const value);
    void pop_back();
    void insertNode(int const value);
    void displayVect();
    
private:
    
    Node *head;
};

#endif // SIMPLEVECTOR_H
