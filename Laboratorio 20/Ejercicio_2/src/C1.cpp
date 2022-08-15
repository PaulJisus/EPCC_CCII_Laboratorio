#include "C1.h"

C1::C1() = default;

C1::C1(std::shared_ptr<double> value)
{
    this->d = value;
}

void C1::print() const
{
    std::cout << "Valor " << *d;
}

C1::~C1()
{
    std::cout << "\nC1 destructor\n";
}
