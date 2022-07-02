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
        LinkedList(Producto);
        int getSize() const;
        void setHead(Node *);
        Node *getHead() const;
        bool empty() const;
        Node *front() const;
        Node *back() const;
        Node *position(int) const;
        void push_back(Producto);
        void push_front(Producto);
        void insert(int, Producto);
        bool search_code(std::string);
        bool search_name(std::string);
        void pop_front();
        void pop_back();
        void pop_position(int);
        void remove_code(std::string);
        void remove_name(std::string);
        void change_name(std::string, std::string);
        void change_price(std::string, double);
        void change_stock(std::string, int);
        void reverse();
        void erase(int, int);
        void sort();
        void descendent_sort();
        void MergeSort(Node **);
        void DescendentMergeSort(Node **);
        Node *SortedMerge(Node *, Node *);
        Node *DescendentSortedMerge(Node *, Node *);
        void dividir(Node *, Node **, Node **);
        void print() const;
        void clear();
        ~LinkedList();
    private:
        int size;
        Node *head;
};

std::ostream& operator<<(std::ostream &output, const LinkedList &o);

#endif
