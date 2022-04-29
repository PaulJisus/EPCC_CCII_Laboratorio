#include <iostream>
#include <string>

using namespace std;

void datos();
std::string binario(int);

int a;

int main()
{
    //llamada a la funcion de ingreso de datos
    datos();
    std::cout << "\nEl numero " << a << " convertido a binario es:" << binario(a) << '\n';
    return 0;
}

void datos()
{
    std::cout << "Programa para convertir un numero a binario.\n";
    //condicional para verificar si el numero esta entre los parámetros indicados
    while(a <= 100 || a >= 999)
    {
        std::cout << "\nIngrese un numero entre 100 y 999: ";
        std::cin >> a;
    }
}

std::string binario(int a)
{
    std::string res = " ";
    std::string aux = " ";
    //condicional para obtenere los dígitos binarios
    while(a != 0)
    {
        //se encuentra el modulo del número y dependiendo de ello se almacena un 1 o un 0
        if(a % 2 == 0)
            res += "0";
        else
            res += "1";
        //se divide el numero entre dos
        a /= 2;
    }
    size_t i = res.length();
    //condicional para invertir el resultado obtenido en el anterior bucle.
    while(i!=0)
    {
        aux += res.back();
        res.erase(i-1);
        i--;
    }
    res = aux;
    return res;
}

