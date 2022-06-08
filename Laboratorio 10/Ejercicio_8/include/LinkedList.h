#ifndef __LINKEDLIST_H_
#define __LINKEDLIST_H_

#include "Node.h"
#include <iostream>
#include <random>
#include <chrono>

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
        void push_front(int);
        void insert(int, int);
        bool search(int);
        void pop_front();
        void pop_back();
        void pop_position(int);
        void remove(int);
        void reverse();
        void erase(int, int);
        void sort();
        void descendent_sort();
        void MergeSort(Node **);
        void DescendentMergeSort(Node **);
        Node *SortedMerge(Node *, Node *);
        Node *DescendentSortedMerge(Node *, Node *);
        void dividir(Node *, Node **, Node **);
        int random();
        void push_random();
        void print() const;
        void clear();
        ~LinkedList();
    private:
        int size;
        Node *head;
};

std::ostream& operator<<(std::ostream &output, const LinkedList &o);

#endif

