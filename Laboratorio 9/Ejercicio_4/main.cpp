#include <iostream>

#include "Arreglo.h"

using namespace std;

int main()
{
    Arreglo<int> a1;
    a1.push_back(5);
    a1.push_back(7);
    a1.push_back(8);
    a1.push_top(9);
    std::cout << a1;
    Arreglo<float> a2;
    a2.push_back(3.6);
    a2.push_back(4.8);
    a2.push_back(5.2);
    a2.push_back(3.24);
    a2.push_back(43.5);
    a2.push_back(76.3);
    a2.push_top(76.35);
    a2.push_top(8.9);
    a2.push_top(-2.5);
    a2.push_top(-12.8);
    std::cout << a2;
    return 0;
}
