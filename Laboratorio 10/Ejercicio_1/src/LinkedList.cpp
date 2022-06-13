#include "LinkedList.h"

LinkedList::LinkedList()
{
    this->head = nullptr;
    this->size = 0;
}

LinkedList::LinkedList(int value)
{
    this->head = new Node(value);
    this->size = 1;
}

int LinkedList::getSize() const
{
    return size;
}

void LinkedList::setHead(Node * head)
{
    this->head = head;
}

Node* LinkedList::getHead() const
{
    return (this->head);
}

bool LinkedList::empty() const
{
    return (getHead() == nullptr);
}

Node *LinkedList::front() const
{
    if(empty())
    {
        throw std::invalid_argument("Lista Vacia\n");
    }
    else
    {
        return(getHead());
    }
}

Node *LinkedList::back() const
{
    if(empty())
    {
        throw std::invalid_argument("Lista Vacia\n");
    }
    else
    {
        Node *tmp = getHead();
        while(tmp->getNext() != nullptr)
        {
            tmp = tmp->getNext();
        }
        return(tmp);
    }
}

void LinkedList::push_back(int value)
{
    Node *aux = new Node(value);
    if(empty())
    {
        setHead(aux);
        size ++;
        return;
    }
    else
    {
        Node *tmp = getHead();
        while(tmp->getNext() != nullptr)
        {
            tmp = tmp->getNext();
        }
        tmp->setNext(aux);
        size++;
    }
}

bool LinkedList::search(int value)
{
    bool flag{};
    if(empty())
    {
        flag = false;
    }
    else
    {
        Node *aux = getHead();
        while(aux->getNext() != nullptr && flag != true)
        {
            if(aux->getValue() == value)
            {
                flag = true;
            }
            else
            {
                aux = aux->getNext();
            }
        }
    }
    return flag;
}

void LinkedList::pop_front()
{
    if(empty())
    {
        throw std::invalid_argument("Lista Vacia\n");
    }
    else
    {
        Node *aux = getHead();
        setHead(getHead()->getNext());
        size--;
        delete aux;
    }
}

void LinkedList::remove(int value)
{
    if(empty())
    {
        throw std::invalid_argument("Lista Vacia\n");
    }
    else
    {
        Node *aux = getHead();
        Node *tmp = nullptr;
        while(aux != nullptr)
        {
            if(getHead()->getValue() == value)
            {
                pop_front();
            }
            else if(aux->getNext() != nullptr && aux->getNext()->getValue() == value)
            {
                tmp = aux->getNext();
                aux->setNext(tmp->getNext());
                delete tmp;
                size--;
            }
            else
            {
                aux = aux->getNext();
            }
        }
        delete aux;
    }
}

void LinkedList::clear()
{
    while(!empty())
    {
        pop_front();
    }
}

LinkedList::~LinkedList()
{
    clear();
}

std::ostream& operator<<(std::ostream &output, const LinkedList &o)
{
    if(o.empty())
    {
        throw std::invalid_argument("Lista Vacia\n");
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
