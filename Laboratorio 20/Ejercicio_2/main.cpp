#include <iostream>
#include <memory>

#include "Point.h"

using namespace std;

int main()
{
    std::unique_ptr<double> d = std::make_unique<double>(1.0);
    std::unique_ptr<Point> pt = std::make_unique<Point>(1.0, 2.0);
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
    return 0;
}
