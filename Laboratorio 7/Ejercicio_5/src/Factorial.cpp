#include "Factorial.h"

Factorial::Factorial(): Base{}
{

}

Factorial::Factorial(double operador): Base(operador)
{

}

Factorial::Factorial(const Factorial &o): Base(o)
{

}

long long Factorial::devolverFactorial() const
{
    long long factorial{1};
    if(getOperador() == 0)
    {
        return 1;
    }
    else
    {
        for(int i = 1; i <= getOperador(); i++)
        {
            factorial *= i;
        }
        return factorial;
    }
}

Factorial::~Factorial()
{

}

Base operator+ (const Factorial &o, const Factorial &p)
{
    Factorial aux(o.devolverFactorial() + p.devolverFactorial());
    return aux;
}

Base operator- (const Factorial &o, const Factorial &p)
{
    Factorial aux(o.devolverFactorial() - p.devolverFactorial());
    return aux;
}

Base operator* (const Factorial &o, const Factorial &p)
{
    Factorial aux(o.devolverFactorial() * p.devolverFactorial());
    return aux;
}

Base operator/ (const Factorial &o, const Factorial &p)
{
    Factorial aux(o.devolverFactorial() / p.devolverFactorial());
    return aux;
}

std::ostream& operator<< (std::ostream &output, const Factorial &o)
{
    output << "---------------------------------------------------------" << std::endl
    << "El Factorial de: " << o.getOperador() << std::endl
    << o.devolverFactorial() << std::endl
    << "---------------------------------------------------------" << std::endl;
    return output;
}
