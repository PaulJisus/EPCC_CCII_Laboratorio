#include <iostream>

#include "Calculadora.h"

using namespace std;

int main()
{
    Calculadora<int> c1(15, 12);
    Calculadora<double> c2(34.2435, 6.3423);
    std::cout << "\nResultados de la calculadora de enteros:\n";
    c1.resultado();
    std::cout << "\nResultados de la calculadora de reales:\n";
    c2.resultado();
    return 0;
}
