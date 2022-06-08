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
    return 0;
}
