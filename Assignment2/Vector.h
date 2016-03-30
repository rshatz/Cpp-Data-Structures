
// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include "node.h"

class Vector
{
    
public:
    
    Vector() : head(nullptr){}

    Vector(Vector const& rhs);
    ~Vector();
    
    void appendNode(int const value);
    void insertNode(int const value);
    void displayVect();
    
private:
    
    Node *head;
    
};

#endif // SIMPLEVECTOR_H
