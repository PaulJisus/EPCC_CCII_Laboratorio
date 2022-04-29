#include <iostream>

using namespace std;

void datos();
int producto(int, int);

int a, b;

int main()
{
    //Llamada a la funcion datos(), para ingresar los datos.
    datos();
    std::cout << "\nEl producto de " << a << " x " << b << " es: " << producto(a, b) << '\n';
    return 0;
}

void datos()
{
    std::cout << "Programa para calcular el producto de dos numeros.\n";
    std::cout << "\nIngrese el primer numero: ";
    std::cin >> a;
    std::cout << "\nIngrese el segundo numero: ";
    std::cin >> b;
}

int producto(int a, int b)
{
    int res = 0;
    // Alamcenamos en la variable res el producto.
    res = a * b;
    //Retornamos el producto.
    return res;
}
