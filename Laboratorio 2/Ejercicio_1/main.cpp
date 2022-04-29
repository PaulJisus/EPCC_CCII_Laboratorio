#include <iostream>

using namespace std;

void datos();
int suma();

int main()
{
    datos();
    cout << '\n' << suma() << '\n';
}

void datos()
{
    std::cout << "\n\tPrograma para hallar la suma de los enteros pares desde 2 a 100.\n";
    std::cout << "\t________________________________________________________________\n";
    std::cout << "\nLa suma de los enteros pares desde 2 a 100 es:\n";
}

int suma()
{
    int valor = 0;
    for(int i = 2; i <= 100; i+=2)
        valor += i;
    return valor;
}
