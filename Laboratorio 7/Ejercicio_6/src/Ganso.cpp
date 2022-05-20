#include "Ganso.h"

Ganso::Ganso(): Ave{}
{

}

Ganso::Ganso(std::string orden, std::string familia, std::string subfamilia, std::string genero, std::string especie,
         std::string subespecie, std::string nombre, std::string habitat, std::string sexo, double peso, double size)
         : Ave(orden, familia, subfamilia, genero, especie, subespecie, nombre, habitat, sexo, peso, size)
{

}

Ganso::Ganso(const Ganso &o): Ave(o)
{

}

Ganso::~Ganso()
{

}

std::ostream& operator<< (std::ostream &output, const Ganso &o)
{
    output << "\n---------------------------------------------------------" << std::endl
    << "Clase Ganso." << std::endl
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
