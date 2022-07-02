#ifndef __NODE_H_
#define __NODE_H_

#include <iostream>

#include "Producto.h"

class Node
{
    public:
        Node();
        Node(Producto);
        void setValue(const Producto);
        Producto getValue() const;
        void setNext(Node *);
        Node *getNext() const;
        ~Node();
    private:
        Producto value;
        Node *next;
};

std::ostream& operator<<(std::ostream &output, const Node &o);

#endif

