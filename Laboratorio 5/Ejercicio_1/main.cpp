#include <iostream>

using namespace std;

void datos();
void intercambio(int *, int *);
void mostrar();

int x, y;

int main()
{
    datos();
    intercambio(&x, &y);
    mostrar();
    return 0;
}

void datos()
{
    std::cout << "\n\tPrograma para intercambiar dos valores.\n";
    std::cout << "\t=======================================\n";
    std::cout << "\nIngrese el primer valor:\n";
    std::cin >> x;
    std::cout << "\nIngrese el segundo valor:\n";
    std::cin >> y;
    std::cout << "\nPrimer valor:\t" << x << '\n';
    std::cout << "\nSegundo valor:\t" << y << '\n';
}

void intercambio(int *x, int *y)
{
    int aux = *x;
    *x = *y;
    *y = aux;
}

void mostrar()
{
    std::cout << "\nLuego del intercambio se obtuvo:\n";
    std::cout << "\nPrimer valor:\t" << x << '\n';
    std::cout << "\nSegundo valor:\t" << y << '\n';
}

