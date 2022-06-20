#include <iostream>

#include "Queue.h"

using namespace std;

Queue q1;

void Menu();
void Datos();
void Ingresar();
void Mostrar();

int main()
{
    Menu();
    Datos();
    return 0;
}

void Menu()
{
    std::cout << "\n\t ===============================\n";
    std::cout << "\t|\t\tMENU\t\t|\n";
    std::cout << "\t ===============================\n";
    std::cout << "\t|Numero |Opciones\t\t|\n";
    std::cout << "\t ===============================\n";
    std::cout << "\t|1.\t|Introducir valores.\t|\n";
    std::cout << "\t|2.\t|Mostrar.\t\t|\n";
    std::cout << "\t ===============================\n\n";
}

void Datos()
{
    unsigned int opcion{};
    std::string confirmacion{};
    do
    {
        std::cout << "Ingrese su Opcion(1 - 2):\n";
        std::cin >> opcion;
    switch (opcion)
    {
        case 1:
            Ingresar();
        break;
        case 2:
            Mostrar();
        break;
        default:
            std::cout << "Opcion invalida\n";
        break;
    }
    std::cout << "Desea continuar el programa:\n";
    std::cin >> confirmacion;
    } while (confirmacion == "s" || confirmacion == "S" || confirmacion == "si"
             || confirmacion == "SI"|| confirmacion == "Si" || confirmacion == "sI");
    std::cout << "Gracias por usar el programa.\n";
}

void Ingresar()
{
    unsigned int n{};
    int value{};
    std::string confirmacion{};
    do
    {
        std::cout << "Cantidad de elementos a ingresar:\n";
        std::cin >> n;
        for(unsigned int i{0}; i < n; i++)
        {
            std::cout << "Elemento a ingresar:\n";
            std::cin >> value;
            q1.enQueue(value);
        }
        std::cout << "Los " << n << " elementos fueron ingresados.\n";
        std::cout << "Desea continuar ingresando elementos:\n";
        std::cin >> confirmacion;
    }while (confirmacion == "s" || confirmacion == "S" || confirmacion == "si"
             || confirmacion == "SI"|| confirmacion == "Si" || confirmacion == "sI");
}

void Mostrar()
{
    try
    {
        std::cout << q1;
    }catch(const std::exception& e)
    {
        std::cerr << e.what();
    }
}
