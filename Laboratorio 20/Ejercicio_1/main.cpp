#include <iostream>

#include "Point.h"

using namespace std;

int main()
{
    double* d = new double(1.0);
    Point* pt = new Point(1.0, 2.0);
    std::cout << *d << std::endl;
    std::cout << *pt << std::endl;
    *d = 2.0;
    (*pt).X(3.0);
    (*pt).Y(3.0);
    std::cout << *d << std::endl;
    std::cout << *pt << std::endl;
    pt->X(3.0);
    pt->Y(3.0);
    std::cout << *pt << std::endl;
    delete d;
    delete pt;
    return 0;
}
