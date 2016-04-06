
// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include "node.h"
#include <cstddef>

class vector
{   
public:
    // constructors
    vector() : head(nullptr){}
    vector(size_t const sz);
    vector(vector const& rhs);
    ~vector();

    vector& operator=(vector const& rhs);
    // modifiers:
    void push_back(int const value);
    void pop_back() const;
    void insertNode(int const value);
    // capacity
    size_t size() const;

    void displayVect();// display vector is for testing only - will be deleted
    
private:
    
    Node *head;
};

#endif // SIMPLEVECTOR_H
