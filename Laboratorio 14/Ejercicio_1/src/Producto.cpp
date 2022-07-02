#include "Producto.h"

Producto::Producto()
{
    this->codigo = " ";
    this->nombre = " ";
    this->precio = 0;
    this->stock = 0;
    this->disponibilidad = false;
}

Producto::Producto(std::string codigo, std::string nombre, double precio, int stock)
{
    this->codigo = codigo;
    this->nombre = nombre;
    this->precio = precio;
    this->stock = stock;
    if(stock > 0)
    {
        this->disponibilidad = true;
    }
    else
    {
        this->disponibilidad = false;
    }
}

Producto::Producto(const Producto &o)
{
    this->codigo = o.codigo;
    this->nombre = o.nombre;
    this->precio = o.precio;
    this->stock = o.stock;
    if(o.stock > 0)
    {
        this->disponibilidad = true;
    }
    else
    {
        this->disponibilidad = false;
    }
}

void Producto::setCodigo(const std::string codigo)
{
    this->codigo = codigo;
}

std::string Producto::getCodigo() const
{
    return (this->codigo);
}

void Producto::setNombre(const std::string nombre)
{
    this->nombre = nombre;
}

std::string Producto::getNombre() const
{
    return (this->nombre);
}

void Producto::setPrecio(const double precio)
{
    this->precio = precio;
}

double Producto::getPrecio() const
{
    return (this->precio);
}

void Producto::setStock(const int stock)
{
    this->stock = stock;
    if(stock > 0)
    {
        setDisponibilidad(true);
    }
    else
    {
        setDisponibilidad(false);
    }
}

int Producto::getStock() const
{
    return (this->stock);
}

void Producto::setDisponibilidad(const bool disponibilidad)
{
    this->disponibilidad = disponibilidad;
}

bool Producto::getDisponibilidad() const
{
    return (this->disponibilidad);
}

Producto::~Producto()
{

}

std::ostream& operator<<(std::ostream &output, const Producto &o)
{
    output << "===================================\n"
    << "\nCodigo:\t\t" << o.getCodigo()
    << "\nNombre:\t\t" << o.getNombre()
    << "\nPrecio:\t\t" << o.getPrecio()
    << "\nStock:\t\t" << o.getStock();
    if(o.getDisponibilidad())
    {
        output << "\nDisponible:\tSi\n";
    }
    else
    {
        output << "\nDisponible:\tNo\n";
    }
    output << "\n===================================\n";
    return output;
}
