#include <iostream>

using namespace std;

int main()
{
    int numeros[3][3], suma = 0, mayor = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            std::cout << "Ingrese el elemento de la posicion[" << i << "][" << j << "]: ";
            cin >> numeros[i][j];
        }
    }
    std::cout << '\n';
    for(int i = 0; i < 3; i++)
    {
        suma = 0;
        for(int j = 0; j < 3; j++)
        {
            cout << numeros[i][j] << '\t';
            suma += numeros[i][j];
            if(suma > mayor)
            {
                mayor = suma;
            }
        }
        std::cout << '\n';
    }
    std::cout << "\nEl valor de la mayor suma por fila es: " << mayor << '\n';
    return 0;
}
