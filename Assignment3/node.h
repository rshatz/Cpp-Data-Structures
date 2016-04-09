#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node
{
    Node(): next(nullptr), value(0) {}
    Node(const T v) : next(nullptr), value(v) {}
    Node(const Node<T>* node) : next(node->next), value(node->value) {}

    Node<T> *next;
    T value;
};

#endif // NODE_H
