#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node
{
    Node(): next(nullptr), value(0) {}
    Node(const T val) : next(nullptr), value(val) {}
    Node(const Node<T>* node) : next(node->next), value(node->value) {}

    Node<T> *next;
    T value;
};

#endif // NODE_H
