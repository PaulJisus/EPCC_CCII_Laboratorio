#include "Node.h"

Node::Node()
{
    value = 0;
    next = nullptr;
}

Node::Node(int value)
{
    this->value = value;
    next = nullptr;
}

void Node::setValue(int value)
{
    this->value = value;
}

int Node::getValue()
{
    return value;
}

void Node::setNext(Node *next)
{
    this->next = next;
}

Node* Node::getNext()
{
    return next;
}

Node::~Node()
{
    delete next;
}

