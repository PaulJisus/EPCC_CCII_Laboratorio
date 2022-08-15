#include <iostream>
#include <memory>

#include "Point.h"

using namespace std;

int main()
{
    std::shared_ptr<double> d = std::make_shared<double>(1.0);
    std::shared_ptr<Point> pt = std::make_shared<Point>(1.0, 2.0);
    std::cout << *d << std::endl;
    std::cout << *pt << std::endl;
    *d = 2.0;
    (*pt).X(3.0);
    (*pt).Y(3.0);
    std::cout << *d << std::endl;
    std::cout << *pt << std::endl;
    pt->X(5.0);
    pt->Y(5.0);
    std::cout << *pt << std::endl;
    std::shared_ptr<Point> pt_1 = std::make_shared<Point>(5.0, 7.0);
    std::shared_ptr<Point> pt_2 = pt_1;
    std::shared_ptr<Point> pt_3 = pt_1;
    std::cout << *pt_1 << std::endl;
    std::cout << *pt_2 << std::endl;
    std::cout << *pt_3 << std::endl;
    std::shared_ptr<Point> pt_4 = std::make_shared<Point>(8.0, 7.0);
    std::shared_ptr<Point> pt_5 = pt_4;
    std::cout << *pt_4 << std::endl;
    std::cout << *pt_5 << std::endl;
    std::cout << pt_1.use_count() << std::endl;
    std::cout << pt_4.use_count() << std::endl;
    pt_3 = pt_4;
    std::cout << pt_1.use_count() << std::endl;
    std::cout << pt_4.use_count() << std::endl;
    return 0;
}

