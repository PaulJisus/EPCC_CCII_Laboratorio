#include "Circulo.h"

Circulo::Circulo(): Elipse{}
{

}

Circulo::Circulo(std::string color, double x, double y, std::string nombre, double radio_mayor, double radio_menor)
                        : Elipse(color, x, y, nombre, radio_mayor, radio_menor)
{

}

Circulo::Circulo(const Circulo &o): Elipse(o)
{

}

double Circulo::getRadio() const
{
    if(this->getRadio_mayor() == 0 && this->getRadio_menor() > 0)
    {
        return(this->getRadio_menor());
    }
    else
    {
        return(this->getRadio_mayor());
    }
}

double Circulo::getDiametro() const
{
    return(2 * this->getRadio());
}

double Circulo::getArea() const
{
    return(this->getPi() * (this->getRadio() * this->getRadio()));
}

double Circulo::getPerimetro() const
{
    return(this->getPi() * this->getDiametro());
}

void Circulo::setTamEscala(const double factor)
{
    Elipse::setTamEscala(factor);
}

void Circulo::imprimir() const
{
    std::cout << "\nCirculo.\n";
    Forma::imprimir();
    std::cout << "Radio: " << getRadio() << std::endl;
    std::cout << "Diametro: " << getDiametro() << std::endl;
    std::cout << "Perimetro: " << getPerimetro() << std::endl;
    std::cout << "Area: " << getArea() << std::endl;
}

Circulo::~Circulo()
{

}

std::ostream& operator<< (std::ostream &output, const Circulo &o)
{
    output << "\nCirculo.\n"
    << "Color: " << o.getColor() << std::endl
    << "Centro: " << "( " << o.getCentroX() << " , " << o.getCentroY() << " )\n"
    << "Nombre: " << o.getNombre() << std::endl
    << "Radio: " << o.getRadio() << std::endl
    << "Diametro: " << o.getDiametro() << std::endl
    << "Perimetro: " << o.getPerimetro() << std::endl
    << "Area: " << o.getArea() << std::endl;
    return output;
}
