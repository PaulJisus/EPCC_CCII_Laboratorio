#include <iostream>
#include <string>

#include "Array.h"

using namespace std;

int main()
{
    Array<int> a1;
    a1.push_back(2);
    a1.push_back(6);
    a1.push_top(8);
    a1.push_back(9);
    a1.insert(5, 2);
    std::cout << a1;
    a1.pop_back();
    std::cout << a1;
    std::cout << a1[2];
    return 0;
}
