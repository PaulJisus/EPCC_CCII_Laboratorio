#include <iostream>

using namespace std;

void datos();
void redondeado(int, int);

int x, y;

int main()
{
    //Llamada a funcion para ingreso de datos
    datos();
    //Llamada a funcion para mostrar el resultado
    redondeado(x, y);
    return 0;
}

void datos()
{
    char a;
    std::cout << "Programa para redondear un numero.\n";
    std::cout << "\nIngrese el numero con punto flotante: ";
    std::cin >> x >> a >> y;
}

void redondeado(int x, int y)
{
    std:: cout << "El numero " << x << "." << y << " redondeado es: " << x << '\n';
}

