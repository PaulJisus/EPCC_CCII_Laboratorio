#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>

class Node
{
    public:
        Node();
        Node(int);
        void setValue(int);
        int getValue();
        void setNext(Node *);
        Node *getNext();
        ~Node();
    private:
        int value;
        Node *next;
};

#endif
