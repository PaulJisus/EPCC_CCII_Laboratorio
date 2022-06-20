#include "Queue.h"

Queue::Queue()
{
    this->size = 0;
    this->front = nullptr;
    this->rear = nullptr;
}

Queue::Queue(const Queue &o)
{
    this->front = nullptr;
    this->rear = nullptr;
    this->size = 0;
    Node *aux = o.getFront();
    while(aux)
    {
        this->enQueue(aux->getValue());
        aux = aux->getNext();
    }
}

int Queue::getSize() const
{
    return (this->size);
}

void Queue::setFront(Node *front)
{
    this->front = front;
}

Node* Queue::getFront() const
{
    return (this->front);
}

void Queue::setRear(Node *rear)
{
    this->rear = rear;
}

Node* Queue::getRear() const
{
    return (this->rear);
}

bool Queue::empty() const
{
    return (getFront() == nullptr);
}

void Queue::enQueue(int value)
{
    Node *aux = new Node(value);
    if(empty())
    {
        setRear(aux);
        setFront(aux);
    }
    else
    {
        getRear()->setNext(aux);
        setRear(aux);
    }
    this->size++;
}

void Queue::print() const
{
    if(empty())
    {
        throw std::invalid_argument("Empty Queue.\n");
    }
    else
    {
        Node *aux = getFront();
        while(aux)
        {
            std::cout << aux->getValue() << " -> ";
            aux = aux->getNext();
        }
        std::cout << "NULL\n";
    }
}

Queue::~Queue()
{
    Node *aux;
    while(getFront() != nullptr)
    {
        aux = getFront()->getNext();
        delete front;
        front = aux;
    }
    delete front;
    delete rear;
}

std::ostream& operator<< (std::ostream &output, const Queue &o)
{
    if(o.empty())
    {
        throw std::invalid_argument("Empty Queue\n");
    }
    else
    {
        Node *aux;
        for(aux = o.getFront(); aux->getNext()!= nullptr; aux = aux->getNext())
        {
            output << aux->getValue() << " -> ";
        }
        output << aux->getValue() << " -> NULL\n";
        return output;
    }
}
