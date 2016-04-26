#ifndef LISTVECTOR_H
#define LISTVECTOR_H

#include <iostream>

template<typename T>
class ListVector {

public:

    ListVector()
        : first(nullptr)
        , last(nullptr)
        , sz(0) {}

    void sorted_push(const T& v);

    void push_back(const T& v);  // insert v at end
    void push_front(const T& v); // insert v at front

    const T& at(const size_t position) const;
    size_t size() const {return sz;}

private:

    template<typename Elem>
    struct Link {

        Link()
            : value(0)
            , prev(nullptr)
            , next(nullptr) {}

        Link(Elem value)
            : value(value)
            , prev(nullptr)
            , next(nullptr) {}

        Link(Elem value, Link* prev, Link* next)
            : value(value)
            , prev(prev)
            , next(next) {}

        Elem value; // the value
        Link* prev; // previous link
        Link* next; // successor (next) link
    };

    void subError() const; // Handles memory subscripts out of range

    Link<T>* first;
    Link<T>* last;

    size_t sz;
};

template<typename T>
void ListVector<T>::sorted_push(const T &v)
{
    Link<T>* newNode = new Link<T>(v);
    sz++;

    if(!first) {
        first = newNode;
        std::cout << newNode->value << " \n";
    } else {

        Link<T>* nodePtr = first;
        while (nodePtr != nullptr && nodePtr->value < v) {
            nodePtr = nodePtr->next;
        }
        if (nodePtr) { // nodePtr did not reach end of the list

            std::cout << newNode->value << " \n";
            newNode->next = nodePtr;
            newNode->prev = nodePtr->prev;
            nodePtr->prev = newNode;

        } else { // nodePtr reached the end of the list

            std::cout << newNode->value << "\n";
            nodePtr = newNode;
            newNode->prev = nodePtr;
            last = newNode;
        }
    }
}

template<typename T>
void ListVector<T>::push_back(const T &v)
{
    Link<T>* newNode = new Link<T>(v);
    sz++;
    if (last) {
        newNode->prev = last; // The node currently last in the list is now pointed to by the new node's previous.
        last->next = newNode; // The node currently last in the list now points to the new node,
        last = newNode;       // The new node now is pointed to by last. New node is at the end of the list.
    } else {                  // Else there are 0 nodes in the list. The new node is now the first in the list.
        first = last = newNode;
    }
}

template<typename T>
void ListVector<T>::push_front(const T &v)
{
    Link<T>* newNode = new Link<T>(v);
    sz++;
    if (first) {
        newNode->next = first;
        first = newNode;
    } else {
        first = last = newNode;
    }
}

template<typename T>
const T& ListVector<T>::at(const size_t position) const
{
    Link<T>* nodePtr = first;

    if (position < 0 || position >= size()) {
        subError();
    } else {
        for (size_t i = 0; i < position; i++) {
            nodePtr = nodePtr->next;
        }
    }
    return nodePtr->value;
}

template <typename T>
void ListVector<T>::subError() const {
    std::cout << "ERROR: Subscript out of range.\n";
        exit(EXIT_FAILURE);
}
#endif // LISTVECTOR_H
