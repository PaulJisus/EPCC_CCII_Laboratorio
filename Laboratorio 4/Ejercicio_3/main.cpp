#include <iostream>

using namespace std;

int main()
{
    int numeros[5][3], suma = 0;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            std::cout << "Ingrese el elemento de la posicion[" << i << "][" << j << "]: ";
            std::cin >> numeros[i][j];
        }
    }
    for(int i = 0; i < 5; i += 2)
    {
        suma = 0;
        std::cout << "\nLos elementos de la fila par " << i << " son:\n";
        for(int j = 0; j < 3; j++)
        {
            std::cout << "\n[" << i << "][" << j << "]: " << numeros[i][j];
            suma += numeros[i][j];
        }
        std::cout << "\nLa suma de los elementos de la fila par " << i << " son:\t" << suma << '\n';
        suma = 0;
    }
    return 0;
}
