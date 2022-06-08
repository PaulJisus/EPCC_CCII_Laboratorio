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

int LinkedList::front() const
{
    if(empty())
    {
        throw std::invalid_argument("Lista Vacia");
    }
    else
    {
        return(getHead()->getValue());
    }
}

int LinkedList::back() const
{
    if(empty())
    {
        throw std::invalid_argument("Lista Vacia");
    }
    else
    {
        Node *tmp = getHead();
        while(tmp->getNext() != nullptr)
        {
            tmp = tmp->getNext();
        }
        return(tmp->getValue());
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

void LinkedList::push_front(int value)
{
    Node *aux = new Node(value);
    aux->setNext(getHead());
    setHead(aux);
    size++;
}

void LinkedList::insert(int pos, int value)
{
    if(pos >= 0 && pos <= size - 1)
    {
        if(pos == 0)
        {
            push_front(value);
        }
        else if(pos == getSize()- 1)
        {
            push_back(value);
        }
        else
        {
            Node *tmp = getHead();
            Node *tmp1 = nullptr;
            while(pos >= 0)
            {
                tmp1 = tmp;
                tmp = tmp->getNext();
                pos--;
            }
            Node *aux = new Node(value);
            tmp1->setNext(aux);
            aux->setNext(tmp);
            size++;
        }
    }
    else
    {
        throw std::invalid_argument("Posicion invalida en la lista.");
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
        throw std::invalid_argument("Lista Vacia");
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
        throw std::invalid_argument("Lista Vacia");
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
    Node *aux;
    for(aux = o.getHead(); aux->getNext()!= nullptr; aux = aux->getNext())
    {
        output << aux->getValue() << " -> ";
    }
    output << aux->getValue() << " -> NULL\n";
    return output;
}
