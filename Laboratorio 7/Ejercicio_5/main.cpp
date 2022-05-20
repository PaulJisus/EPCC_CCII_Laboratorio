#include <iostream>

#include "Factorial.h"

using namespace std;

int main()
{
    Factorial f1(8);
    Factorial f2(5);
    Base b1 = f1 - f2;
    Base b2 = f1 + f2;
    Base b3 = f1 * f2;
    Base b4 = f1 / f2;
    std::cout << f1;
    std::cout << f2;
    std::cout << "\nResta:\n" << b1;
    std::cout << "\nSuma:\n" << b2;
    std::cout << "\nMultiplicacion:\n" << b3;
    std::cout << "\nDivision:\n" << b4;
    return 0;
}
