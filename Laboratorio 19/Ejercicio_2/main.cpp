#include <iostream>
#include <vector>

#include "Find.h"

using namespace std;

template<typename Type>
void mostrar(vector<Type> &v)
{
    for (auto i{0}; i < v.size(); ++i) {
        std::cout << v.at(i) << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> v{};
    for(int i{1}, j{10}; i < 10, j > 0; i++, j--)
    {
        v.push_back(i);
        v.push_back(j);
    }
    std::cout << "Vector con valores iniciales:\n";
    mostrar(v);
    Find<int> find1;
    int valor = 4;
    std::vector<int> respuesta = find1(v.begin(), v.end(), valor);
    std::cout << "Vector con las posiciones del elemento " << valor << std::endl;
    mostrar(respuesta);
    return 0;
}
