#include <iostream>

using namespace std;

template< int n >
struct Binario
{
    enum{ valor = ( Binario<n/2>::valor ) * 10 + ( n % 2) };
};

template<>
struct Binario<0>
{
    enum{ valor = 0 };

};

int main()
{
    int n = Binario<66>::valor;
    std::cout << n;
    return 0;
}
