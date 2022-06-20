#include <iostream>
#include <random>
#include <chrono>

#include "Queue.h"

using namespace std;

void Menu();
void Datos(Queue *, Queue *);
void Datos_Ejemplo(Queue *, Queue *);
void Ingresar_Datos(Queue *, Queue *);
void Datos_Aleatorios(Queue *, Queue *);
void Eliminar(Queue *, Queue *);
void Eliminar_Todo(Queue *, Queue *);
int Aleatorio();
void Iterar(Queue *, Queue *, unsigned int);
void Mostrari(Queue *, Queue *);
void Mostrarf(Queue *, Queue *);
void Mostrar(Queue *, Queue *, unsigned int);

auto eng = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine gen(eng);
    uniform_int_distribution<> rand_digits(1, 130);

int main()
{
    Queue *Hombres = new Queue();
    Queue *Mujeres = new Queue();
    Menu();
    Datos(Hombres, Mujeres);
    return 0;
}

void Menu()
{
    std::cout << "\n\t ===============================\n";
    std::cout << "\t|\t\tMENU\t\t|\n";
    std::cout << "\t ===============================\n";
    std::cout << "\t|Numero |Opciones\t\t|\n";
    std::cout << "\t ===============================\n";
    std::cout << "\t|1.\t|Datos del Ejemplo.\t|\n";
    std::cout << "\t|2.\t|Ingresar Datos.\t|\n";
    std::cout << "\t|3.\t|Datos Aleatorios.\t|\n";
    std::cout << "\t|4.\t|Eliminar.\t\t|\n";
    std::cout << "\t|5.\t|Eliminar Todo.\t\t|\n";
    std::cout << "\t ===============================\n\n";
}

void Datos(Queue *q1, Queue *q2)
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
            Datos_Ejemplo(q1, q2);
        break;
        case 2:
            Ingresar_Datos(q1, q2);
        break;
        case 3:
            Datos_Aleatorios(q1, q2);
        break;
        case 4:
            Eliminar(q1, q2);
        break;
        case 5:
            Eliminar_Todo(q1, q2);
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

void Datos_Ejemplo(Queue *q1, Queue *q2)
{
    q1->enQueue(20);
    q1->enQueue(15);
    q2->enQueue(13);
    q2->enQueue(18);
    q2->enQueue(23);
    unsigned int n{};
    std::cout << "\nIngrese la cantidad de Iteraciones:\n";
    std::cin >> n;
    Mostrari(q1, q2);
    Iterar(q1, q2, n);
    Mostrarf(q1, q2);
    Mostrar(q1, q2, n);
    //Eliminar_Todo(q1, q2);
}

void Ingresar_Datos(Queue *q1, Queue *q2)
{
    unsigned int n{};
    int value{};
    std::string confirmacion{};
    do
    {
        std::cout << "Cantidad de elementos a ingresar en la primera cola:\n";
        std::cin >> n;
        for(unsigned int i{0}; i < n; i++)
        {
            std::cout << "Elemento a ingresar:\n";
            std::cin >> value;
            q1->enQueue(value);
        }
        std::cout << "Los " << n << " elementos fueron ingresados en la primera cola.\n";
        std::cout << "Cantidad de elementos a ingresar en la segunda cola:\n";
        std::cin >> n;
        for(unsigned int i{0}; i < n; i++)
        {
            std::cout << "Elemento a ingresar:\n";
            std::cin >> value;
            q2->enQueue(value);
        }
        std::cout << "Los " << n << " elementos fueron ingresados en la segunda cola.\n";
        std::cout << "Desea continuar ingresando elementos:\n";
        std::cin >> confirmacion;
    }while (confirmacion == "s" || confirmacion == "S" || confirmacion == "si"
             || confirmacion == "SI"|| confirmacion == "Si" || confirmacion == "sI");
    unsigned int m{};
    std::cout << "\nIngrese la cantidad de Iteraciones:\n";
    std::cin >> m;
    Mostrari(q1, q2);
    Iterar(q1, q2, m);
    Mostrarf(q1, q2);
    Mostrar(q1, q2, m);
}

void Datos_Aleatorios(Queue *q1, Queue *q2)
{
    unsigned int n{};
    std::string confirmacion{};
    do
    {
        std::cout << "Cantidad de elementos a ingresar en la primera cola:\n";
        std::cin >> n;
        for(unsigned int i{0}; i < n; i++)
        {
            q1->enQueue(Aleatorio());
        }
        std::cout << "Los " << n << " elementos fueron ingresados en la primera cola.\n";
        std::cout << "Cantidad de elementos a ingresar en la segunda cola:\n";
        std::cin >> n;
        for(unsigned int i{0}; i < n; i++)
        {
            q2->enQueue(Aleatorio());
        }
        std::cout << "Los " << n << " elementos fueron ingresados en la segunda cola.\n";
        std::cout << "Desea continuar ingresando elementos:\n";
        std::cin >> confirmacion;
    }while (confirmacion == "s" || confirmacion == "S" || confirmacion == "si"
             || confirmacion == "SI"|| confirmacion == "Si" || confirmacion == "sI");
    unsigned int m{};
    std::cout << "\nIngrese la cantidad de Iteraciones:\n";
    std::cin >> m;
    Mostrari(q1, q2);
    Iterar(q1, q2, m);
    Mostrarf(q1, q2);
    Mostrar(q1, q2, m);
}

int Aleatorio()
{
    return rand_digits(gen);
}

void Eliminar(Queue *q1, Queue *q2)
{
    unsigned int n{};
    std::string confirmacion{};
    do
    {
        std::cout << "Cantidad de elementos a eliminar en la primera cola:\n";
        std::cin >> n;
        for(unsigned int i{0}; i < n; i++)
        {
            try
            {
                std::cout << "Elemento: " << *q1->deQueue() << " eliminado.\n";
            }catch(const std::exception& e)
            {
                std::cerr << e.what();
            }
        }
        std::cout << "Los " << n << " elementos fueron eliminados de la primera cola.\n";
        std::cout << "Cantidad de elementos a eliminar en la segunda cola:\n";
        std::cin >> n;
        for(unsigned int i{0}; i < n; i++)
        {
            try
            {
                std::cout << "Elemento: " << *q2->deQueue() << " eliminado.\n";
            }catch(const std::exception& e)
            {
                std::cerr << e.what();
            }
        }
        std::cout << "Los " << n << " elementos fueron eliminados de la segunda cola.\n";
        std::cout << "Desea continuar eliminando elementos:\n";
        std::cin >> confirmacion;
    }while (confirmacion == "s" || confirmacion == "S" || confirmacion == "si"
             || confirmacion == "SI"|| confirmacion == "Si" || confirmacion == "sI");
}

void Eliminar_Todo(Queue *q1, Queue *q2)
{
    q1->clear();
    q2->clear();
    std::cout << "\nTodos los elementos de ambas colas fueron eliminados.\n\n";
}

void Mostrari(Queue *q1, Queue *q2)
{
    std::cout << "\n\tColas Iniciales.\n";
    std::cout << "\nHombres.\n\n";
    std::cout << *q1;
    std::cout << "\nMujeres.\n\n";
    std::cout << *q2;
}

void Mostrarf(Queue *q1, Queue *q2)
{
    std::cout << "\n\tColas despues de las Iteraciones.\n";
    std::cout << "\nHombres.\n\n";
    std::cout << *q1;
    std::cout << "\nMujeres.\n\n";
    std::cout << *q2;
}


void Iterar(Queue *q1, Queue *q2, unsigned int n)
{
    int aux_h{}, aux_m{};
    for(unsigned int i{}; i < n; i++)
    {
        aux_h = q1->front()->getValue();
        aux_m = q2->front()->getValue();
        q1->deQueue();
        q2->deQueue();
        q1->enQueue(aux_h);
        q2->enQueue(aux_m);
    }
}

void Mostrar(Queue *q1, Queue *q2, unsigned int n)
{
    std::cout << "\nResultado en la iteracion numero: " << n;
    if(q1->front()->getValue() == q2->front()->getValue())
    {
        std::cout << "\nIguales.\n";
    }
    else if(q1->front()->getValue() > q2->front()->getValue())
    {
        std::cout << "\nHombres.\n\n";
    }
    else
    {
        std::cout << "\nMujeres.\n\n";
    }
}
