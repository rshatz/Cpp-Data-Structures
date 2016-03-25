
// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

class SimpleVector
{

public:

    SimpleVector(){
        head = nullptr;
    }
    ~SimpleVector();

    void appendNode(int value);
    void insertNode(int value);
    void displayVect();

private:

    struct Node
    {
        int value;
        Node *next;
    };

    Node *head;

};

#endif // SIMPLEVECTOR_H
