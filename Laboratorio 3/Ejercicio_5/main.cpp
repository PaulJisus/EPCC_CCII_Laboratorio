#include <iostream>
#include <cmath>

using namespace std;

void datos();
bool espar(int);
int suma(int);

int x = 0;

int main()
{
    datos();
    std::cout << "La suma de los numeros impares desde 0 hasta " << x << " es: " << suma(x) << '\n';
    return 0;
}

void datos()
{
    std::cout << "\nIngrese un numero entre 0 y 100:\n";
    std::cin >> x;
    while(x < 0 || x > 100 || !espar(x) )
    {
        std::cout << "\nIngrese un numero entre 0 y 100:\n";
        std::cin >> x;
    }
    std::cout << '\n';
}

bool espar(int x)
{
    if(x%2 == 0)
    {
        return true;
    }
    return false;
}

int suma(int x)
{
    int valor = 0;
    for(int i = 1; i <= x; i+=2)
    {
        valor += i;
    }
    return valor;
}
