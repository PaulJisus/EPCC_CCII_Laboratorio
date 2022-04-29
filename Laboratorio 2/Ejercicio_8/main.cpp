#include <iostream>

using namespace std;

void datos();
void tabla (int, int);

int n, x;

int main()
{
    datos();
    tabla(n, x);
}

void datos()
{
    std::cout << "\n\tPrograma para generar la tabla de multiplicar de un numero.\n";
    std::cout << "\t________________________________________________________________\n";
    std::cout << "\nIngrese el numero del cual desea saber la tabla: ";
    std::cin >> n;
    std::cout << "\nIngrese el ultimo elemento multiplicador de la tabla: ";
    std::cin >> x;
    std::cout << "\nLa tabla de multiplicar del numero " << n << " es:\n";
}

void tabla(int n, int x)
{
    std::cout << '\n';
    for(int i = 0; i <= x; i++)
        std::cout << n << " x " << i << " = " << n*i << '\n';
}
