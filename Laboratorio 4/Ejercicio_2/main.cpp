#include <iostream>

using namespace std;

void datos();
bool buscar(int x);

int numeros[8], x;

int main()
{
    datos();
    return 0;
}

void datos()
{
    std::cout << "\n\tPrograma para hallar un numero en un arreglo.\n";
    std::cout << "\t============================================\n";
    for(int i = 0; i < 8; i++)
    {
        std::cout << "Ingrese el elemento de la posicion " << i + 1 << " :";
        std::cin >> numeros[i];
    }
    std::cout << "Ingrese el valor a buscar: ";
    std::cin >> x;
    if(buscar(x))
    {
        std::cout << "El numero si se encontro.\n";
    }
    else
    {
        std::cout << "Numero no encontrado.\n";
    }
}

bool buscar(int x)
{
    bool aux = false;
    for(int i = 0; i < 8; i++)
    {
        if(numeros[i] == x)
        {
            aux = true;
            break;
        }
    }
    return aux;
}
