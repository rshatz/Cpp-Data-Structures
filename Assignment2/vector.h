
// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include "node.h"
#include <cstddef>

class vector
{   
public:
    
    vector() : head(nullptr){}
    vector(size_t const) : head(nullptr){}

    vector(vector const& rhs);
    ~vector();

    vector& operator=(vector const& rhs);
    // modifiers:
    void push_back(int const value);
    void pop_back() const;
    void insertNode(int const value);
    // capacity
    size_t size() const;
    // display vector - to be deleted
    void displayVect();
    
private:
    
    Node *head;

};

#endif // SIMPLEVECTOR_H
