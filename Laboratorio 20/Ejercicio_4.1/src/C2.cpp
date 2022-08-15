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
    return this->d;
}

void C2::print() const
{
    std::cout << "Valor " << *d;
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
