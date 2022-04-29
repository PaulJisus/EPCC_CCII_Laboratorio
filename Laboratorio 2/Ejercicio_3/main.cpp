#include <iostream>

using namespace std;

void datos();
void valores();

int main()
{
    datos();
    valores();
}

void datos()
{
    std::cout << "\n\tPrograma para hallar los multiplos de 5 comprendidos entre 1 y 100.\n";
    std::cout << "\t____________________________________________________________________\n";
    std::cout << "\nLos multiplos de 5 comprendidos entre 1 y 100 son:\n";
}

void valores()
{
    int num = 5;
    while(num <= 100)
    {
        std::cout << num << '\n';
        num+=5;
    }
}
