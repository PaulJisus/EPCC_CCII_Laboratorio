#include "Node.h"

Node::Node()
{
    this->value = value;
    this->next = nullptr;
}

Node::Node(Producto value)
{
    this->value = value;
    this->next = nullptr;
}

void Node::setValue(const Producto value)
{
    this->value = value;
}

Producto Node::getValue() const
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

std::ostream& operator<<(std::ostream &output, const Node &o)
{
    output << o.getValue();
    return output;
}
