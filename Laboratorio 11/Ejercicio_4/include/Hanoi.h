#ifndef HANOI_H
#define HANOI_H

#include <cmath>

#include "Stack.h"

class Hanoi
{
    public:
        Hanoi();
        void setSize(const int);
        int getSize() const;
        void setMovimientos();
        int getMovimientos() const;
        void HanoiTower();
        void Move(Stack *, Stack *);
        void mostrar() const;
        ~Hanoi();
    private:
        Stack *s1;
        Stack *s2;
        Stack *s3;
        int size;
        int movimientos;
};

#endif
