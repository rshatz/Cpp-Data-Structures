#ifndef LINKEDVECTOR_H
#define LINKEDVECTOR_H

#include <cstddef>
#include <iostream>

template <typename T>
class List
{
public:
    // constructors
    List()
        : head(nullptr)
        , sz(0) {}
    List(const size_t s);
    List(const List& rhs);
    ~List();

    List<T>& operator=(const List& rhs);

    // element access:
    const T& at(const size_t position) const;
    const T& operator[](const size_t position) const;

    // modifiers:
    void push_back(const T& value);
    void pop_back();
    void insert(const size_t position, const T& value);
    void erase(const size_t position);

    // capacity:
    size_t size() const {return sz;}

private:

    template <typename U>
    struct Node
    {
        Node()
           : link(nullptr)
           , value(0) {}

        Node(const U val)
            : link(nullptr)
            , value(val) {}

        Node(const Node<U>* node)
            : link(node->link)
            , value(node->value) {}

        Node(const Node<U>* lnk, U& val) // continue working on this
            : link(lnk)
            , value(val) {}

        Node<U> *link;
        U value;
    };

    void subError() const; // Handles memory subscripts out of range
    void swap(List<T>& other);

    Node<T> *head;
    size_t sz;
};

// Class implementation

template <typename T>
List<T>::List(const size_t s)
    : head(nullptr)
    , sz(s)
{
    Node<T> d;
    Node<T>* nodePtr = &d;
    for (size_t i = 0; i < sz; i++) {
        nodePtr->link = new Node<T>;
        nodePtr = nodePtr->link;
    }
    this->head = d.link;
}

template <typename T>
List<T>::List(const List& rhs)
    : head(nullptr)
    , sz(0)
{
    Node<T>** current = &head;

    for(Node<T>* loop = rhs.head; loop; loop = loop->link) {
        (*current) = new Node<T>(loop->value);
        current    = &(*current)->link;
        ++sz;
    }
}

template <typename T>
List<T>& List<T>::operator=(const List& rhs)
{
    List<T>  tmp(rhs);  // Copy
    tmp.swap(*this);    // Swap
    return *this;       // return
}

template <typename T>
void List<T>::swap(List<T>& other)
{
    using std::swap;
    swap(head, other.head);
    swap(sz, other.sz);
}
template <typename T>
List<T>::~List()
{
    Node<T>* nodePtr = head;
    while (nodePtr != nullptr) {
        Node<T>* nextNode = nodePtr->link;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

template <typename T>
const T& List<T>::at(const size_t position) const
{
    Node<T>* nodePtr = head;
    if (position < 0 || position >= this->size()) {
        subError();
    } else {

        for (size_t i = 0; i < position; i++) {
            nodePtr = nodePtr->link;
        }
    }
    return nodePtr->value;
}

template <typename T>
const T& List<T>::operator[](const size_t position) const{
    return at(position);
}

template <typename T>
void List<T>::push_back(const T& value)
{
    Node<T>* newNode = new Node<T>(value);
    // If there are no nodes in the list make newNode the first node.
    if (head == nullptr) {
        head = newNode;
    // Otherwise, insert newNode at end.
    } else {
        Node<T>* nodePtr = head;
        // Go to the last node in the list.
        while (nodePtr->link) {
            nodePtr = nodePtr->link;
        }
        // Insert newNode as the last node.
        nodePtr->link = newNode;
    }
    ++sz;
}

template <typename T>
void List<T>::pop_back()
{
    if (!head) {
        return;
    } else if (!head->link) {
        delete head;
        head = nullptr;
        sz = 0;
    } else {

        Node<T>* nodePtr = head;
        Node<T>* previousNode = nullptr;

        while (nodePtr->link) {
            previousNode = nodePtr;
            nodePtr = nodePtr->link;
        }
        previousNode->link = nullptr;
        delete nodePtr;
        --sz;
    }
}

template <typename T>
void List<T>::insert(const size_t position, const T& value)
{
    if (position > sz) {
        subError();
    }

    Node<T>* newNode = new Node<T>(value);
    Node<T>* nodePtr = head;
    Node<T>* previousNode = nullptr;

    if (head == nullptr) {
        head = newNode;
    // Insert at beginning of list
    } else if (position == 0) {
        head = newNode;
        newNode->link = nodePtr;
    // Otherwise insert new node at given position
    } else {
        for (size_t i = 0; i < position; i++) {
            previousNode = nodePtr;
            nodePtr = nodePtr->link;
        }
        previousNode->link = newNode;
        newNode->link = nodePtr;
    }
    ++sz;
}

template <typename T>
void List<T>::erase(const size_t position)
{
    if (sz <= position || head == nullptr) {
        subError();
    }
    Node<T>* nodePtr = head;
    Node<T>* previousNode = nullptr;
    // Erase first element
    if (position == 0) {
        head = nodePtr->link;
        delete nodePtr;
    // Otherwise erase element at position
    } else {
        for (size_t i = 0; i < position; i++) {
            previousNode = nodePtr;
            nodePtr = nodePtr->link;
        }
        previousNode->link = nodePtr->link;
        delete nodePtr;
    }
    --sz;
}

template <typename T>
void List<T>::subError() const {
    std::cout << "ERROR: Subscript out of range.\n";
        exit(EXIT_FAILURE);
}
#endif // LINKEDVECTOR_H
