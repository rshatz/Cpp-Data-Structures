
// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include "node.h"
#include <cstddef>

class vector
{   
public:
    // constructors
    vector() : head(nullptr) {}
    vector(const size_t sz);
    vector(const vector& rhs);
    ~vector();

    vector& operator=(vector const& rhs);

    // modifiers:
    void push_back(const int value);
    void pop_back() const;
    void insert(const size_t position, const int value);
    void erase(const size_t position);

    // capacity
    size_t size() const;

    void displayVect();// display vector is for testing only - will be deleted
    
private:
    
    Node *head;
};

#endif // SIMPLEVECTOR_H
