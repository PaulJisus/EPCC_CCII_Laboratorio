#include <iostream>

using namespace std;

template<int n>
struct sumaD
{
    enum { valor = n + sumaD<n-1>::valor };
};

template<>
struct sumaD<1>
{
    enum { valor = 1 };
};

int main()
{
    std::cout << sumaD<10>::valor << std::endl;
    return 0;
}
