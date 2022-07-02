#include "LinkedList.h"

LinkedList::LinkedList()
{
    this->head = nullptr;
    this->size = 0;
}

LinkedList::LinkedList(Producto value)
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
        throw std::invalid_argument("Lista Vacia.\n");
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
        throw std::invalid_argument("Lista Vacia.\n");
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

Node *LinkedList::position(int pos) const
{
    if(empty())
    {
        throw std::invalid_argument("Lista Vacia.\n");
    }
    else if(pos >= 0 && pos <= getSize() - 1)
    {

        Node *tmp = getHead();
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


void LinkedList::push_back(Producto value)
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

void LinkedList::push_front(Producto value)
{
    Node *aux = new Node(value);
    aux->setNext(getHead());
    setHead(aux);
    size++;
}

void LinkedList::insert(int pos, Producto value)
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

bool LinkedList::search_code(std::string codigo)
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
            if(aux->getValue().getCodigo() == codigo)
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

bool LinkedList::search_name(std::string nombre)
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
            if(aux->getValue().getNombre() == nombre)
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
        throw std::invalid_argument("Lista Vacia.\n");
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
        throw std::invalid_argument("Lista Vacia.\n");
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
        throw std::invalid_argument("Posicion invalida en la lista.\n");
    }
}

void LinkedList::remove_code(std::string codigo)
{
    if(empty())
    {
        throw std::invalid_argument("Lista Vacia.\n");
    }
    else if(!search_code(codigo))
    {
        throw std::invalid_argument("Elemento no existente en la lista.\n");
    }
    else
    {
        Node *aux = getHead();
        Node *tmp = nullptr;
        while(aux != nullptr)
        {
            if(getHead()->getValue().getCodigo() == codigo)
            {
                pop_front();
            }
            else if(aux->getNext() != nullptr && aux->getNext()->getValue().getCodigo() == codigo)
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

void LinkedList::remove_name(std::string nombre)
{
    if(empty())
    {
        throw std::invalid_argument("Lista Vacia.\n");
    }
    else if(!search_name(nombre))
    {
        throw std::invalid_argument("Elemento no existente en la lista.\n");
    }
    else
    {
        Node *aux = getHead();
        Node *tmp = nullptr;
        while(aux != nullptr)
        {
            if(getHead()->getValue().getNombre() == nombre)
            {
                pop_front();
            }
            else if(aux->getNext() != nullptr && aux->getNext()->getValue().getNombre() == nombre)
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

void LinkedList::change_name(std::string nombre_1, std::string nombre)
{
    if(empty())
    {
        throw std::invalid_argument("Lista Vacia.\n");
    }
    else if(!search_name(nombre_1))
    {
        throw std::invalid_argument("Elemento no existente en la lista.\n");
    }
    else
    {
        Node *aux = getHead();
        while(aux->getNext() != nullptr)
        {
            if(aux->getValue().getNombre() == nombre_1)
            {
                aux->getValue().setNombre(nombre);
            }
            else
            {
                aux = aux->getNext();
            }
        }
    }
}

void LinkedList::change_price(std::string nombre, double precio)
{
    if(empty())
    {
        throw std::invalid_argument("Lista Vacia.\n");
    }
    else if(!search_name(nombre))
    {
        throw std::invalid_argument("Elemento no existente en la lista.\n");
    }
    else
    {
        Node *aux = getHead();
        while(aux->getNext() != nullptr)
        {
            if(aux->getValue().getNombre() == nombre)
            {
                aux->getValue().setPrecio(precio);
            }
            else
            {
                aux = aux->getNext();
            }
        }
    }
}

void LinkedList::change_stock(std::string nombre, int stock)
{
    if(empty())
    {
        throw std::invalid_argument("Lista Vacia.\n");
    }
    else if(!search_name(nombre))
    {
        throw std::invalid_argument("Elemento no existente en la lista.\n");
    }
    else
    {
        Node *aux = getHead();
        while(aux->getNext() != nullptr)
        {
            if(aux->getValue().getNombre() == nombre)
            {
                aux->getValue().setStock(stock);
            }
            else
            {
                aux = aux->getNext();
            }
        }
    }
}

void LinkedList::reverse()
{
    if(empty())
    {
        throw std::invalid_argument("Lista Vacia.\n");
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
        throw std::invalid_argument("Posicion invalida en la lista.\n");
    }
}

void LinkedList::sort()
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

void LinkedList::descendent_sort()
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

void LinkedList::DescendentMergeSort(Node **Ref_head)
{
    Node *aux = *Ref_head;
    Node *a = nullptr;
    Node *b = nullptr;
    if((aux == nullptr) || (aux->getNext() == nullptr))
    {
        return;
    }
    dividir(aux, &a, &b);
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
    if(a->getValue().getPrecio() <= b->getValue().getPrecio())
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
    if(a->getValue().getPrecio() >= b->getValue().getPrecio())
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
            output << aux->getValue();
        }
        output << aux->getValue();
        return output;
    }
}
