#ifndef NODE_H
#define NODE_H

struct Node
{
    Node() : next(nullptr), value(0) {}
    Node(int const v, Node* const n) : next(n), value(v){}
    Node(Node* const node) : next(node->next), value(node->value){}

    Node *next;
    int value;
};

#endif // NODE_H
