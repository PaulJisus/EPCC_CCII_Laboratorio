#include <iostream>

using namespace std;

void datos();
void divisor(const int, const int);

int a, b;

int main()
{
    //llamada a la funcion de ingreso de datos
    datos();
    //llamada a la funcion que mostrara el resultado
    divisor(a, b);
    return 0;
}

void datos()
{
    std::cout << "Programa para calcular si un numero es divisor de otro.\n";
    std::cout << "\nIngrese un numero: ";
    std::cin >> a;
    std::cout << "\nIngrese un numero: ";
    std::cin >> b;
}

void divisor(const int a, const int b)
{
    //condicional para verificar si el segundo digito ingresado es divisor del primero.
    if(a % b == 0)
        std::cout << "\nEl numero " << b << " es divisor de " << a << '\t';
    else
    {
        //condicional para verificar si el primer digito ingresado es divisor del segundo.
        if(b % a == 0)
                std::cout << "\nEl numero " << a << " es divisor de " << b << '\t';
        else
            std::cout << "\nNinguno de los dos numeros es divisor del otro\n";
    }
}
