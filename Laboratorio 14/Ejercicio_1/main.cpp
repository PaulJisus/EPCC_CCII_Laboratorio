#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <limits>

#include "LinkedList.h"
#include "Producto.h"

using namespace std;

LinkedList l1;
ofstream archivo;

void Menu();
void Datos();
void Ingresar();
void SubmenuIngresar();
void DarDeBaja();
void Eliminar();
void SubmenuEliminar();
void Modificar();
void SubmenuModificar();
void Obtener();
void SubmenuObtener();
void Buscar();
void SubmenuBuscar();
void Ordenar();
void SubmenuOrdenar();
void Mostrar();
void SubmenuMostrar();

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
    std::cout << "\t|1.\t|Dar de Alta.\t\t|\n";
    std::cout << "\t|2.\t|Dar de Baja.\t\t|\n";
    std::cout << "\t|3.\t|Eliminar Productos.\t|\n";
    std::cout << "\t|4.\t|Modificar.\t\t|\n";
    std::cout << "\t|5.\t|Obtener Informacion.\t|\n";
    std::cout << "\t|6.\t|Buscar.\t\t|\n";
    std::cout << "\t|7.\t|Ordenar.\t\t|\n";
    std::cout << "\t|8.\t|Mostrar.\t\t|\n";
    std::cout << "\t ===============================\n\n";
}

void Datos()
{
    unsigned int opcion{};
    std::string confirmacion{}, confirmacion2{};
    do
    {
        std::cout << "Ingrese su Opcion(1 - 8):\n";
        std::cin >> opcion;
    switch (opcion)
    {
        case 1:
            Ingresar();
        break;
        case 2:
            DarDeBaja();
        break;
        case 3:
            Eliminar();
        break;
        case 4:
            Modificar();
        break;
        case 5:
            Obtener();
        break;
        case 6:
            Buscar();
        break;
        case 7:
            Ordenar();
        break;
        case 8:
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
            Producto p1;
            std::string codigo{}, nombre{};
            double precio{};
            int stock{};
            std::cout << "Cantidad de productos a ingresar al inicio:\n";
            std::cin >> n;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            for(unsigned int i{0}; i < n; i++)
            {
                std::cout << "Producto a ingresar:\n";
                std::cout << "Ingrese el codigo del producto:\n";
                getline(std::cin, codigo);
                p1.setCodigo(codigo);
                std::cout << "Ingrese el nombre del producto:\n";
                getline(std::cin, nombre);
                p1.setNombre(nombre);
                std::cout << "Ingrese el precio del producto:\n";
                std::cin >> precio;
                p1.setPrecio(precio);
                std::cout << "Ingrese el stock del producto:\n";
                std::cin >> stock;
                p1.setStock(stock);
                l1.push_front(p1);
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            std::cout << "Los " << n << " productos fueron ingresados al inicio.\n";
        }
        break;
        case 2:
        {
            unsigned int n{};
            Producto p1;
            std::string codigo{}, nombre{};
            double precio{};
            int stock{};
            std::cout << "Cantidad de productos a ingresar al final:\n";
            std::cin >> n;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            for(unsigned int i{0}; i < n; i++)
            {
                std::cout << "Producto a ingresar:\n";
                std::cout << "Ingrese el codigo del producto:\n";
                getline(std::cin, codigo);
                p1.setCodigo(codigo);
                std::cout << "Ingrese el nombre del producto:\n";
                getline(std::cin, nombre);
                p1.setNombre(nombre);
                std::cout << "Ingrese el precio del producto:\n";
                std::cin >> precio;
                p1.setPrecio(precio);
                std::cout << "Ingrese el stock del producto:\n";
                std::cin >> stock;
                p1.setStock(stock);
                l1.push_back(p1);
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            std::cout << "Los " << n << " productos fueron ingresados al final.\n";
        }
        break;
        case 3:
        {
            unsigned int n{};
            Producto p1;
            std::string codigo{}, nombre{};
            double precio{};
            int stock{}, pos{};
            std::cout << "Cantidad de productos a ingresar por posicion:\n";
            std::cin >> n;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            for(unsigned int i{0}; i < n; i++)
            {
                std::cout << "Producto a ingresar:\n";
                std::cout << "Ingrese el codigo del producto:\n";
                getline(std::cin, codigo);
                p1.setCodigo(codigo);
                std::cout << "Ingrese el nombre del producto:\n";
                getline(std::cin, nombre);
                p1.setNombre(nombre);
                std::cout << "Ingrese el precio del producto:\n";
                std::cin >> precio;
                p1.setPrecio(precio);
                std::cout << "Ingrese el stock del producto:\n";
                std::cin >> stock;
                p1.setStock(stock);
                std::cout << "Posicion a ingresar:\n";
                std::cin >> pos;
                try
                {
                    l1.insert(pos, p1);
                }catch(const std::exception& e)
                {
                    std::cout << e.what();
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            std::cout << "Los " << n << " productos fueron ingresados por posicion.\n";
        }
        break;
        default:
            std::cout << "Opcion invalida";
        break;
    }
    std::cout << "Desea continuar para Dar de Alta Productos:\n";
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
    std::cout << "\t =======================================\n\n";
}

void DarDeBaja()
{
    std::string confirmacion{};
    do{
        std::string nombre{};
        int stock{0};
        std::cout << "Ingrese el nombre del Producto a Dar de Baja:\n";
        getline(std::cin, nombre);
        try
        {
            l1.change_stock(nombre, stock);
        }catch(const std::exception& e)
        {
            std::cout << e.what();
        }
        std::cout << "Desea continuar para Dar de Alta Productos:\n";
        std::cin >> confirmacion;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (confirmacion == "s" || confirmacion == "S" || confirmacion == "si"
             || confirmacion == "SI"|| confirmacion == "Si" || confirmacion == "sI");
}

void Eliminar()
{
    SubmenuEliminar();
    unsigned int opcion{};
    std::string confirmacion{};
    do
    {
        std::cout << "Ingrese su Opcion(1 - 6):\n";
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
            std::cout << "Primer Producto eliminado.\n";
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
            std::cout << "Ultimo Producto eliminado.\n";
        }
        break;
        case 3:
        {
            std::string codigo{};
            std::cout << "Ingrese el codigo del producto a eliminar:\n";
            getline(std::cin, codigo);
            try
            {
                l1.remove_code(codigo);
            }catch(const std::exception& e)
            {
                std::cout << e.what();
            }
        }
        break;
        case 4:
        {
            std::string nombre{};
            std::cout << "Ingrese el nombre del producto a eliminar:\n";
            getline(std::cin, nombre);
            try
            {
                l1.remove_name(nombre);
            }catch(const std::exception& e)
            {
                std::cout << e.what();
            }
        }
        break;
        case 5:
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
        case 6:
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
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
    std::cout << "\t|3.\t|Eliminar por Codigo.\t\t|\n";
    std::cout << "\t|4.\t|Eliminar por Nombre.\t\t|n";
    std::cout << "\t|5.\t|Eliminar por Posicion.\t\t|\n";
    std::cout << "\t|6.\t|Eliminar por Rango.\t\t|\n";
    std::cout << "\t =======================================\n\n";
}

void Modificar()
{
    SubmenuModificar();
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
            std::string nombre_1{}, nombre{};
            std::cout << "Ingrese el nombre del Producto a modificar:\n";
            getline(std::cin, nombre_1);
            std::cout << "Ingrese el nuevo nombre:\n";
            getline(std::cin, nombre);
            try
            {
                l1.change_name(nombre_1, nombre);
            }catch(const std::exception& e)
            {
                std::cout << e.what();
            }
        }
        break;
        case 2:
        {
            std::string nombre{};
            double precio{};
            std::cout << "Ingrese el nombre del Producto a modificar:\n";
            getline(std::cin, nombre);
            std::cout << "Ingrese el nuevo precio:\n";
            std::cin >> precio;
            try
            {
                l1.change_price(nombre, precio);
            }catch(const std::exception& e)
            {
                std::cout << e.what();
            }
        }
        break;
        case 3:
        {
            std::string nombre{};
            int stock{};
            std::cout << "Ingrese el nombre del Producto a modificar:\n";
            getline(std::cin, nombre);
            std::cout << "Ingrese el nuevo stock:\n";
            std::cin >> stock;
            try
            {
                l1.change_stock(nombre, stock);
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
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Desea continuar para modificar la informacion de un producto:\n";
    std::cin >> confirmacion;
    } while (confirmacion == "s" || confirmacion == "S" || confirmacion == "si"
             || confirmacion == "SI"|| confirmacion == "Si" || confirmacion == "sI");
}

void SubmenuModificar()
{
    std::cout << "\n\t =======================================\n";
    std::cout << "\t|\t\tMENU\t\t\t|\n";
    std::cout << "\t =======================================\n";
    std::cout << "\t|Numero |\tOpciones\t\t|\n";
    std::cout << "\t =======================================\n";
    std::cout << "\t|1.\t|Modificar Nombre.\t|\n";
    std::cout << "\t|2.\t|Modificar Precio.\t|\n";
    std::cout << "\t|3.\t|Modificar Stock.\t\t|\n";
    std::cout << "\t =======================================\n\n";
}

void Obtener()
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
        case 3:
        {
            int pos{};
            std::cout << "Ingrese la posicion del producto a obtener.\n";
            std::cin >> pos;
            try
            {
                Node *aux = l1.position(pos);
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
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Desea continuar para Obtener un informacion de un producto:\n";
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
    std::cout << "\t|1.\t|Obtener Producto Inicial.\t\t|\n";
    std::cout << "\t|2.\t|Obtener Producto Final.\t\t|\n";
    std::cout << "\t|3.\t|Obtener Producto por Posicion.\t|\n";
    std::cout << "\t =======================================\n\n";
}

void Buscar()
{
    SubmenuBuscar();
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
            std::string nombre{};
            std::cout << "Ingrese el nombre del Producto a Buscar:\n";
            getline(std::cin, nombre);
            if(l1.search_name(nombre))
            {
                std::cout << "Elemento encontrado.\n";
            }
            else
            {
                std::cout << "Elemento no encontrado.\n";
            }
        }
        break;
        case 2:
        {
            std::string codigo{};
            std::cout << "Ingrese el codigo del Producto a Buscar:\n";
            getline(std::cin, codigo);
            if(l1.search_code(codigo))
            {
                std::cout << "Elemento encontrado.\n";
            }
            else
            {
                std::cout << "Elemento no encontrado.\n";
            }
        }
        break;
        default:
            std::cout << "Opcion invalida";
        break;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Desea continuar para Mostrar:\n";
    std::cin >> confirmacion;
    } while (confirmacion == "s" || confirmacion == "S" || confirmacion == "si"
             || confirmacion == "SI"|| confirmacion == "Si" || confirmacion == "sI");
}

void SubmenuBuscar()
{
    std::cout << "\n\t =======================================\n";
    std::cout << "\t|\t\tMENU\t\t\t|\n";
    std::cout << "\t =======================================\n";
    std::cout << "\t|Numero |\tOpciones\t\t|\n";
    std::cout << "\t =======================================\n";
    std::cout << "\t|1.\t|Buscar Producto por Nombre.\t\t|\n";
    std::cout << "\t|2.\t|Obtener Producto por Codigo.\t\t|\n";
    std::cout << "\t =======================================\n\n";
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
                l1.sort();
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
                l1.descendent_sort();
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
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Desea continuar Ordenando:\n";
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
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
