#ifndef __NODE_H_
#define __NODE_H_

#include <iostream>

template<typename T>
class Node;

template <typename T>
std::ostream& operator<<(std::ostream &, const Node<T> &);

template <typename T>
class Node
{
    public:
        Node();
        Node(T);
        void setValue(const T);
        T getValue() const;
        void setNext(Node *);
        Node *getNext() const;
        ~Node();
    private:
        T value;
        Node<T> *next;
};

template <typename T>
Node<T>::Node()
{
    value = 0;
    next = nullptr;
}

template <typename T>
Node<T>::Node(T value)
{
    this->value = value;
    this->next = nullptr;
}

template <typename T>
void Node<T>::setValue(const T value)
{
    this->value = value;
}

template <typename T>
T Node<T>::getValue() const
{
    return (this->value);
}

template <typename T>
void Node<T>::setNext(Node *next)
{
    this->next = next;
}

template <typename T>
Node<T>* Node<T>::getNext() const
{
    return (this->next);
}

template <typename T>
Node<T>::~Node()
{

}

template <typename T>
std::ostream& operator<<(std::ostream &output, const Node<T> &o)
{
    output << o.getValue();
    return output;
}

#endif
