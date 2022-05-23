#include "Forma.h"

Forma::Forma() = default;

Forma::Forma(std::string color, double x, double y, std::string nombre)
{
    this->color = color;
    this->centro = Punto(x, y);
    this->nombre = nombre;
}

Forma::Forma(const Forma &o)
{
    this->color = o.color;
    this->centro = o.centro;
    this->nombre = o.nombre;
}

void Forma::setColor(const std::string color)
{
    this->color = color;
}

std::string Forma::getColor() const
{
    return (this->color);
}

void Forma::setCentroX(const double x)
{
    this->centro.setX(x);
}

double Forma::getCentroX() const
{
    return (this->centro.getX());
}

void Forma::setCentroY(const double y)
{
    this->centro.setY(y);
}

double Forma::getCentroY() const
{
    return (this->centro.getY());
}

void Forma::setNombre(const std::string nombre)
{
    this->nombre = nombre;
}

std::string Forma::getNombre() const
{
    return (this->nombre);
}

double Forma::getArea() const
{
    return 0;
}

void Forma::Mover(const double m_x, const double m_y)
{
    this->centro.setX(this->centro.getX() + m_x);
    this->centro.setY(this->centro.getY() + m_y);
}

void Forma::imprimir() const
{
    std::cout << "\nColor: " << getColor() << std::endl;
    std::cout << "Centro: " << "( " << getCentroX() << " , " << getCentroY() << " )\n";
    std::cout << "Nombre: " << getNombre() << std::endl;
}

Forma::~Forma()
{

}

std::ostream& operator<< (std::ostream &output, const Forma &o)
{
    output << "Color: " << o.getColor() << std::endl
    << "Centro: " << "( " << o.getCentroX() << " , " << o.getCentroY() << " )\n"
    << "Nombre: " << o.getNombre() << std::endl;
    return output;
}
