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
            size--;
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

void LinkedList::reverse()
{
    if(empty())
    {
        throw std::invalid_argument("Lista Vacia");
    }
    else
    {
        Node *aux = getHead();
        Node *tmp_a = nullptr;
        Node *tmp_s = nullptr;
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

void LinkedList::erase(int pos_i, int pos_f)
{
    if((pos_i >= 0 && pos_i < getSize()) && (pos_f >= 0 && pos_f < getSize()))
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
            Node *aux = getHead();
            Node *tmp;
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
        throw std::invalid_argument("Posicion invalida en la lista.");
    }
}

void LinkedList::sort()
{
    MergeSort(&head);
}

void LinkedList::descendent_sort()
{
    DescendentMergeSort(&head);
}

void LinkedList::MergeSort(Node **Ref_head)
{
    Node *head = *Ref_head;
    Node *a = nullptr;
    Node *b = nullptr;
    if((head == nullptr) || (head->getNext() == nullptr))
    {
        return;
    }
    dividir(head, &a, &b);
    MergeSort(&a);
    MergeSort(&b);
    *Ref_head = SortedMerge(a, b);
}

void LinkedList::DescendentMergeSort(Node **Ref_head)
{
    Node *head = *Ref_head;
    Node *a = nullptr;
    Node *b = nullptr;
    if((head == nullptr) || (head->getNext() == nullptr))
    {
        return;
    }
    dividir(head, &a, &b);
    DescendentMergeSort(&a);
    DescendentMergeSort(&b);
    *Ref_head = DescendentSortedMerge(a, b);
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

Node *LinkedList::DescendentSortedMerge(Node *a, Node *b)
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
    Node *aux;
    for(aux = o.getHead(); aux->getNext()!= nullptr; aux = aux->getNext())
    {
        output << aux->getValue() << " -> ";
    }
    output << aux->getValue() << " -> NULL\n";
    return output;
}
