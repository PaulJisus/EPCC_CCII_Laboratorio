#include "Base.h"

Base::Base() = default;

Base::Base(double operador)
{
    this->operador = operador;
}

Base::Base(const Base &o)
{
    this->operador = o.operador;
}

void Base::setOperador(const double operador)
{
    this->operador = operador;
}

double Base::getOperador() const
{
    return operador;
}

Base::~Base()
{

}

std::ostream& operator<< (std::ostream &output, const Base &o)
{
    output << "---------------------------------------------------------" << std::endl
    << o.getOperador() << std::endl
    << "---------------------------------------------------------" << std::endl;
    return output;
}
