#include <iostream>

using namespace std;

void datos();
int pow(int, int);

int a, b;

int main()
{
    //Llamada a la funcion datos(), para ingresar los datos.
    datos();
    std::cout << '\n' << a << " elevado a " << b << " es: " << pow(a, b) << '\n';
    return 0;
}

void datos()
{
    std::cout << "Programa para calcular la potencia de un numero.\n";
    std::cout << "\nIngrese el numero: ";
    std::cin >> a;
    std::cout << "\nIngrese el exponente: ";
    std::cin >> b;
}

int pow(int a, int b)
{
    int aux = 0;
    if(b == 0)
    {
        return 1;
    }
    for(int i = 0; i != b; i++)
    {
        aux += a;
    }
    return aux;
}
