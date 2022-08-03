#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <limits>
#include <random>
#include <utility>

#include "LinkedList.h"

using namespace std;

LinkedList<double> l1;
ofstream archivo;

void Menu();
void Datos();
void Ingresar();
void SubmenuIngresar();
void Eliminar();
void SubmenuEliminar();
void ObtenerNodo();
void SubmenuObtener();
void Buscar();
void Ordenar();
void SubmenuOrdenar();
void Mostrar();
void SubmenuMostrar();

static auto rng = []{
    std::mt19937 rng;
    rng.seed(std::chrono::system_clock::now().time_since_epoch().count());
    return rng;
}();

template <typename T,
          template<typename> typename Distribution
                                      = std::uniform_int_distribution,
          typename... Args>
T random(Args&&... args)
{
    Distribution<T> dist(std::forward<Args>(args)...);
    return dist(rng);
}

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
    std::cout << "\t|5.\t|Ordenar.\t\t|\n";
    std::cout << "\t|6.\t|Mostrar.\t\t|\n";
    std::cout << "\t ===============================\n\n";
}

void Datos()
{
    unsigned int opcion{};
    std::string confirmacion{}, confirmacion2{};
    do
    {
        std::cout << "Ingrese su Opcion(1 - 6):\n";
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
            Ordenar();
        break;
        case 6:
            Mostrar();
        break;
        default:
            std::cout << "Opcion invalida";
        break;
    }
    std::cout << "Desea continuar el programa:\n";
    std::cin >> confirmacion;
    std::cout << "Desea visualizar nuevamente las opciones:\n";
    std::cin >> confirmacion2;
    if(confirmacion2 == "s" || confirmacion2 == "S" || confirmacion2 == "si"
            || confirmacion2 == "SI"|| confirmacion2 == "Si" || confirmacion2 == "sI")
    {
        Menu();
    }
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
        std::cout << "Ingrese su Opcion(1 - 4):\n";
        std::cin >> opcion;
    switch(opcion)
    {
        case 1:
        {
            unsigned int n{};
            double value{};
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
            double value{};
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
            double value{};
            int pos{};
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
        case 4:
        {
            unsigned int n{};
            std::cout << "Cantidad de elementos aleatorios a ingresar:\n";
            std::cin >> n;
            for(unsigned int i{0}; i < n; i++)
            {
                l1.push_back(random<double, std::normal_distribution>(INT_MIN, INT_MAX));
            }
            std::cout << "Los " << n << " elementos aleatorios fueron ingresados.\n";
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
    std::cout << "\n\t =======================================\n";
    std::cout << "\t|\t\tMENU\t\t\t|\n";
    std::cout << "\t =======================================\n";
    std::cout << "\t|Numero |\tOpciones\t\t|\n";
    std::cout << "\t =======================================\n";
    std::cout << "\t|1.\t|Ingresar al Inicio.\t\t|\n";
    std::cout << "\t|2.\t|Ingresar al Final.\t\t|\n";
    std::cout << "\t|3.\t|Ingresar por Posicion.\t\t|\n";
    std::cout << "\t|4.\t|Ingresar elementos aleatorios.\t|\n";
    std::cout << "\t =======================================\n\n";
}

void Eliminar()
{
    SubmenuEliminar();
    unsigned int opcion{};
    std::string confirmacion{};
    do
    {
        std::cout << "Ingrese su Opcion(1 - 5):\n";
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
            double value{};
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
        case 4:
        {
            int pos{};
            std::cout << "Posicion del elemento a eliminar:\n";
            std::cin >> pos;
            try
            {
                l1.pop_position(pos);
            }catch(const std::exception& e)
            {
                std::cout << e.what();
            }
        }
        case 5:
        {
            int pos1{}, pos2{};
            std::cout << "Posicion inicial del rango:\n";
            std::cin >> pos1;
            std::cout << "Posicion final del rango:\n";
            std::cin >> pos2;
            try
            {
                l1.erase(pos1, pos2);
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
    std::cout << "\t|4.\t|Eliminar por Posicion.\t\t|\n";
    std::cout << "\t|5.\t|Eliminar por Rango.\t\t|\n";
    std::cout << "\t =======================================\n\n";
}

void ObtenerNodo()
{
    SubmenuObtener();
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
                Node<double> *aux = l1.front();
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
                Node<double> *aux = l1.back();
                std::cout << *aux;
            }catch(const std::exception& e)
            {
                std::cout << e.what();
            }
        }
        break;
        case 3:
        {
            int pos{};
            std::cout << "Ingrese la posicion del elemento a obtener.\n";
            std::cin >> pos;
            try
            {
                Node<double> *aux = l1.position(pos);
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
    std::cout << "\n\t =======================================\n";
    std::cout << "\t|\t\tMENU\t\t\t|\n";
    std::cout << "\t =======================================\n";
    std::cout << "\t|Numero |\tOpciones\t\t|\n";
    std::cout << "\t =======================================\n";
    std::cout << "\t|1.\t|Obtener Nodo Inicial.\t\t|\n";
    std::cout << "\t|2.\t|Obtener Nodo Final.\t\t|\n";
    std::cout << "\t|3.\t|Obtener Nodo por Posicion.\t|\n";
    std::cout << "\t =======================================\n\n";
}

void Buscar()
{
    double value{};
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

void Ordenar()
{
    SubmenuOrdenar();
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
                auto inicio = std::chrono::high_resolution_clock::now();
                l1.sort();
                auto fin = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double, std::milli> float_ms = fin - inicio;
                std::cout << "Tiempo de ordenamiento para " << l1.getSize() << " elementos es de " << float_ms.count() << " ms " << std::endl;
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
                auto inicio = std::chrono::high_resolution_clock::now();
                l1.descendent_sort();
                auto fin = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double, std::milli> float_ms = fin - inicio;
                std::cout << "Tiempo de ordenamiento para " << l1.getSize() << " elementos es de " << float_ms.count() << " ms " << std::endl;
            }catch(const std::exception& e)
            {
                std::cout << e.what();
            }
        }
        break;
        case 3:
        {
            try
            {
                l1.reverse();
            }catch(const std::exception& e)
            {
                std::cout << e.what();
            }
        }
        default:
            std::cout << "Opcion invalida";
        break;
    } std::cout << "Desea continuar Ordenando:\n";
        std::cin >> confirmacion;
    } while (confirmacion == "s" || confirmacion == "S" || confirmacion == "si"
             || confirmacion == "SI"|| confirmacion == "Si" || confirmacion == "sI");
}

void SubmenuOrdenar()
{
    std::cout << "\n\t =======================================\n";
    std::cout << "\t|\t\tMENU\t\t\t|\n";
    std::cout << "\t =======================================\n";
    std::cout << "\t|Numero |\tOpciones\t\t|\n";
    std::cout << "\t =======================================\n";
    std::cout << "\t|1.\t|Ordenar Ascendentemente.\t|\n";
    std::cout << "\t|2.\t|Ordenar Descendentemente.\t|\n";
    std::cout << "\t|3.\t|Invertir Lista.\t\t|\n";
    std::cout << "\t =======================================\n\n";
}


void Mostrar()
{
    SubmenuMostrar();
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
                std::cout << l1;
            }catch(const std::exception& e)
            {
                std::cout << e.what();
            }
        }
        break;
        case 2:
        {
            archivo.open("resultado.txt",ios::out);
            if(archivo.fail())
            {
                cout << "Error al abrir archivo";
                exit(1);
            }
            try
            {
                archivo << l1;
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
    std::cout << "Desea continuar para Mostrar:\n";
    std::cin >> confirmacion;
    } while (confirmacion == "s" || confirmacion == "S" || confirmacion == "si"
             || confirmacion == "SI"|| confirmacion == "Si" || confirmacion == "sI");
}

void SubmenuMostrar()
{
    std::cout << "\n\t =======================================\n";
    std::cout << "\t|\t\tMENU\t\t\t|\n";
    std::cout << "\t =======================================\n";
    std::cout << "\t|Numero |\tOpciones\t\t|\n";
    std::cout << "\t =======================================\n";
    std::cout << "\t|1.\t|Mostrar en pantalla.\t\t|\n";
    std::cout << "\t|2.\t|Mostrar en archivo de texto.\t|\n";
    std::cout << "\t =======================================\n\n";
}
