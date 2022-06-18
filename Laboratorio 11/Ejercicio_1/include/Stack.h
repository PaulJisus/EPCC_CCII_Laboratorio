#ifndef STACK_H
#define STACK_H

#include <iostream>

#include "Node.h"

class Stack
{
    public:
        Stack();
        Stack(int);
        Stack(const Stack &);
        int getSize() const;
        void setHead(Node *);
        Node *getHead() const;
        bool empty() const;
        void push(int);
        void print() const;
        ~Stack();
    private:
        int size;
        Node *head;
};

std::ostream& operator<< (std::ostream &output, const Stack &o);

#endif
