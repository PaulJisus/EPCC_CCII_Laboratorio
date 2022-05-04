#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main()
{
    std::string nombre[10];
    float precio[10];
    int stock[10];
    int op = 1, i = 0;
    std::cout << "\n\tPrograma de gestion de una tienda.\n";
    while(op >= 1 && op <= 3)
    {
        std::cout << "\n\n\t\t\tMENU\n";
        std::cout << "\t =================================\n";
        std::cout << "\t|Numero |Opciones\t\t  |\n";
        std::cout << "\t =================================\n";
        std::cout << "\t|1.\t|Alta de producto.\t  |\n";
        std::cout << "\t|2.\t|Buscar por Nombre.\t  |\n";
        std::cout << "\t|3.\t|Modificar stock y precio.|\n";
        std::cout << "\t|4.\t|Salir.\t\t\t  |\n";
        std::cout << "\t =================================\n\n";
        std::cout << "Ingrese su opcion: ";
        std::cin >> op;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(op == 1)
        {
            if(i != 10)
            {
                std::cout << "Ingrese el nombre: ";
                std::getline(std::cin, nombre[i]);
                std::cout << "Ingrese el precio: ";
                std::cin >> precio[i];
                std::cout << "Ingrese el stock ";
                std::cin >> stock[i];
                i++;
                std::cout << "\n\tProducto registrado correctamente.\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else
            {
                std::cout << "\n\t¡¡¡Inventario lleno!!!\n";
            }
        }
        if(op == 2)
        {
            std::string aux = " ";
            std::cout << "Ingrese el nombre del producto a buscar: ";
            std::getline(std::cin, aux);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            for(int j = 0; j < 10; j++)
            {
                if(aux.compare(nombre[j]) == 0)
                {
                    std::cout << "\n\tProducto encontrado.\n";
                    std::cout << "\nNombre: " << nombre[j];
                    std::cout << "\nPrecio: " << precio[j];
                    std::cout << "\nStock: " << stock[j] << '\n';
                }
            }
            std::cout << '\n';
        }
        if(op == 3)
        {
            std::string aux = " ";
            std::cout << "Ingrese el nombre del producto a modificar: ";
            std::getline(std::cin, aux);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            for(int j = 0; j < 10; j++)
            {
                if(aux.compare(nombre[j]) == 0)
                {
                    std::cout << "\n\tProducto encontrado.\n";
                    std::cout << "Ingrese el precio: ";
                    std::cin >> precio[j];
                    std::cout << "Ingrese el stock ";
                    std::cin >> stock[j];
                    std::cout << "\n\tProducto modificado correctamente.\n";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
            std::cout << '\n';
        }
    }
    return 0;
}
