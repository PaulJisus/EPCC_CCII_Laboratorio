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
        throw std::invalid_argument("Lista Vacia");
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
        throw std::invalid_argument("Lista Vacia");
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

void LinkedList::push_front(int value)
{
    Node *aux = new Node(value);
    aux->setNext(getHead());
    setHead(aux);
    size++;
}

void LinkedList::insert(int pos, int value)
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
        throw std::invalid_argument("Posicion invalida en la lista.\n");
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

void LinkedList::pop_back()
{
    if(empty())
    {
        throw std::invalid_argument("Lista Vacia");
    }
    else
    {
        Node *aux = getHead();
        Node *tmp = nullptr;
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

void LinkedList::pop_position(int pos)
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
            Node *tmp = getHead();
            Node *tmp1 = nullptr;
            while(pos > 0)
            {
                tmp1 = tmp;
                tmp = tmp->getNext();
                pos--;
            }
            tmp1->setNext(tmp->getNext());
            delete tmp;
            size++;
        }
    }
    else
    {
        throw std::invalid_argument("Posicion invalida en la lista.");
    }
}

void LinkedList::remove(int value)
{
    if(empty())
    {
        throw std::invalid_argument("Lista Vacia");
    }
    else if(!search(value))
    {
        throw std::invalid_argument("Elemento no existente en la lista.\n");
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

void LinkedList::sort()
{
    if(empty())
    {
        throw std::invalid_argument("Lista Vacia");
    }
    else
    {
        MergeSort(&head);
    }
}

void LinkedList::MergeSort(Node **Ref_head)
{
    Node *aux = *Ref_head;
    Node *a = nullptr;
    Node *b = nullptr;
    if((aux == nullptr) || (aux->getNext() == nullptr))
    {
        return;
    }
    dividir(aux, &a, &b);
    MergeSort(&a);
    MergeSort(&b);
    *Ref_head = SortedMerge(a, b);
}

Node *LinkedList::SortedMerge(Node *a, Node *b)
{
    Node *aux = nullptr;
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

void LinkedList::dividir(Node *inicio, Node **L1, Node **L2)
{
    Node *aux = inicio;
    Node *aux1 = inicio->getNext();
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

int LinkedList::random()
{
    auto eng = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine gen(eng);
    std::uniform_int_distribution<int> distr(-getSize()- 10, getSize()+ 10);
	return distr(gen);
}

void LinkedList::push_random()
{
    push_back(random());
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
