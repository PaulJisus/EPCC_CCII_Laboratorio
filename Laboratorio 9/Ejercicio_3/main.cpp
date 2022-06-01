#include <iostream>
#include <string>

#include "Correo.h"

using namespace std;

void datos();

int main()
{
    datos();
    return 0;
}

void datos()
{
    int x{};
    while(x != 5)
    {
        std::cout << "\nDe la persona " << x + 1 << " ingrese sus datos.\n";
        Correo<char, std::string> c1;
        char letra{};
        std::string apellido{};
        std::cout << "Ingrese la primera letra de su nombre:\n";
        std::cin >> letra;
        c1.setLetra(letra);
        std::cout << "Ingrese su apellido:\n";
        std::cin >> apellido;
        c1.setApellido(apellido);
        std::cout << c1;
        x++;
    }
}
