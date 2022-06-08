#ifndef __LINKEDLIST_H_
#define __LINKEDLIST_H_

#include "Node.h"
#include <iostream>

class LinkedList
{
    public:
        LinkedList();
        LinkedList(int);
        int getSize() const;
        void setHead(Node *);
        Node *getHead() const;
        bool empty() const;
        int front() const;
        int back() const;
        void push_back(int);
        bool search(int);
        void pop_front();
        void remove(int);
        void print() const;
        void clear();
        ~LinkedList();
    private:
        int size;
        Node *head;
};

std::ostream& operator<<(std::ostream &output, const LinkedList &o);

#endif
