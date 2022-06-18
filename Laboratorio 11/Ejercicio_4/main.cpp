#include <iostream>
#include <cmath>
#include <chrono>
#include <thread>

#include "Stack.h"

using namespace std;

void Datos(Stack *, Stack *, Stack *);
void HanoiTower(Stack *, Stack *, Stack *, int);
void Move(Stack *, Stack *);
void Mostrar(Stack *, Stack *, Stack *);
void Clear();

int main()
{
    Stack *s1 = new Stack();
    Stack *s2 = new Stack();
    Stack *s3 = new Stack();
    Datos(s1, s2, s3);
}

void Datos(Stack *s1, Stack *s2, Stack *s3)
{
    int n{};
    std::cout << "\nIngrese la cantidad de Discos:\n";
    std::cin >> n;
    HanoiTower(s1, s2, s3, n);
}

void HanoiTower(Stack *s1, Stack *s2, Stack *s3, int n)
{
    int aux1 = std::pow(2, n) - 1;
    for(int i = n; i >= 1; i--)
    {
        s1->push(i);
    }
    Clear();
    std::cout << "\n\tConfiguracion Inicial:\n";
    Mostrar(s1, s2, s3);
    this_thread::sleep_for(chrono::milliseconds(2000));
    Clear();
    for(int i = 1; i <= aux1; i++)
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
        std::cout << "\n\tMovimiento numero " << i << ":\n";
        if(i == aux1)
        {
            std::cout << "\tResultado Final\n";
        }
        if(n % 2 != 0)
        {
            Mostrar(s1, s2, s3);
        }
        else
        {
            Mostrar(s1, s3, s2);
        }
        this_thread::sleep_for(chrono::milliseconds(2000));
        Clear();
    }
}

void Mostrar(Stack *s1, Stack *s2, Stack *s3)
{
    std::cout << "\nTorre Origen  | " << *s1;
    std::cout << "\nTorre Auxiliar| " << *s2;
    std::cout << "\nTorre Destino | " << *s3;
}

void Move(Stack *s1, Stack *s2)
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

void Clear()
{
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}
