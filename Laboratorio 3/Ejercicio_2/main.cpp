#include <iostream>

using namespace std;

void datos();
bool bisiesto(int);
void mostrar(int);

int a, b;

int main()
{
    //Llamada a la funcion datos(), para ingresar los datos.
    datos();
    mostrar(a);
    return 0;
}

void datos()
{
    std::cout << "Programa para detectar si un a" << (char)164 << "o es bisiesto." << '\n';
    std::cout << "\nIngrese el a" << (char)164 << "o:\n";
    std::cin >> a;
}

bool bisiesto(int a)
{
    if(((a % 4 == 0) && (a % 100 != 0)) || (a % 400 == 0))
    {
        return true;
    }
    return false;
}

void mostrar(int a)
{
    if(bisiesto(a))
    {
        std::cout << "\nEl a" << (char)164 << "o " << a << " es Bisiesto.\n";
    }
    else
    {
        std::cout << "\nEl a" << (char)164 << "o " << a << " no es Bisiesto.\n";
    }
}
