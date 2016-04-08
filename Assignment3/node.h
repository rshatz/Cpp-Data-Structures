#ifndef NODE_H
#define NODE_H

struct Node
{
    Node(): next(nullptr), value(0) {}
    Node(const int v) : next(nullptr), value(v) {}
    //Node(Node* n, const int v) : next(n), value(v) {}
    Node(const Node* node) : next(node->next), value(node->value) {}

    Node *next;
    int value;
};

#endif // NODE_H
