#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include "Node.h"
#include <iostream>

class Linkedlist
{
    public:
        Linkedlist();
        Linkedlist(int);
        int getSize() const;
        bool empty() const;
        void insert(int);
        void search(int);
        void remove(int);
        void print() const;
        ~Linkedlist();
        friend std::ostream& operator<<(std::ostream &output, const Linkedlist &o);
    private:
        int size;
        Node *head;
};

#endif

