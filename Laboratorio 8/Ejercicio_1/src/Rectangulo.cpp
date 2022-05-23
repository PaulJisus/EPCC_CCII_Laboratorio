#include "Rectangulo.h"

Rectangulo::Rectangulo(): Forma{}, lado_mayor{}, lado_menor{}
{

}

Rectangulo::Rectangulo(std::string color, double x, double y, std::string nombre, double lado_mayor, double lado_menor)
                        : Forma(color, x, y, nombre)
{
    this->lado_mayor = lado_mayor;
    this->lado_menor = lado_menor;
}

Rectangulo::Rectangulo(const Rectangulo &o): Forma(o)
{
    this->lado_mayor = o.lado_mayor;
    this->lado_menor = o.lado_menor;
}

void Rectangulo::setLado_mayor(const double lado_mayor)
{
    this->lado_mayor = lado_mayor;
}

double Rectangulo::getLado_mayor() const
{
    return (this->lado_mayor);
}

void Rectangulo::setLado_menor(const double lado_menor)
{
    this->lado_menor = lado_menor;
}

double Rectangulo::getLado_menor() const
{
    return (this->lado_menor);
}

double Rectangulo::getArea() const
{
    return (this->getLado_mayor() * this->getLado_menor());
}

double Rectangulo::getPerimetro() const
{
    return ((this->getLado_mayor() * 2) + (this->getLado_menor() * 2));
}

void Rectangulo::setTamEscala(const double factor)
{
    this->setLado_mayor(this->getLado_mayor() * factor);
    this->setLado_menor(this->getLado_menor() * factor);
}

void Rectangulo::imprimir() const
{
    std::cout << "\nRectangulo.\n";
    Forma::imprimir();
    std::cout << "Lado Mayor: " << getLado_mayor() << std::endl;
    std::cout << "Lado Menor: " << getLado_menor() << std::endl;
    std::cout << "Perimetro: " << getPerimetro() << std::endl;
    std::cout << "Area: " << getArea() << std::endl;
}

Rectangulo::~Rectangulo()
{

}

std::ostream& operator<< (std::ostream &output, const Rectangulo &o)
{
    output << "\nRectangulo.\n"
    << "Color: " << o.getColor() << std::endl
    << "Centro: " << "( " << o.getCentroX() << " , " << o.getCentroY() << " )\n"
    << "Nombre: " << o.getNombre() << std::endl
    << "Lado Mayor: " << o.getLado_mayor() << std::endl
    << "Lado Menor: " << o.getLado_menor() << std::endl
    << "Perimetro: " << o.getPerimetro() << std::endl
    << "Area: " << o.getArea() << std::endl;
    return output;
}
