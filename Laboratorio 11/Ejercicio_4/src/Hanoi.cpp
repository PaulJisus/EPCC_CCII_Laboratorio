#include "Hanoi.h"

Hanoi::Hanoi() = default;

void Hanoi::setSize(const int size)
{
    this->size = size;
    for(int i = size; i >= 1; i--)
    {
        s1->push(i);
    }
}

int Hanoi::getSize() const
{
    return this->size;
}

void Hanoi::setMovimientos()
{
    this->movimientos = getMovimientos();
}

int Hanoi::getMovimientos() const
{
    return(std::pow(2, getSize()) - 1);
}

void Hanoi::HanoiTower()
{
    mostrar();
    for(int i = 1; i <= getMovimientos(); i++)
    {
        if(i % 3 == 0)
        {
            Move(s2, s3);
        }
        else if(i % 3 == 1)
        {
            Move(s1, s3);
        }
        else if(i % 3 == 2)
        {
            Move(s1, s2);
        }
        mostrar();
    }
}

void Hanoi::Move(Stack *s1, Stack *s2)
{
    if(s1->empty())
    {
        s1->push(s2->pop()->getValue());
    }
    else if(s2->empty())
    {
        s2->push(s1->pop()->getValue());
    }
    else if(s1->top()->getValue() > s2->top()->getValue())
    {
        s1->push(s2->pop()->getValue());
    }
    else
    {
        s2->push(s1->pop()->getValue());
    }
}


void Hanoi::mostrar() const
{
    while(getSize())
    {
        std::cout << *s1->top()->getValue << '\t' << *s2->top->getValue() << '\t' << *s3->top()->getValue << '\n';
        --getSize();
    }
}

Hanoi::~Hanoi()
{
    //dtor
}
