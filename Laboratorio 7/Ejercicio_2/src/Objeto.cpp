#include "Objeto.h"

Objeto::Objeto(): Material{}, Color{}, nombre{}
{

}

Objeto::Objeto(int red, int green, int blue, std::string tipo, std::string nombre)
                : Material(tipo), Color(red, green, blue)
{
    this->nombre = nombre;
}

Objeto::Objeto(const Objeto &o): Material(o), Color(o)
{
    this->nombre = o.nombre;
}

void Objeto::setNombre(const std::string nombre)
{
    this->nombre = nombre;
}

std::string Objeto::getNombre() const
{
    return nombre;
}

Objeto::~Objeto()
{

}

std::ostream& operator<< (std::ostream &output, const Objeto &o)
{
    output << "---------------------------------------------------------" << std::endl
    << "Nombre del Objeto:\t" << o.getNombre() << std::endl
    << "Color del Objeto en RGB:" << std::endl
    << "\tRed:\t" << o.getRed() << std::endl
    << "\tGreen:\t" << o.getGreen() << std::endl
    << "\tBlue:\t" << o.getBlue() << std::endl
    << "Material del Objeto:\t" << o.getTipo() << std::endl
    << "\n---------------------------------------------------------" << std::endl;
    return output;
}
