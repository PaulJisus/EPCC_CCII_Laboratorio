#include <iostream>

#include "Stack.h"

using namespace std;

Stack s1;

void Menu();
void Datos();
void Ingresar();
void Eliminar();
void Top();
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
    std::cout << "\t|2.\t|Eliminar valores.\t|\n";
    std::cout << "\t|3.\t|Top.\t\t\t|\n";
    std::cout << "\t|4.\t|Mostrar.\t\t|\n";
    std::cout << "\t ===============================\n\n";
}

void Datos()
{
    unsigned int opcion{};
    std::string confirmacion{};
    do
    {
        std::cout << "Ingrese su Opcion(1 - 4):\n";
        std::cin >> opcion;
    switch (opcion)
    {
        case 1:
            Ingresar();
        break;
        case 2:
            Eliminar();
        break;
        case 3:
            Top();
        break;
        case 4:
            Mostrar();
        break;
        default:
            std::cout << "Opcion invalida";
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
            s1.push(value);
        }
        std::cout << "Los " << n << " elementos fueron ingresados.\n";
        std::cout << "Desea continuar ingresando elementos:\n";
        std::cin >> confirmacion;
    }while (confirmacion == "s" || confirmacion == "S" || confirmacion == "si"
             || confirmacion == "SI"|| confirmacion == "Si" || confirmacion == "sI");
}

void Eliminar()
{
    unsigned int n{};
    std::string confirmacion{};
    do
    {
        std::cout << "Cantidad de elementos a eliminar:\n";
        std::cin >> n;
        for(unsigned int i{0}; i < n; i++)
        {
            try
            {
                std::cout << "Elemento: " << *s1.pop() << " eliminado.\n";
            }catch(const std::exception& e)
            {
                std::cerr << e.what();
            }
        }
        std::cout << "Los " << n << " elementos fueron eliminados.\n";
        std::cout << "Desea continuar eliminando elementos:\n";
        std::cin >> confirmacion;
    }while (confirmacion == "s" || confirmacion == "S" || confirmacion == "si"
             || confirmacion == "SI"|| confirmacion == "Si" || confirmacion == "sI");
}

void Top()
{
    try
    {
        std::cout << "Elemento: " << *s1.top() << " en la cima de la pila.\n";
    }catch(const std::exception& e)
    {
        std::cerr << e.what();
    }
}

void Mostrar()
{
    try
    {
        std::cout << s1;
    }catch(const std::exception& e)
    {
        std::cerr << e.what();
    }
}
