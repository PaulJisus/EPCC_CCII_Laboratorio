#include <iostream>
#include <fstream>

#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList l1;
    //Insertar al final.
    l1.push_back(5);
    //Insertar al final.
    l1.push_back(7);
    //Insertar al final.
    l1.push_back(3);
    std::cout << l1;
    //Insertar al final.
    l1.push_back(9);
    std::cout << l1;
    //Eliminar al inicio.
    l1.pop_front();
    std::cout << l1;
    //Eliminar por valor.
    l1.remove(3);
    std::cout << l1;
    //Insertar al inicio.
    l1.push_front(12);
    //Insertar al inicio.
    l1.push_front(20);
    std::cout << l1;
    //Insertar por posicion.
    l1.insert(0, 25);
    std::cout << l1;
    //Insertar por posicion.
    l1.insert(l1.getSize() - 1, 14);
    std::cout << l1;
    //Insertar por posicion.
    l1.insert(2, 16);
    std::cout << l1;
    //Eliminar al final.
    l1.pop_back();
    std::cout << l1;
    //Eliminar por posicion.
    l1.pop_position(2);
    std::cout << l1;
    //Ordenar ascendentemente.
    l1.sort();
    std::cout << l1;
    //Ordenar descendentemente.
    l1.descendent_sort();
    std::cout << l1;
    //Invertir la lista.
    l1.reverse();
    std::cout << l1;
    //Eliminar por rango.
    l1.erase(2, 4);
    std::cout << l1;
    LinkedList l2;
    int n{10000};
    for(int i{0}; i < n; i++)
    {
        //Insertar un elemento aleatorio al final.
        l2.push_random();
    }
    ofstream archivo;
    archivo.open("resultado.txt",ios::out);
    if(archivo.fail())
    {
        cout << "Error al abrir archivo";
        exit(1);
    }
    archivo << "\nLista enlazada con valores aleatorios:\n";
    archivo << l2;
    archivo << "\nLista enlazada Ordenada Descendentemente:\n";
    auto inicio = std::chrono::high_resolution_clock::now();
    //Ordenar descendentemente.
    l2.descendent_sort();
    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> float_ms = fin - inicio;
    archivo << l2;
    std::cout << "Tiempo de ordenamiento para " << n << " elementos =\t" << float_ms.count() << " ms " << std::endl;
    return 0;
}
