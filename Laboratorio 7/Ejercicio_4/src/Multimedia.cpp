#include "Multimedia.h"

Multimedia::Multimedia() = default;

Multimedia::Multimedia(std::string tipom, std::string categoria)
{
    this->tipom = tipom;
    this->categoria = categoria;
}

Multimedia::Multimedia(const Multimedia &o)
{
    this->tipom = o.tipom;
    this->categoria = o.categoria;
}

void Multimedia::setTipom(const std::string tipom)
{
    this->tipom = tipom;
}

std::string Multimedia::getTipom() const
{
    return tipom;
}

void Multimedia::setCategoria(const std::string categoria)
{
    this->categoria = categoria;
}

std::string Multimedia::getCategoria() const
{
    return categoria;
}

Multimedia::~Multimedia()
{

}

std::ostream& operator<< (std::ostream &output, const Multimedia &o)
{
    output << "---------------------------------------------------------" << std::endl
    << "\tMultimedia." << std::endl
    << "Tipo: " << o.getTipom() << std::endl
    << "Categoria: " << o.getCategoria() << std::endl
    << "---------------------------------------------------------" << std::endl;
    return output;
}
