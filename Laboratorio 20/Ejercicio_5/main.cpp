#include <iostream>
#include <memory>

#include "Point.h"

using namespace std;

int main()
{
    std::shared_ptr<double> d = std::make_shared<double>(1.0);
    std::weak_ptr<double> d_1 = d;
    std::shared_ptr<double> d_2 = d_1.lock();
    std::shared_ptr<Point> pt = std::make_shared<Point>(1.0, 2.0);
    std::weak_ptr<Point> pt_1 = pt;
    std::shared_ptr<Point> pt_2 = pt_1.lock();
    std::cout << *d_2 << std::endl;
    std::cout << *pt_2 << std::endl;
    *d = 2.0;
    (*pt).X(3.0);
    (*pt).Y(3.0);
    std::cout << *d_2 << std::endl;
    std::cout << *pt_2 << std::endl;
    pt->X(5.0);
    pt->Y(8.0);
    std::cout << *pt_2 << std::endl;
    return 0;
}
