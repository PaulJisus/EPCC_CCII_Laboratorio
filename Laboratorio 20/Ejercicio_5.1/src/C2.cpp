#include "C2.h"

C2::C2() = default;

C2::C2(std::shared_ptr<double> value)
{
    this->d = value;
}

C2::C2(const C2 &o)
{
    this->d = o.d;
}

std::shared_ptr<double> C2::getD() const
{
    std::shared_ptr<double> c_2 = d.lock();
    return c_2;
}

void C2::print() const
{
    std::shared_ptr<double> c_1 = d.lock();
    std::cout << "Valor " << *c_1;
}

C2::~C2()
{
    std::cout << "\nC2 destructor\n";
}

std::ostream& operator<<(std::ostream &output, const C2 &o)
{
    output << "Valor " << *o.getD() << "\n";
    return output;
}
