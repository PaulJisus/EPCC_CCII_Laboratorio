#include "Material.h"

Material::Material() = default;

Material::Material(std::string tipo)
{
    this->tipo = tipo;
}

Material::Material(const Material &o)
{
    this->tipo = o.tipo;
}

void Material::setTipo(const std::string tipo)
{
    this->tipo = tipo;
}

std::string Material::getTipo() const
{
    return tipo;
}

Material::~Material()
{

}

std::ostream& operator<< (std::ostream &output, const Material &o)
{
    output << "---------------------------------------------------------" << std::endl
    << "\nMaterial:\t" << o.getTipo() << std::endl
    << "---------------------------------------------------------" << std::endl;
    return output;
}
