#include <iostream>
#include "Linkedlist.h"
#include <ctime>

using namespace std;


int main()
{
    Linkedlist L;
    srand(time(NULL));
    for(int i = 0; i < 1000; i++)
    {
        int num = -1000 + rand() % (2001);
        L.insert(num);
    }
    cout << L;
    return 0;
}


/*
int **insertarNodo(int **, int);
void mostrar(int **);
int **eliminarNodo(int **);

int main()
{
    int **head = nullptr;
    head = insertarNodo(head,5);
    head = insertarNodo(head,7);
    head = insertarNodo(head,9);
    head = insertarNodo(head,8);
    head = insertarNodo(head,11);
    head = insertarNodo(head,14);
    head = insertarNodo(head,16);
    mostrar(head);
    head = eliminarNodo(head);
    mostrar(head);
    while ((head = eliminarNodo(head)) != nullptr);
    mostrar(head);
    return 0;
}

int **insertarNodo(int **head, int valor)
{
    int **nodo = new int*[2];
    nodo[0] = new int;
    *(nodo[0]) = valor;
    nodo[1] = nullptr;
    if (head == nullptr)
    {
        head = nodo;
    }
    else
    {
        int **aux;
        aux = head;
        while (aux[1]!= nullptr && (int **)aux[0] <= (int **)nodo[0])
        {
            std::cout << aux[0] << '\n';
            aux = (int **)aux[1];
        }
        aux[1] = (int *)nodo;
    }
    return head;
}

void mostrar(int **head)
{
    int **aux;
    aux = head;
    while (aux != nullptr)
    {
        std::cout << *(aux[0]) << " -> ";
        aux = (int **)aux[1];
    }
    std::cout << "NULL" << '\n';
}

int **eliminarNodo(int **head)
{
    int **aux;
    if (head != nullptr)
    {
        aux = (int **)head[1];
        delete[]head[0];
        //delete[]head[1];
        head = aux;
    }
    return head;
}*/
/*
#include <iostream>
#include <limits>
using namespace std;

int **leeNodo()
{
    int *valor, **Nodo;
    valor = new int;
    Nodo = new int*[2];
    std::cout << "ingrese el numero: ";
    std::cin >> *valor;
    Nodo[0] = valor;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    Nodo[1] = nullptr;
    return Nodo;
}

void mostrarNodo(int **Nodo)
{
    int *valor;
    valor = (int *)Nodo[0];
    std::cout << *valor << " -> ";
}

void eliminarNodo(int **Nodo)
{
    int *valor;
    valor = (int *)Nodo[0];
    delete valor;
}

void insertar(int **&lista, int **Nodo)
{
    int **aux = lista, **prev = nullptr;
    while(aux)
    {
        if((int *)aux[0] > (int *)Nodo[0])
            break;
        prev = aux;
        prev = (int **)aux[1];
    }
    Nodo[1] = (int *)aux;
    if(prev != nullptr)
    {
        prev[1] = (int *)Nodo;
    }
    else
    {
        lista = Nodo;
    }
}

void mostrar(int **lista)
{
    while(lista)
    {
        mostrarNodo(lista);
        {
            lista = (int **)lista[1];
        }
    }
}

void eliminar(int **&lista)
{
    int **aux;
    while(lista)
    {
        aux = lista;
        lista = (int **)lista[1];
        eliminarNodo(aux);
        delete aux;
    }
}


int main()
{
    int **lista = nullptr, **nodo, x{};
    while(x!=10)
    {
        nodo = leeNodo();
        if(nodo == nullptr)
        {
            break;
        }
        insertar(lista, nodo);
        x++;
    }
    mostrar(lista);
    eliminar(lista);
    return 0;
}
*/
