#include <iostream>
#include <cmath>

bool primo(int);

using namespace std;
int main()
{
    int primos[100];
    int num = 3;
    int aux = 0;
    int i = 1;
    primos[0] = 2;
    while(aux != 99)
    {
        if(primo(num))
        {
            primos[i] = num;
            aux++;
            i++;
        }
        num+=2;
    }
    for(int j = 99; j >= 0; j--)
    {
        std::cout << primos[j] << '\t';
    }
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
