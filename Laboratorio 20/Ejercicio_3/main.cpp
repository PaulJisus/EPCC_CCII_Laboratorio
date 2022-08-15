#include <iostream>
#include <memory>

#include "C1.h"
#include "C2.h"

using namespace std;

int main()
{
    std::shared_ptr<double> d = make_shared<double>(2.5);
    std::cout << *d << std::endl;
    C1 c_1(d);
    C2 c_2(d);
    std::cout << c_1 << std::endl;
    std::cout << c_2 << std::endl;
    std::cout << d.use_count() << std::endl;
    return 0;
}
