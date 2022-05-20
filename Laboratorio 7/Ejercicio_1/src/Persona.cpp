#include "Persona.h"

Persona::Persona() = default;

Persona::Persona(int edad, std::string nombres, std::string apellidos, std::string direccion,
                 std::string correo, int DNI, long long telefono)
{
    this->edad = edad;
    this->nombres = nombres;
    this->apellidos = apellidos;
    this->direccion = direccion;
    this->correo = correo;
    this->DNI = DNI;
    this->telefono = telefono;
}

Persona::Persona(const Persona &o)
{
    this->edad = o.edad;
    this->nombres = o.nombres;
    this->apellidos = o.apellidos;
    this->direccion = o.direccion;
    this->correo = o.correo;
    this->DNI = o.DNI;
    this->telefono = o.telefono;
}

void Persona::setEdad(const int edad)
{
    this->edad = edad;
}

int Persona::getEdad() const
{
    return edad;
}

void Persona::setNombres(const std::string nombres)
{
    this->nombres = nombres;
}

std::string Persona::getNombres() const
{
    return nombres;
}

void Persona::setApellidos(const std::string apellidos)
{
    this->apellidos = apellidos;
}

std::string Persona::getApellidos() const
{
    return apellidos;
}

void Persona::setDireccion(const std::string direccion)
{
    this->direccion = direccion;
}

std::string Persona::getDireccion() const
{
    return direccion;
}

void Persona::setCorreo(const std::string correo)
{
    this->correo = correo;
}

std::string Persona::getCorreo() const
{
    return correo;
}

void Persona::setDNI(const int DNI)
{
    this->DNI = DNI;
}

int Persona::getDNI() const
{
    return DNI;
}

void Persona::setTelefono(const long long telefono)
{
    this->telefono = telefono;
}

long long Persona::getTelefono() const
{
    return telefono;
}

Persona::~Persona()
{

}

std::ostream& operator<< (std::ostream &output, const Persona &o)
{
    output << "\n---------------------------------------------------------" << std::endl
    << "\tNombres: " << o.getNombres() << std::endl
    << "\tApellidos: " << o.getApellidos() << std::endl
    << "\tD.N.I.: " << o.getDNI() << std::endl
    << "\tEdad: " << o.getEdad() << std::endl
    << "\tDireccion: " << o.getDireccion() << std::endl
    << "\tCorreo: " << o.getCorreo() << std::endl
    << "\tTelefono: " << o.getTelefono() << std::endl
    << "---------------------------------------------------------" << std::endl;
    return output;
}
