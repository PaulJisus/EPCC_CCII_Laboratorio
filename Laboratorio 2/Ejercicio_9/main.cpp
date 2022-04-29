#include <iostream>

using namespace std;

void datos();
void piramide(int);

int n;

int main()
{
    datos();
    piramide(n);
}

void datos()
{
    std::cout << "\n\tPrograma para generar luna piramide de *.\n";
    std::cout << "\t_________________________________________\n";
    std::cout << "\nIngrese la altura de la piramide: ";
    std::cin >> n;
    std::cout << "\nLa piramide formada de altura " << n << " es:\n";
}

void piramide(int n)
{
    std::cout << '\n';
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            std::cout << '*';
        }
        std::cout << '\n';
    }
}
