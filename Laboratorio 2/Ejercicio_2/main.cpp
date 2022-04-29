#include <iostream>
#include <cmath>

using namespace std;

void datos();
bool primo(int);
void valores();

int main()
{
    datos();
    valores();
}

void datos()
{
    std::cout << "\n\tPrograma para hallar los 50 primeros primos.\n";
    std::cout << "\t____________________________________________\n";
    std::cout << "\nLos 50 primeros numeros primos son:\n";
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

void valores()
{
    int num = 3;
    int aux = 0;
    std::cout << "2\t";
    while(aux != 49)
    {
        if(primo(num))
        {
            std::cout << num << '\t';
            aux++;
        }
        num+=2;
    }
    std::cout << '\n';
}
