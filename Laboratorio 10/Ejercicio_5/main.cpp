#include <iostream>
#include <string>

#include "LinkedList.h"

using namespace std;

LinkedList l1;

void Menu();
void Datos();
void Ingresar();
void SubmenuIngresar();
void Eliminar();
void SubmenuEliminar();
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
    std::cout << "\t|2.\t|Eliminar valores.\t|\n";
    std::cout << "\t|3.\t|Obtener Nodo.\t\t|\n";
    std::cout << "\t|4.\t|Buscar.\t\t|\n";
    std::cout << "\t|5.\t|Mostrar.\t\t|\n";
    std::cout << "\t ===============================\n\n";
}

void Datos()
{
    unsigned int opcion{};
    std::string confirmacion{};
    do
    {
        std::cout << "Ingrese su Opcion(1 - 5):\n";
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
            ObtenerNodo();
        break;
        case 4:
            Buscar();
        break;
        case 5:
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
        std::cout << "Ingrese su Opcion(1 - 3):\n";
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
        case 3:
        {
            unsigned int n{};
            int value{}, pos{};
            std::cout << "Cantidad de elementos a ingresar por posicion:\n";
            std::cin >> n;
            for(unsigned int i{0}; i < n; i++)
            {
                std::cout << "Elemento a ingresar:\n";
                std::cin >> value;
                std::cout << "Posicion a ingresar:\n";
                std::cin >> pos;
                try
                {
                    l1.insert(pos, value);
                }catch(const std::exception& e)
                {
                    std::cout << e.what();
                }
            }
            std::cout << "Los " << n << " elementos fueron ingresados por posicion.\n";
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
    std::cout << "\t|3.\t|Ingresar por Posicion.\t|\n";
    std::cout << "\t ===============================\n\n";
}

void Eliminar()
{
    SubmenuEliminar();
    unsigned int opcion{};
    std::string confirmacion{};
    do
    {
        std::cout << "Ingrese su Opcion(1 - 3):\n";
        std::cin >> opcion;
    switch(opcion)
    {
        case 1:
        {
            try
            {
                l1.pop_front();
            }catch(const std::exception& e)
            {
                std::cout << e.what();
            }
            std::cout << "Primer elemento eliminado.\n";
        }
        break;
        case 2:
        {
            try
            {
                l1.pop_back();
            }catch(const std::exception& e)
            {
                std::cout << e.what();
            }
            std::cout << "Ultimo elemento eliminado.\n";
        }
        break;
        case 3:
        {
            int value{};
            std::cout << "Elemento a eliminar:\n";
            std::cin >> value;
            try
            {
                l1.remove(value);
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
    std::cout << "Desea continuar para Eliminar Elementos:\n";
    std::cin >> confirmacion;
    } while (confirmacion == "s" || confirmacion == "S" || confirmacion == "si"
             || confirmacion == "SI"|| confirmacion == "Si" || confirmacion == "sI");
}

void SubmenuEliminar()
{
    std::cout << "\n\t =======================================\n";
    std::cout << "\t|\t\tMENU\t\t\t|\n";
    std::cout << "\t =======================================\n";
    std::cout << "\t|Numero |\tOpciones\t\t|\n";
    std::cout << "\t =======================================\n";
    std::cout << "\t|1.\t|Eliminar Primer elemento.\t|\n";
    std::cout << "\t|2.\t|Eliminar Ultimo elemento.\t|\n";
    std::cout << "\t|3.\t|Eliminar por Valor.\t\t|\n";
    std::cout << "\t =======================================\n\n";
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

