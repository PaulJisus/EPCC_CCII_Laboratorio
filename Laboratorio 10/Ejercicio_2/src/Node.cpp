#include "Node.h"

Node::Node()
{
    value = 0;
    next = nullptr;
}

Node::Node(int value)
{
    this->value = value;
    this->next = nullptr;
}

void Node::setValue(const int value)
{
    this->value = value;
}

int Node::getValue() const
{
    return (this->value);
}

void Node::setNext(Node *next)
{
    this->next = next;
}

Node* Node::getNext() const
{
    return (this->next);
}

Node::~Node()
{

}
