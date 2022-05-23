#include "Punto.h"

Punto::Punto() = default;

Punto::Punto(double x, double y)
{
    this->x = x;
    this->y = y;
}

Punto::Punto(const Punto &o)
{
    this->x = o.x;
    this->y = o.y;
}

void Punto::setX(const double x)
{
    this->x = x;
}

double Punto::getX() const
{
    return this->x;
}

void Punto::setY(const double y)
{
    this->y = y;
}

double Punto::getY() const
{
    return this->y;
}

void Punto::imprimir() const
{
    std::cout << "\n(" << getX() << " , " << getY() << ")\n";
}

Punto::~Punto()
{

}

std::ostream& operator<< (std::ostream &output, const Punto &o)
{
    output << "\n(" << o.getX() << " , " << o.getY() << ")\n";
    return output;
}
