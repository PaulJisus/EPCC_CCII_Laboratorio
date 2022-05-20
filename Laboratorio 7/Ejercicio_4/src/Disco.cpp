#include "Disco.h"

Disco::Disco(): Multimedia{}, titulo{}, tipod{}, formato{}, anio{}, autor{}, copyright{}, volumen{}
{

}

Disco::Disco(std::string tipom, std::string categoria, std::string titulo, std::string tipod, std::string formato,
             int anio, std::string autor, std::string copyright, int volumen): Multimedia(tipom, categoria)
{
    this->titulo = titulo;
    this->tipod = tipod;
    this->formato = formato;
    this->anio = anio;
    this->autor = autor;
    this->copyright = copyright;
    this->volumen = volumen;
}

Disco::Disco(const Disco &o): Multimedia(o)
{
    this->titulo = o.titulo;
    this->tipod = o.tipod;
    this->formato = o.formato;
    this->anio = o.anio;
    this->autor = o.autor;
    this->copyright = o.copyright;
    this->volumen = o.volumen;
}

void Disco::setTitulo(const std::string titulo)
{
    this->titulo = titulo;
}

std::string Disco::getTitulo() const
{
    return titulo;
}

void Disco::setTipod(const std::string tipod)
{
    this->tipod = tipod;
}

std::string Disco::getTipod() const
{
    return tipod;
}

void Disco::setFormato(const std::string formato)
{
    this->formato = formato;
}

std::string Disco::getFormato() const
{
    return formato;
}

void Disco::setAnio(const int anio)
{
    this->anio = anio;
}

int Disco::getAnio() const
{
    return anio;
}

void Disco::setAutor(const std::string autor)
{
    this->autor = autor;
}

std::string Disco::getAutor() const
{
    return autor;
}

void Disco::setCopyright(const std::string copyright)
{
    this->copyright = copyright;
}

std::string Disco::getCopyright() const
{
    return copyright;
}

void Disco::setVolumen(const int volumen)
{
    this->volumen = volumen;
}

int Disco::getVolumen() const
{
    return volumen;
}

Disco::~Disco()
{

}

std::ostream& operator<< (std::ostream &output, const Disco &o)
{
    output << "---------------------------------------------------------" << std::endl
    << "\tInformacion general del disco." << std::endl
    << "Titulo: " << o.getTitulo() << std::endl
    << "Tipo: " << o.getTipod() << std::endl
    << "Formato: " << o.getFormato() << std::endl
    << "Autor: " << o.getAutor() << std::endl
    << 'A' << char(164) << "o: " << o.getAnio() << std::endl
    << "Derechos de Autor: " << o.getCopyright() << std::endl
    << "volumen: " << o.getVolumen() << std::endl
    << "Informacion multimedia del disco." << std::endl
    << "Tipo: " << o.getTipom() << std::endl
    << "Categoria: " << o.getCategoria() << std::endl
    << "---------------------------------------------------------" << std::endl;
    return output;
}
