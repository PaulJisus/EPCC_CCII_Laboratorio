#include "Linkedlist.h"

Linkedlist::Linkedlist()
{
    head = nullptr;
    size = 0;
}

Linkedlist::Linkedlist(int elem)
{
    head = new Node(elem);
    size = 1;
}

int Linkedlist::getSize() const
{
    return size;
}

bool Linkedlist::empty() const
{
    return (head == nullptr);
}

void Linkedlist::insert(int elem)
{
    Node *aux = new Node();
    aux->setValue(elem);
    aux->setNext(nullptr);
    if(empty())
    {
        head = aux;
        size++;
        return;
    }
    else
    {
        Node *tmp = head;
        while(tmp->getNext() != nullptr && tmp->getNext()->getValue() <= elem)
        {
            tmp = tmp->getNext();
        }
        aux->setNext(tmp->getNext());
        tmp->setNext(aux);
        size++;
    }
}

void Linkedlist::search(int elem)
{
    if(empty())
    {
        std::cout << "Lista vacia\n";
        return;
    }
    else
    {
        Node *aux = head;
        bool flag = false;
        int cont = 0;
        while(aux->getNext() != nullptr && flag != true)
        {
            if(aux->getValue() == elem)
            {
                flag = true;
                std::cout << "Nodo con valor: " << aux->getValue()
                << " encontrado en la posicion: " << cont << std::endl;
            }
            else
            {
                aux = aux->getNext();
                cont ++;
            }
        }
        if(flag != true)
        {
            std::cout << "No se pudo encontrado un Nodo con el valor: " << elem << std::endl;
        }
    }
}

void Linkedlist::remove(int elem)
{
    if(empty())
    {
        std::cout << "Lista vacia\n";
        return;
    }
    else
    {
        Node *aux = head;
        Node *aux1 = nullptr;
        bool flag = false;
        while(aux->getNext() != nullptr && flag != true)
        {
            if(aux->getValue() == elem)
            {
                flag = true;
            }
            else
            {
                aux1 = aux;
                aux = aux->getNext();
            }
        }
        if(flag == true)
        {
            if(aux1 == nullptr)
            {
                head = aux->getNext();
                delete aux;
            }
            else
            {
                aux1->setNext(aux->getNext());
                delete aux;
            }
            size --;
        }
        else
        {
                std::cout << "No se pudo eliminar un Nodo con valor: " << elem << " NO EXISTE EN LA LISTA" << std::endl;
        }
    }
}

void Linkedlist::print() const
{
    Node *aux = head;
    while(aux != nullptr)
    {
        std::cout << aux->getValue() << " -> ";
        aux = aux->getNext();
    }
    std::cout << "NULL" << std::endl;
}

Linkedlist::~Linkedlist()
{
    Node *aux = nullptr;
    while(head != nullptr)
    {
        aux = head;
        head = aux->getNext();
        delete aux;
        size --;
    }
}

std::ostream& operator<<(std::ostream &output, const Linkedlist &o)
{
    Node *aux;
    for(aux = o.head; aux->getNext()!= nullptr; aux = aux->getNext())
    {
        output << aux->getValue() << " -> ";
    }
    output << aux->getValue() << " -> NULL\n";
    return output;
}
