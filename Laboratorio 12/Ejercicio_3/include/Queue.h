#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>

#include "Node.h"

class Queue
{
    public:
        Queue();
        Queue(const Queue &);
        int getSize() const;
        void setFront(Node *);
        Node *getFront() const;
        void setRear(Node *);
        Node *getRear() const;
        bool empty() const;
        void enQueue(int);
        Node *deQueue();
        Node *front();
        Node *back();
        bool search(int);
        void print() const;
        ~Queue();
    private:
        int size;
        Node *Front;
        Node *rear;
};

std::ostream& operator<< (std::ostream &output, const Queue &o);

#endif
