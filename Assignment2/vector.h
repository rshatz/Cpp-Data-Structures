
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
    
    void appendNode(int const value);
    void insertNode(int const value);
    void displayVect();
    
private:
    
    Node *head;
    Node *node;
    
};

#endif // SIMPLEVECTOR_H
