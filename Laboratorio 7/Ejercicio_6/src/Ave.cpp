#include "Ave.h"

Ave::Ave() = default;

Ave::Ave(std::string orden, std::string familia, std::string subfamilia, std::string genero, std::string especie,
         std::string subespecie, std::string nombre, std::string habitat, std::string sexo, double peso, double size)
{
    this->orden = orden;
    this->familia = familia;
    this->subfamilia = subfamilia;
    this->genero = genero;
    this->especie = especie;
    this->subespecie = subespecie;
    this->nombre = nombre;
    this->habitat = habitat;
    this->sexo = sexo;
    this->peso = peso;
    this->size = size;
}

Ave::Ave(const Ave &o)
{
    this->orden = o.orden;
    this->familia = o.familia;
    this->subfamilia = o.subfamilia;
    this->genero = o.genero;
    this->especie = o.especie;
    this->subespecie = o.subespecie;
    this->nombre = o.nombre;
    this->habitat = o.habitat;
    this->sexo = o.sexo;
    this->peso = o.peso;
    this->size = o.size;
}

void Ave::setOrden(const std::string orden)
{
    this->orden = orden;
}

std::string Ave::getOrden() const
{
    return orden;
}

void Ave::setFamilia(const std::string familia)
{
    this->familia = familia;
}

std::string Ave::getFamilia() const
{
    return familia;
}

void Ave::setSubfamilia(const std::string subfamilia)
{
    this->subfamilia = subfamilia;
}

std::string Ave::getSubfamilia() const
{
    return subfamilia;
}

void Ave::setGenero(const std::string genero)
{
    this->genero = genero;
}

std::string Ave::getGenero() const
{
    return genero;
}

void Ave::setEspecie(const std::string especie)
{
    this->especie = especie;
}

std::string Ave::getEspecie() const
{
    return especie;
}

void Ave::setSubespecie(const std::string subespecie)
{
    this->subespecie = subespecie;
}

std::string Ave::getSubespecie() const
{
    return subespecie;
}

void Ave::setNombre(const std::string nombre)
{
    this->nombre = nombre;
}

std::string Ave::getNombre() const
{
    return nombre;
}

void Ave::setHabitat(const std::string habitat)
{
    this->habitat = habitat;
}

std::string Ave::getHabitat() const
{
    return habitat;
}

void Ave::setSexo(const std::string sexo)
{
    this->sexo = sexo;
}

std::string Ave::getSexo() const
{
    return sexo;
}

void Ave::setPeso(const double peso)
{
    this->peso = peso;
}

double Ave::getPeso() const
{
    return peso;
}

void Ave::setSize(const double size)
{
    this->size = size;
}

double Ave::getSize() const
{
    return size;
}

Ave::~Ave()
{

}

std::ostream& operator<< (std::ostream &output, const Ave &o)
{
    output << "\n---------------------------------------------------------" << std::endl
    << "Orden:\t\t" << o.getOrden() << std::endl
    << "Familia:\t" << o.getFamilia() << std::endl
    << "Subfamilia:\t" << o.getSubfamilia() << std::endl
    << "Genero:\t\t" << o.getGenero() << std::endl
    << "Especie:\t" << o.getEspecie() << std::endl
    << "Subespecie:\t" << o.getSubespecie() << std::endl
    << "Nombre Comun:\t" << o.getNombre() << std::endl
    << "Habitat:\t" << o.getHabitat() << std::endl
    << "Sexo:\t\t" << o.getSexo() << std::endl
    << "Peso(gr):\t" << o.getPeso() << std::endl
    << "Tama" << char(164) << "o(cm):\t" << o.getSize() << std::endl
    << "---------------------------------------------------------" << std::endl;
    return output;
}
