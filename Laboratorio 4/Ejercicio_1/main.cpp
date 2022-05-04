#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main()
{
    std::string nombres[3];
    std::string apellidos[3];
    unsigned int edad[3];
    unsigned long dni[3];
    std::cout << "\nPor favor ingrese la siguiente informacion de las personas: \n";
    for(int i = 0; i < 3; i++)
    {
        std::cout << "\n******* Persona " << i + 1 << "********:\n";
        std::cout << "Nombre: ";
        std::getline(std::cin, nombres[i]);
        std::cout << "Apellidos: ";
        std::getline(std::cin, apellidos[i]);
        std::cout << "Edad: ";
        std::cin >> edad[i];
        std::cout << "DNI: ";
        std::cin >> dni[i];
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "\nLa informacion ingresada fue:\n";
    for(int i = 0; i < 3; i++)
    {
        std::cout << "\n\n******* Persona " << i + 1 << "********:\n";
        std::cout << "\nNombre: " << nombres[i];
        std::cout << "\nApellidos: " << apellidos[i];
        std::cout << "\nEdad: " << edad[i];
        std::cout << "\nDNI: " << dni[i];
    }
}

