#include "Cuadrado.h"

Cuadrado::Cuadrado(): Rectangulo{}
{

}

Cuadrado::Cuadrado(std::string color, double x, double y, std::string nombre, double lado_mayor, double lado_menor)
                        : Rectangulo(color, x, y, nombre, lado_mayor, lado_menor)
{

}

Cuadrado::Cuadrado(const Cuadrado &o): Rectangulo(o)
{

}

double Cuadrado::getLado() const
{
    if(this->getLado_mayor() == 0 && this->getLado_menor() > 0)
    {
        return(this->getLado_menor());
    }
    else
    {
        return(this->getLado_mayor());
    }
}

double Cuadrado::getArea() const
{
    return (this->getLado() * this->getLado());
}

double Cuadrado::getPerimetro() const
{
    return (this->getLado() * 4);
}

void Cuadrado::setTamEscala(const double factor)
{
    Rectangulo::setTamEscala(factor);
}

void Cuadrado::imprimir() const
{
    std::cout << "\nCuadrado.\n";
    Forma::imprimir();
    std::cout << "Lado: " << getLado() << std::endl;
    std::cout << "Perimetro: " << getPerimetro() << std::endl;
    std::cout << "Area: " << getArea() << std::endl;
}

Cuadrado::~Cuadrado()
{

}

std::ostream& operator<< (std::ostream &output, const Cuadrado &o)
{
    output << "\nCuadrado.\n"
    << "Color: " << o.getColor() << std::endl
    << "Centro: " << "( " << o.getCentroX() << " , " << o.getCentroY() << " )\n"
    << "Nombre: " << o.getNombre() << std::endl
    << "Lado: " << o.getLado() << std::endl
    << "Perimetro: " << o.getPerimetro() << std::endl
    << "Area: " << o.getArea() << std::endl;
    return output;
}
