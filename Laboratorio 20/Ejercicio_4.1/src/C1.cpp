#include "C1.h"

C1::C1() = default;

C1::C1(std::shared_ptr<double> value)
{
    this->d = value;
}

C1::C1(const C1 &o)
{
    this->d = o.d;
}

std::shared_ptr<double> C1::getD() const
{
    return this->d;
}

void C1::print() const
{
    std::cout << "Valor " << *d;
}

C1::~C1()
{
    std::cout << "\nC1 destructor\n";
}

std::ostream& operator<<(std::ostream &output, const C1 &o)
{
    output << "Valor " << *o.getD() << "\n";
    return output;
}
