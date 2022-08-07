#include <iostream>

using namespace std;

template<int n>
struct fibonacci
{
    enum { valor = fibonacci<n-1>::valor + fibonacci<n-2>::valor };
};

template<>
struct fibonacci<1>
{
    enum { valor = 1 };
};

template<>
struct fibonacci<0>
{
    enum { valor = 0 };
};

int main()
{
    const int x{10};
    std::cout << fibonacci<x - 1>::valor << std::endl;
    return 0;
}
