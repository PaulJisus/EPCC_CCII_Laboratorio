#include <iostream>

using namespace std;

template<int n>
struct sumaD
{
    enum{ valor = (n%10) + (sumaD<n/10>::valor)};
};

template<>
struct sumaD <0>
{
    enum{ valor = 0 };
};

int main()
{
    int x {sumaD<15894>::valor};
    std::cout << x << "\n";
    return 0;
}
