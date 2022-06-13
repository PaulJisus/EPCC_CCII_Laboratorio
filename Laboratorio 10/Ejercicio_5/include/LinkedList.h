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
        Node *front() const;
        Node *back() const;
        void push_back(int);
        void push_front(int);
        void insert(int, int);
        bool search(int);
        void pop_front();
        void pop_back();
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
