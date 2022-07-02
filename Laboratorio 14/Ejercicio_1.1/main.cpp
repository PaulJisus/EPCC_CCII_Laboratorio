#include <string>
#include <iostream>
#include <limits>

using namespace std;

struct Producto{
    std::string codigo;
    std::string nombre;
    double precio;
    int stock;
};

struct Node {
    Producto data;
    struct Node *next;
};

void Insertaradelante(struct Node **node, Producto x)
{
    struct Node *nuevo = new Node();
    nuevo->next = *node;
    *node = nuevo;
}

void Insertar(struct Node **node, Producto x)
{
    struct Node *nuevo = new Node();
    if(nuevo)
    {
        nuevo->data = x;
        nuevo->next = *node;
        *node = nuevo;
    }
}

bool Buscar_nombre(struct Node *lista, std::string nombre)
{
    while (lista)
    {
        if(lista->data.nombre == nombre)
        {
            return true;
        }
        lista = lista->next;
    }
    return false;
}

bool Buscar_codigo(struct Node *lista, std::string codigo)
{
    while (lista)
    {
        if(lista->data.codigo == codigo)
        {
            return true;
        }
        lista = lista->next;
    }
    return false;
}

void Modificar_nombre(struct Node *lista, std::string nombre, std::string nombre_1)
{
   while (lista)
   {
        if(lista->data.nombre == nombre)
        {
            lista->data.nombre = nombre_1;
        }
        lista = lista->next;
   }
}

void Modificar_precio(struct Node *lista, std::string nombre, double precio)
{
   while (lista)
   {
        if(lista->data.nombre == nombre)
        {
            lista->data.precio = precio;
        }
        lista = lista->next;
   }
}

void Modificar_stock(struct Node *lista, std::string nombre, int stock)
{
   while (lista)
   {
        if(lista->data.nombre == nombre)
        {
            lista->data.stock = stock;
        }
        lista = lista->next;
   }
}

void Mostrar(struct Node *lista)
{
    while(lista) {
        std::cout << "\nCodigo:\t\t" << lista->data.codigo;
        std::cout << "\nNombre:\t\t" << lista->data.nombre;
        std::cout << "\nPrecio:\t\t" << lista->data.precio;
        std::cout << "\nStock:\t\t" << lista->data.stock;
        if(lista->data.stock == 0)
        {
            std::cout << "\nDisponible:\tNO\n";
        }
        else
        {
            std::cout << "\nDisponible:\tSI\n";
        }
        lista = lista->next;
    }
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
    std::cout << "\t|3.\t|Modificar Nombre.\t|\n";
    std::cout << "\t|4.\t|Modificar Precio.\t|\n";
    std::cout << "\t|5.\t|Modificar Stock.\t|\n";
    std::cout << "\t|6.\t|Buscar por Nombre.\t|\n";
    std::cout << "\t|7.\t|Buscar por Codigo.\t|\n";
    std::cout << "\t|8.\t|Mostrar.\t\t|\n";
    std::cout << "\t ===============================\n\n";
}

int main() {
    struct Node *lista = NULL;
    Producto p1{};
    unsigned int opcion{};
    Menu();
    std::string confirmacion{}, confirmacion2{};
    do
    {
        std::cout << "Ingrese su Opcion(1 - 8):\n";
        std::cin >> opcion;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    switch (opcion)
    {
        case 1:
        {
            std::string codigo{}, nombre{};
            double precio{};
            int stock{};
            std::cout << "Ingrese el codigo del producto:\n";
            getline(std::cin, codigo);
            p1.codigo = codigo;
            std::cout << "Ingrese el nombre del producto:\n";
            getline(std::cin, nombre);
            p1.nombre = nombre;
            std::cout << "Ingrese el precio del producto:\n";
            std::cin >> precio;
            p1.precio = precio;
            std::cout << "Ingrese el stock del producto:\n";
            std::cin >> stock;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            p1.stock = stock;
            Insertar(&lista, p1);
            std::cout << "Producto dado de Alta.\n";
        }
        break;
        case 2:
        {
            std::string nombre{};
            std::cout << "Ingrese el nombre del producto a dar de baja:\n";
            getline(std::cin, nombre);
            p1.nombre = nombre;
            Modificar_stock(lista, nombre, 0);
            std::cout << "Producto dado de baja.\n";
        }
        break;
        case 3:
        {
            std::string nombre{}, nombre_1{};
            std::cout << "Ingrese el nombre del producto del que desea modificar el nombre:\n";
            getline(std::cin, nombre);
            std::cout << "Ingrese el nuevo nombre del producto:\n";
            getline(std::cin, nombre_1);
            Modificar_nombre(lista, nombre, nombre_1);
            std::cout << "Producto cambiado de nombre.\n";
        }
        break;
        case 4:
        {
            std::string nombre{};
            double precio{};
            std::cout << "Ingrese el nombre del producto del que desea modificar el precio:\n";
            getline(std::cin, nombre);
            std::cout << "Ingrese el nuevo precio del producto:\n";
            std::cin >> precio;
            Modificar_precio(lista, nombre, precio);
            std::cout << "Producto cambiado de precio.\n";
        }
        break;
        case 5:
        {
            std::string nombre{};
            int stock{};
            std::cout << "Ingrese el nombre del producto del que desea modificar el stock:\n";
            getline(std::cin, nombre);
            std::cout << "Ingrese el nuevo stock del producto:\n";
            std::cin >> stock;
            Modificar_stock(lista, nombre, stock);
            std::cout << "Producto cambiado de stock.\n";
        }
        break;
        case 6:
        {
            std::string nombre{};
            std::cout << "Ingrese el nombre del producto a buscar:\n";
            getline(std::cin, nombre);
            if(Buscar_nombre(lista, nombre))
            {
                std::cout << "Producto Encontrado.\n";
            }
            else
            {
                std::cout << "Producto no Encontrado.\n";
            }
        }
        break;
        case 7:
        {
            std::string codigo{};
            std::cout << "Ingrese el codigo del producto a buscar:\n";
            getline(std::cin, codigo);
            if(Buscar_codigo(lista, codigo))
            {
                std::cout << "Producto Encontrado.\n";
            }
            else
            {
                std::cout << "Producto no Encontrado.\n";
            }
        }
        break;
        case 8:
        {
            std::cout << "\n\tEsta es la lista de productos.\n";
            Mostrar(lista);
        }
        break;
        default:
            std::cout << "Opcion invalida";
        break;
    }
    std::cout << "\nDesea continuar el programa:\n";
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
             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Gracias por usar el programa.\n";
}
