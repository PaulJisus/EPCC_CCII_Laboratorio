#ifndef __LINKEDLIST_H_
#define __LINKEDLIST_H_

#include "Node.h"
#include <iostream>
#include <random>
#include <chrono>

template <typename T>
class LinkedList;

template <typename T>
std::ostream& operator<<(std::ostream &, const LinkedList<T> &);

template <typename T>
class LinkedList
{
    public:
        LinkedList();
        LinkedList(T);
        int getSize() const;
        void setHead(Node<T> *);
        Node<T> *getHead() const;
        bool empty() const;
        Node<T> *front() const;
        Node<T> *back() const;
        Node<T> *position(int) const;
        void push_back(T);
        void push_front(T);
        void insert(int, T);
        bool search(T);
        void pop_front();
        void pop_back();
        void pop_position(int);
        void remove(T);
        void reverse();
        void erase(int, int);
        void sort();
        void descendent_sort();
        void MergeSort(Node<T> **);
        void DescendentMergeSort(Node<T> **);
        Node<T> *SortedMerge(Node<T> *, Node<T> *);
        Node<T> *DescendentSortedMerge(Node<T> *, Node<T> *);
        void dividir(Node<T> *, Node<T> **, Node<T> **);
        void print() const;
        void clear();
        ~LinkedList();
    private:
        T size;
        Node<T> *head;
};

template <typename T>
LinkedList<T>::LinkedList()
{
    this->head = nullptr;
    this->size = 0;
}

template <typename T>
LinkedList<T>::LinkedList(T value)
{
    this->head = new Node(value);
    this->size = 1;
}

template <typename T>
int LinkedList<T>::getSize() const
{
    return size;
}

template <typename T>
void LinkedList<T>::setHead(Node<T> * head)
{
    this->head = head;
}

template <typename T>
Node<T>* LinkedList<T>::getHead() const
{
    return (this->head);
}

template <typename T>
bool LinkedList<T>::empty() const
{
    return (getHead() == nullptr);
}

template <typename T>
Node<T> *LinkedList<T>::front() const
{
    if(empty())
    {
        throw std::invalid_argument("Lista Vacia.\n");
    }
    else
    {
        return(getHead());
    }
}

template <typename T>
Node<T> *LinkedList<T>::back() const
{
    if(empty())
    {
        throw std::invalid_argument("Lista Vacia.\n");
    }
    else
    {
        Node<T> *tmp = getHead();
        while(tmp->getNext() != nullptr)
        {
            tmp = tmp->getNext();
        }
        return(tmp);
    }
}

template <typename T>
Node<T> *LinkedList<T>::position(int pos) const
{
    if(empty())
    {
        throw std::invalid_argument("Lista Vacia.\n");
    }
    else if(pos >= 0 && pos <= getSize() - 1)
    {

        Node<T> *tmp = getHead();
        while(pos >= 0)
        {
            tmp = tmp->getNext();
            pos--;
        }
        return(tmp);
    }
    else
    {
        throw std::invalid_argument("Posicion invalida en la lista.\n");
    }
}

template <typename T>
void LinkedList<T>::push_back(T value)
{
    Node<T> *aux = new Node(value);
    if(empty())
    {
        setHead(aux);
        size ++;
        return;
    }
    else
    {
        Node<T> *tmp = getHead();
        while(tmp->getNext() != nullptr)
        {
            tmp = tmp->getNext();
        }
        tmp->setNext(aux);
        size++;
    }
}

template <typename T>
void LinkedList<T>::push_front(T value)
{
    Node<T> *aux = new Node(value);
    aux->setNext(getHead());
    setHead(aux);
    size++;
}

template <typename T>
void LinkedList<T>::insert(int pos, T value)
{
    if(empty())
    {
        push_front(value);
    }
    else if(pos >= 0 && pos <= getSize() - 1)
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
            Node<T> *tmp = getHead();
            Node<T> *tmp1 = nullptr;
            while(pos >= 0)
            {
                tmp1 = tmp;
                tmp = tmp->getNext();
                pos--;
            }
            Node<T> *aux = new Node(value);
            tmp1->setNext(aux);
            aux->setNext(tmp);
            size++;
        }
    }
    else
    {
        throw std::invalid_argument("Posicion invalida en la lista.\n");
    }
}

template <typename T>
bool LinkedList<T>::search(T value)
{
    bool flag{};
    if(empty())
    {
        flag = false;
    }
    else
    {
        Node<T> *aux = getHead();
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

template <typename T>
void LinkedList<T>::pop_front()
{
    if(empty())
    {
        throw std::invalid_argument("Lista Vacia.\n");
    }
    else
    {
        Node<T> *aux = getHead();
        setHead(getHead()->getNext());
        size--;
        delete aux;
    }
}

template <typename T>
void LinkedList<T>::pop_back()
{
    if(empty())
    {
        throw std::invalid_argument("Lista Vacia.\n");
    }
    else
    {
        Node<T> *aux = getHead();
        Node<T> *tmp = nullptr;
        while(aux->getNext() != nullptr)
        {
            tmp = aux;
            aux = aux->getNext();
        }
        tmp->setNext(nullptr);
        delete aux;
        size--;
    }
}

template <typename T>
void LinkedList<T>::pop_position(int pos)
{
    if(pos >= 0 && pos <= size - 1)
    {
        if(pos == 0)
        {
            pop_front();
        }
        else if(pos == getSize()- 1)
        {
            pop_back();
        }
        else
        {
            Node<T> *tmp = getHead();
            Node<T> *tmp1 = nullptr;
            while(pos > 0)
            {
                tmp1 = tmp;
                tmp = tmp->getNext();
                pos--;
            }
            tmp1->setNext(tmp->getNext());
            delete tmp;
            size--;
        }
    }
    else
    {
        throw std::invalid_argument("Posicion invalida en la lista.\n");
    }
}

template <typename T>
void LinkedList<T>::remove(T value)
{
    if(empty())
    {
        throw std::invalid_argument("Lista Vacia.\n");
    }
    else if(!search(value))
    {
        throw std::invalid_argument("Elemento no existente en la lista.\n");
    }
    else
    {
        Node<T> *aux = getHead();
        Node<T> *tmp = nullptr;
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

template <typename T>
void LinkedList<T>::reverse()
{
    if(empty())
    {
        throw std::invalid_argument("Lista Vacia.\n");
    }
    else
    {
        Node<T> *aux = getHead();
        Node<T> *tmp_a = nullptr;
        Node<T> *tmp_s = nullptr;
        while(aux != nullptr)
        {
            tmp_s = aux->getNext();
            aux->setNext(tmp_a);
            tmp_a = aux;
            aux = tmp_s;
        }
        head = tmp_a;
    }
}

template <typename T>
void LinkedList<T>::erase(int pos_i, int pos_f)
{
    if(empty())
    {
        throw std::invalid_argument("Lista Vacia.\n");
    }
    else if((pos_i >= 0 && pos_i < getSize()) && (pos_f >= 0 && pos_f < getSize()))
    {
        if(pos_i == 0)
        {
            for(int i{0}; i < pos_f - pos_i; i++)
            {
                pop_front();
            }
        }
        else if(pos_f == getSize() - 1)
        {
            for(int i{pos_f}; i >= pos_f - pos_i; i--)
            {
                pop_back();
            }
        }
        else
        {
            Node<T> *aux = getHead();
            Node<T> *tmp;
            for(int i{0}; i < pos_i - 1; i++)
            {
                aux = aux->getNext();
            }
            for(int i{0}; i < pos_f - pos_i + 1; i++)
            {
                tmp = aux->getNext();
                aux->setNext(tmp->getNext());
                delete tmp;
                size--;
            }
        }
    }
    else
    {
        throw std::invalid_argument("Posicion invalida en la lista.\n");
    }
}

template <typename T>
void LinkedList<T>::sort()
{
    if(empty())
    {
        throw std::invalid_argument("Lista Vacia.\n");
    }
    else
    {
        MergeSort(&head);
    }
}

template <typename T>
void LinkedList<T>::descendent_sort()
{
    if(empty())
    {
        throw std::invalid_argument("Lista Vacia.\n");
    }
    else
    {
        DescendentMergeSort(&head);
    }
}

template <typename T>
void LinkedList<T>::MergeSort(Node<T> **Ref_head)
{
    Node<T> *aux = *Ref_head;
    Node<T> *a = nullptr;
    Node<T> *b = nullptr;
    if((aux == nullptr) || (aux->getNext() == nullptr))
    {
        return;
    }
    dividir(aux, &a, &b);
    MergeSort(&a);
    MergeSort(&b);
    *Ref_head = SortedMerge(a, b);
}

template <typename T>
void LinkedList<T>::DescendentMergeSort(Node<T> **Ref_head)
{
    Node<T> *aux = *Ref_head;
    Node<T> *a = nullptr;
    Node<T> *b = nullptr;
    if((aux == nullptr) || (aux->getNext() == nullptr))
    {
        return;
    }
    dividir(aux, &a, &b);
    DescendentMergeSort(&a);
    DescendentMergeSort(&b);
    *Ref_head = DescendentSortedMerge(a, b);
}

template <typename T>
Node<T> *LinkedList<T>::SortedMerge(Node<T> *a, Node<T> *b)
{
    Node<T> *aux = nullptr;
    if(a == nullptr)
    {
        return(b);
    }
    else if(b == nullptr)
    {
        return(a);
    }
    if(a->getValue() <= b->getValue())
    {
        aux = a;
        aux->setNext(SortedMerge(a->getNext(), b));
    }
    else
    {
        aux = b;
        aux->setNext(SortedMerge(b->getNext(), a));
    }
    return (aux);
}

template <typename T>
Node<T> *LinkedList<T>::DescendentSortedMerge(Node<T> *a, Node<T> *b)
{
    Node<T> *aux = nullptr;
    if(a == nullptr)
    {
        return(b);
    }
    else if(b == nullptr)
    {
        return(a);
    }
    if(a->getValue() >= b->getValue())
    {
        aux = a;
        aux->setNext(DescendentSortedMerge(a->getNext(), b));
    }
    else
    {
        aux = b;
        aux->setNext(DescendentSortedMerge(b->getNext(), a));
    }
    return (aux);
}

template <typename T>
void LinkedList<T>::dividir(Node<T> *inicio, Node<T> **L1, Node<T> **L2)
{
    Node<T> *aux = inicio;
    Node<T> *aux1 = inicio->getNext();
    while(aux1 != nullptr)
    {
        aux1 = aux1->getNext();
        if(aux1 != nullptr)
        {
            aux = aux->getNext();
            aux1 = aux1->getNext();
        }
    }
    *L1 = inicio;
    *L2 = aux->getNext();
    aux->setNext(nullptr);
}

template <typename T>
void LinkedList<T>::clear()
{
    while(!empty())
    {
        pop_front();
    }
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}

template <typename T>
std::ostream& operator<<(std::ostream &output, const LinkedList<T> &o)
{
    if(o.empty())
    {
        throw std::invalid_argument("Lista Vacia\n");
    }
    else
    {
        Node<T> *aux;
        for(aux = o.getHead(); aux->getNext()!= nullptr; aux = aux->getNext())
        {
            output << aux->getValue() << " -> ";
        }
        output << aux->getValue() << " -> NULL\n";
        return output;
    }
}

#endif
