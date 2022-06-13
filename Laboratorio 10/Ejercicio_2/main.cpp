#include <iostream>
#include <string>

#include "LinkedList.h"

using namespace std;

LinkedList l1;

void Menu();
void Datos();
void Ingresar();
void SubmenuIngresar();
void ObtenerNodo();
void SubmenuObtener();
void Buscar();
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
    std::cout << "\t|2.\t|Obtener Nodo.\t\t|\n";
    std::cout << "\t|3.\t|Buscar.\t\t|\n";
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
            ObtenerNodo();
        break;
        case 3:
            Buscar();
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
    SubmenuIngresar();
    unsigned int opcion{};
    std::string confirmacion{};
    do
    {
        std::cout << "Ingrese su Opcion(1 - 2):\n";
        std::cin >> opcion;
    switch(opcion)
    {
        case 1:
        {
            unsigned int n{};
            int value{};
            std::cout << "Cantidad de elementos a ingresar al inicio:\n";
            std::cin >> n;
            for(unsigned int i{0}; i < n; i++)
            {
                std::cout << "Elemento a ingresar:\n";
                std::cin >> value;
                l1.push_front(value);
            }
            std::cout << "Los " << n << " elementos fueron ingresados al inicio.\n";
        }
        break;
        case 2:
        {
            unsigned int n{};
            int value{};
            std::cout << "Cantidad de elementos a ingresar al final:\n";
            std::cin >> n;
            for(unsigned int i{0}; i < n; i++)
            {
                std::cout << "Elemento a ingresar:\n";
                std::cin >> value;
                l1.push_back(value);
            }
            std::cout << "Los " << n << " elementos fueron ingresados al final.\n";
        }
        break;
        default:
            std::cout << "Opcion invalida";
        break;
    }
    std::cout << "Desea continuar para Ingresar Elementos:\n";
    std::cin >> confirmacion;
    } while (confirmacion == "s" || confirmacion == "S" || confirmacion == "si"
             || confirmacion == "SI"|| confirmacion == "Si" || confirmacion == "sI");
}

void SubmenuIngresar()
{
    std::cout << "\n\t ===============================\n";
    std::cout << "\t|\t\tMENU\t\t|\n";
    std::cout << "\t ===============================\n";
    std::cout << "\t|Numero |Opciones\t\t|\n";
    std::cout << "\t ===============================\n";
    std::cout << "\t|1.\t|Ingresar al Inicio.\t|\n";
    std::cout << "\t|2.\t|Ingresar al Final.\t|\n";
    std::cout << "\t ===============================\n\n";
}

void ObtenerNodo()
{
    SubmenuObtener();
    unsigned int opcion{};
    std::string confirmacion{};
    do
    {
        std::cout << "Ingrese su Opcion(1 - 2):\n";
        std::cin >> opcion;
    switch(opcion)
    {
        case 1:
        {
            try
            {
                Node *aux = l1.front();
                std::cout << *aux;
            }catch(const std::exception& e)
            {
                std::cout << e.what();
            }
        }
        break;
        case 2:
        {
            try
            {
                Node *aux = l1.back();
                std::cout << *aux;
            }catch(const std::exception& e)
            {
                std::cout << e.what();
            }
        }
        break;
        default:
            std::cout << "Opcion invalida";
        break;
    }
    std::cout << "Desea continuar para Obtener un Nodo:\n";
    std::cin >> confirmacion;
    } while (confirmacion == "s" || confirmacion == "S" || confirmacion == "si"
             || confirmacion == "SI"|| confirmacion == "Si" || confirmacion == "sI");
}

void SubmenuObtener()
{
    std::cout << "\n\t ===============================\n";
    std::cout << "\t|\t\tMENU\t\t|\n";
    std::cout << "\t ===============================\n";
    std::cout << "\t|Numero |Opciones\t\t|\n";
    std::cout << "\t ===============================\n";
    std::cout << "\t|1.\t|Obtener Nodo Inicial.\t|\n";
    std::cout << "\t|2.\t|Obtener Nodo Final.\t|\n";
    std::cout << "\t ===============================\n\n";
}

void Buscar()
{
    int value{};
    std::string confirmacion{};
    do
    {
        std::cout << "Ingrese el elemento a buscar:\n";
        std::cin >> value;
        if(l1.search(value))
        {
            std::cout << "Elemento encontrado.\n";
        }
        else
        {
            std::cout << "Elemento no encontrado.\n";
        }
        std::cout << "Desea continuar buscando:\n";
        std::cin >> confirmacion;
    } while (confirmacion == "s" || confirmacion == "S" || confirmacion == "si"
             || confirmacion == "SI"|| confirmacion == "Si" || confirmacion == "sI");
}

void Mostrar()
{
    try
    {
        std::cout << l1;
    }catch(const std::exception& e)
    {
        std::cout << e.what();
    }
}

