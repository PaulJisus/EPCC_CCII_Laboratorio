#include <iostream>

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
    return 0;
}
