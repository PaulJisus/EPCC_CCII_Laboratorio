#include <iostream>
#include <fstream>

#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList l1;
    l1.push_back(5);
    l1.push_back(7);
    l1.push_back(3);
    std::cout << l1;
    l1.push_back(9);
    std::cout << l1;
    l1.pop_front();
    std::cout << l1;
    l1.remove(3);
    std::cout << l1;
    l1.push_front(12);
    l1.push_front(20);
    std::cout << l1;
    l1.insert(0, 25);
    std::cout << l1;
    l1.insert(l1.getSize() - 1, 14);
    std::cout << l1;
    l1.insert(2, 16);
    std::cout << l1;
    l1.pop_back();
    std::cout << l1;
    l1.pop_position(2);
    std::cout << l1;
    l1.sort();
    std::cout << l1;
    LinkedList l2;
    int n{10000};
    for(int i{0}; i < n; i++)
    {
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
    archivo << "\nLista enlazada Ordenada Ascendentemente:\n";
    auto inicio = std::chrono::high_resolution_clock::now();
    l2.sort();
    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> float_ms = fin - inicio;
    archivo << l2;
    std::cout << "Tiempo de ordenamiento para " << n << " elementos =\t" << float_ms.count() << " ms " << std::endl;
    return 0;
}
