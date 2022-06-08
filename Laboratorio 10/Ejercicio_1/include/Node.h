#ifndef __NODE_H_
#define __NODE_H_

#include <iostream>

class Node
{
    public:
        Node();
        Node(int);
        void setValue(const int);
        int getValue() const;
        void setNext(Node *);
        Node *getNext() const;
        ~Node();
    private:
        int value;
        Node *next;
};

#endif

