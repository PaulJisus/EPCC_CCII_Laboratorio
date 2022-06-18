#include "Stack.h"

Stack::Stack()
{
    this->head = nullptr;
    this->size = 0;
}

Stack::Stack(int value)
{
    this->head = new Node(value);
    this->size = 1;
}

Stack::Stack(const Stack &o)
{
    this->head = nullptr;
    this->size = 0;
    Node *aux = o.getHead();
    while(aux)
    {
        this->push(aux->getValue());
        aux = aux->getNext();
    }
}

int Stack::getSize() const
{
    return (this->size);
}

void Stack::setHead(Node *head)
{
    this->head = head;
}

Node* Stack::getHead() const
{
    return (this->head);
}

bool Stack::empty() const
{
    return (getHead() == nullptr);
}

void Stack::push(int value)
{
    Node *aux = new Node(value);
    aux->setNext(getHead());
    setHead(aux);
    this->size++;
}

Node* Stack::top()
{
    if(empty())
    {
        throw std::invalid_argument("Empty Stack.\n");
    }
    else
    {
        return(getHead());
    }
}

Node* Stack::pop()
{
    Node* aux = getHead();
    if(empty())
    {
        throw std::invalid_argument("Empty Stack.\n");
    }
    else
    {
        setHead(getHead()->getNext());
        this->size--;
        return aux;
    }
    delete aux;
}

bool Stack::search(int value)
{
    if(empty())
    {
        throw std::invalid_argument("Empty Stack.\n");
    }
    else
    {
        Node *aux = getHead();
        while(aux)
        {
            if(aux->getValue() == value)
            {
                return true;
            }
            aux = aux->getNext();
        }
        return false;
    }
}

void Stack::clear()
{
    while(!empty())
    {
        pop();
    }
}

void Stack::print() const
{
    if(empty())
    {
        throw std::invalid_argument("Empty Stack.\n");
    }
    else
    {
        Node *aux = getHead();
        while(aux)
        {
            std::cout << aux->getValue() << " -> ";
            aux = aux->getNext();
        }
        std::cout << "NULL\n";
    }
}

Stack::~Stack()
{
    Node *aux;
    while(getHead() != nullptr)
    {
        aux = getHead()->getNext();
        delete head;
        head = aux;
    }
    delete head;
}

std::ostream& operator<< (std::ostream &output, const Stack &o)
{
    if(o.empty())
    {
        throw std::invalid_argument("Empty Stack\n");
    }
    else
    {
        Node *aux;
        for(aux = o.getHead(); aux->getNext()!= nullptr; aux = aux->getNext())
        {
            output << aux->getValue() << " -> ";
        }
        output << aux->getValue() << " -> NULL\n";
        return output;
    }
}
