#include "Elipse.h"

Elipse::Elipse(): Forma{}, radio_mayor{}, radio_menor{}
{

}

Elipse::Elipse(std::string color, double x, double y, std::string nombre, double radio_mayor, double radio_menor)
                        : Forma(color, x, y, nombre)
{
    this->radio_mayor = radio_mayor;
    this->radio_menor = radio_menor;
}

Elipse::Elipse(const Elipse &o): Forma(o)
{
    this->radio_mayor = o.radio_mayor;
    this->radio_menor = o.radio_menor;
}

void Elipse::setRadio_mayor(const double radio_mayor)
{
    this->radio_mayor = radio_mayor;
}

double Elipse::getRadio_mayor() const
{
    return (this->radio_mayor);
}

void Elipse::setRadio_menor(const double radio_menor)
{
    this->radio_menor = radio_menor;
}

double Elipse::getRadio_menor() const
{
    return (this->radio_menor);
}

double Elipse::getPi() const
{
    return (this->pi);
}

double Elipse::getArea() const
{
    return (this->getPi() * (this->getRadio_mayor() * this->getRadio_menor()));
}

double Elipse::getPerimetroAprox1() const
{
    return(this->getPi() * (3 * (this->getRadio_mayor() + this->getRadio_menor())
                            - sqrt((3 * this->getRadio_mayor() + this->getRadio_menor()) *
                                   (this->getRadio_mayor() + (3 * this->getRadio_menor())))));
}

double Elipse::getPerimetroAprox2() const
{
    return(this->getPi() * (this->getRadio_mayor() + this->getRadio_menor()) *
           (1 + ((3 * (pow(this->getRadio_mayor() - this->getRadio_menor(), 2) /
                       pow(this->getRadio_mayor() + this->getRadio_menor(), 2)))
                 / (10 + (sqrt(4 - (3 * (pow(this->getRadio_mayor() - this->getRadio_menor(), 2)
                                         / pow(this->getRadio_mayor() + this->getRadio_menor(), 2)))))))));
}

void Elipse::setTamEscala(const double factor)
{
    this->setRadio_mayor(this->getRadio_mayor() * factor);
    this->setRadio_menor(this->getRadio_menor() * factor);
}

void Elipse::imprimir() const
{
    std::cout << "\nElipse.\n";
    Forma::imprimir();
    std::cout << "Radio Mayor: " << getRadio_mayor() << std::endl;
    std::cout << "Radio Menor: " << getRadio_menor() << std::endl;
    std::cout << "Perimetro(Aproximacion 1): " << getPerimetroAprox1() << std::endl;
    std::cout << "Perimetro(Aproximacion 2): " << getPerimetroAprox2() << std::endl;
    std::cout << "Area: " << getArea() << std::endl;
}

Elipse::~Elipse()
{

}

std::ostream& operator<< (std::ostream &output, const Elipse &o)
{
    output << "\nElipse.\n"
    << "Color: " << o.getColor() << std::endl
    << "Centro: " << "( " << o.getCentroX() << " , " << o.getCentroY() << " )\n"
    << "Nombre: " << o.getNombre() << std::endl
    << "Radio Mayor: " << o.getRadio_mayor() << std::endl
    << "Radio Menor: " << o.getRadio_menor() << std::endl
    << "Perimetro(Aproximacion 1): " << o.getPerimetroAprox1() << std::endl
    << "Perimetro(Aproximacion 2): " << o.getPerimetroAprox2() << std::endl
    << "Area: " << o.getArea() << std::endl;
    return output;
}
