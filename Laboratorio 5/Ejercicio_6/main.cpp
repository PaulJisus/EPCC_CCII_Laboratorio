#include <iostream>

void datos();
void sumar(int, int);
void restar(int, int);
void multiplicar(int, int);
void dividir(int, int);

int a{}, b{};

using namespace std;

int main()
{
    datos();
    return 0;
}

void datos()
{
    void (*operacion[4])(int, int)= {sumar, restar, multiplicar, dividir};
    std::cout << "Ingrese el primer valor:\n";
    std::cin >> a;
    std::cout << "Ingrese el segundo valor:\n";
    std::cin >> b;
    for(int i = 0; i < 4; i++)
    {
        operacion[i](a, b);
    }
}

void sumar(int a, int b)
{
    std::cout << "\nEl resultado de la suma de " << a << " + " << b << " es:\n";
    std::cout << a + b << '\n';
}

void restar(int a, int b)
{
    std::cout << "\nEl resultado de la resta de " << a << " - " << b << " es:\n";
    std::cout << a - b << '\n';
}

void multiplicar(int a, int b)
{
    std::cout << "\nEl resultado de la multiplicacion de " << a << " x " << b << " es:\n";
    std::cout << a * b << '\n';
}

void dividir(int a, int b)
{
    std::cout << "\nEl resultado de la division de " << a << " / " << b << " es:\n";
    std::cout << (double)a / b << '\n';
}
