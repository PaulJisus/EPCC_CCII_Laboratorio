#include <iostream>
#include <cmath>

using namespace std;

void datos();
bool primo(int);
void valores(int);

int x;

int main()
{
    datos();
    valores(x);
}

void datos()
{
    std::cout << "\n\tPrograma para hallar los numeros primos de 1 hasta x.\n";
    std::cout << "\t____________________________________________\n";
    std::cout << "\nIngrese el valor de x:\n";
    std::cin >> x;
}

bool primo(int num)
{
    for(int i = 2; i <= sqrt(num); i++)
    {
        if(num % i == 0)
            return false;
    }
    return true;
}

void valores(int x)
{
    int num = 1;
    std::cout << "\n2\t";
    while(num <= x)
    {
        if(primo(num))
        {
            std::cout << num << '\t';
        }
        num+=2;
    }
    std::cout << '\n';
}
