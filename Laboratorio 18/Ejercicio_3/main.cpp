#include <iostream>

using namespace std;

template<int n, int m>
struct potencia
{
    enum { valor = n * potencia<n, m - 1>::valor };
};

template<int n>
struct potencia<n, 0>
{
    enum { valor = 1 };
};

int main()
{
    const int x{10}, y{5};
    std::cout << potencia<x, y>::valor << std::endl;
    return 0;
}
