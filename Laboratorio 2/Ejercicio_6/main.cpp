#include <iostream>

using namespace std;

void datos();
void fibonacci(int n);

int n;

int main()
{
    datos();
    fibonacci(n);
}

void datos()
{
    while(n <= 1)
    {
        std::cout << "\n\tPrograma para generar la serie Fibonacci.\n";
        std::cout << "\t_________________________________________\n";
        std::cout << "Ingrese la cantidad de elementos de la serie Fibonacci que desea ver:\n";
        cin >> n;
    }
}

void fibonacci(int n)
{
    cout << "\nLos " << n << " primeros numeros de la serie de Fibonacci son:" << endl;
    int fib = 0;
    int aux = 1;
    std::cout << '0' << '\n';
    for(int i = 1; i < n; i++)
    {
        cout << aux << '\n';
        aux += fib;
        fib = aux - fib;
    }
    std::cout << '\n';
}
