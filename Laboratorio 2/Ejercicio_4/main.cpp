#include <iostream>
#include <cmath>

using namespace std;

void datos();
bool primo(int);
void valores(int, int);

int x, y;

int main()
{
    datos();
    valores(x, y);
}

void datos()
{
    std::cout << "\n\tPrograma para hallar los primos entre x y y.\n";
    std::cout << "\t____________________________________________\n";
    std::cout << "\nIngrese el valor de x:\n";
    std::cin >> x;
    while(x > y)
    {
        std::cout << "\nIngrese el valor de y que sea mayor que x:\n";
        std::cin >> y;
    }
    std::cout << '\n';
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

void valores(int x, int y)
{
    int aux = 0;
    while(x != y)
    {
        if(primo(x))
        {
            std::cout << x << '\t';
            aux++;
        }
        x++;
    }
    if(aux == 0)
    {
        while(aux <= 0)
        {
            if(primo(x))
            {
                std::cout << x << '\n';
                aux++;
            }
            else if(primo(y))
            {
                std::cout << y << '\n';
                aux++;
            }
            x--;
            y++;
        }
    }
    std::cout << '\n';
}
