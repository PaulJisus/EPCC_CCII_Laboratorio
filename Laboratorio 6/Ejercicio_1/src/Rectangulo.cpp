#include <sstream>

#include "Rectangulo.h"

Rectangulo::Rectangulo(int b, int a): base(b), altura(a)
{

}

Rectangulo::~Rectangulo()
{

}

int Rectangulo::getBase() const
{
    return base;
}

void Rectangulo::setBase(int base)
{
    this->base = base;
}

int Rectangulo::getAltura() const
{
    return altura;
}

void Rectangulo::setAltura(int altura)
{
    this->altura = altura;
}

int Rectangulo::Perimetro() const
{
    return (getBase() + getAltura()) * 2;
}

int Rectangulo::Area() const
{
    return getBase() * getAltura();
}

std::ostream& operator << (std::ostream &output, const Rectangulo &r)
{
    output << "Perimetro: " << r.Perimetro() << " unidades\tArea: " << r.Area() << " unidades al cuadrado.\n";
    return output;
}
