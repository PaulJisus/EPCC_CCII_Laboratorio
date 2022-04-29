#include <iostream>

using namespace std;

void datos();
int suma(int *);
void mostrar(int *);

int *num = nullptr;

int main()
{
    //llamada a la funcion de ingreso de datos
    datos();
    //llamada a la funcion que mostrara el resultado
    mostrar(num);
    //se libera la memoria.
    delete[]num;
}

void datos()
{
    std::cout << "Programa para sumar los numeros negativos de una lista de 10.\n";
    num = new int[10];
    for(int i = 0; i < 10; i++)
    {
        std::cout << "\nIngrese el numero " << i + 1 << ": ";
        std::cin >> *(num + i);
    }
}

int suma(int *num)
{
    int suma;
    for(int i = 0; i < 10; i++)
    {
        //condicional para verificar si el numero es negativo
        if(*(num + i) < 0)
            //se suma el numero negstivo
            suma += *(num + i);
    }
    return suma;
}

void mostrar(int *num)
{
    std::cout << "De los siguientes numeros introducidos:\n";
    for(int i = 0; i < 10; i++)
    {
        std::cout << *(num + i) << '\t';
    }
    std::cout << "\nSe obtuvieron los siguientes numeros negativos:\n";
    for(int i = 0; i < 10; i++)
    {
        if(*(num + i) < 0)
        {
            std::cout << *(num + i) << '\t';
        }
    }
    std::cout << "\nSiendo la suma de los numeros negativos: \t" << suma(num);
}
